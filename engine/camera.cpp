#include "camera.h"

#include <algorithm>

#include "dungeon.h"
#include "entities.h"
#include "entity.h"
#include "graphics.h"

Camera::Camera(Graphics& graphics, int tile_size, int zoom)
    :graphics{graphics}, tile_size{tile_size}, zoom{zoom}, location{0, 0},
     screen_center{graphics.screen_width /2, graphics.screen_height /2} {
    calculate_visibility_limits();
}

void Camera::render(const Vec& position, const Sprite& sprite) const {
    Vec pixel = world_to_screen(position);
    graphics.draw_sprite(pixel, sprite, zoom);
}
    
void Camera::render(const Dungeon& dungeon) const {
    // screen -> world
    // calculate min, max values for x, y, then only draw those
    int x_min = std::max(0, min.x);
    int y_min = std::max(0, min.y);
    int x_max = std::min(max.x, dungeon.tiles.width-1);
    int y_max = std::min(max.y, dungeon.tiles.height-1);

    // remember any doors that are in view, then draw them later on top of base tiles
    std::vector<std::pair<Vec, Sprite>> door_sprites;
    
    // draw tile base sprite
    for (int y = y_min; y <= y_max; ++y) {
        for (int x = x_min; x <= x_max; ++x) {
            Vec position{x, y};
            if (within_view(position)) {
                const Tile& tile = dungeon.tiles(position);
                render(position, tile.sprite);
                if (tile.has_door()) {
                    door_sprites.emplace_back(position, tile.door->get_sprite());
                }
            }
        }
    }

    // draw decorations
    for (const auto& [position, doodad] : dungeon.decorations) {
        if (within_view(position)) {
            render(position, doodad.get_sprite());
        }
    }

    // draw doors
    for (const auto& [position, sprite] : door_sprites) {
        render(position, sprite);
    }
}

void Camera::render(const Entities& entities) const {
    for (const std::shared_ptr<Entity>& entity : entities) {
        if (within_view(entity->get_position()) && entity->is_alive() && entity->is_visible()) {
            for (Sprite sprite : entity->get_sprites()) {
                render(entity->get_position(), sprite);
            }
        }
    }
}


void Camera::render_fog(const Dungeon& dungeon) const {
    int x_min = std::max(0, min.x);
    int y_min = std::max(0, min.y);
    int x_max = std::min(max.x, dungeon.tiles.width-1);
    int y_max = std::min(max.y, dungeon.tiles.height-1);
        
    for (int y = y_min; y <= y_max; ++y) {
        for (int x = x_min; x <= x_max; ++x) {
            Vec position{x, y};
            double brightness = dungeon.fog.brightness(position);
            int alpha = std::clamp(static_cast<int>(brightness*255), 0, 255);
            render_rect(position, 0, 0, 0, alpha);
        }
    }
}

void Camera::render_rect(const Vec& position, int red, int green, int blue, int alpha) const {
    int scale = tile_size * zoom;
    Vec pixel = world_to_screen(position);
    // sprites are anchored at the bottom center, whereas
    // rectangle are anchored at the upper-left: shift pixel x and
    // y values
    pixel.x -= scale / 2;
    pixel.y -= scale;
    Vec size{scale, scale};
    graphics.draw_rect(pixel, size, red, green, blue, alpha);
}

void Camera::render_health_bar(int current_health, int max_health) {
    double percentage = current_health / static_cast<double>(max_health);
    int length = static_cast<int>(percentage*300);
    graphics.draw_rect({10, 10}, {320, 40}, 255, 255, 255, 255);
    graphics.draw_rect({15, 15}, {310, 30}, 0, 0, 0, 255);
    graphics.draw_rect({20, 20}, {length, 20}, 50, 255, 50, 255);
}

void Camera::render_items(int selected_item, const std::vector<std::string>& sprite_names) {
    constexpr Vec size{54, 54}, gap{5, 5};
    for (std::size_t i = 0; i < sprite_names.size(); ++i) {
        int x = graphics.screen_width - (size.x + gap.x) * (max_inventory - i) - gap.x;
        int y = 10;
        Vec corner{x, y};
        // draw border, then background, then item sprite
        if (i == selected_item) {
            // red border indicates that item is currently selected
            graphics.draw_rect(corner, size, 255, 0, 0, 255);
        }
        else {
            // white border for all other items
            graphics.draw_rect(corner, size, 255, 255, 255, 255);
        }
        // a black background improves sprite visibility
        graphics.draw_rect(corner+gap, size-2*gap, 150, 150, 150, 255);

        if (!sprite_names.at(i).empty()) {
            Sprite sprite = graphics.get_sprite(sprite_names.at(i));
            Vec position = {corner.x + size.x/2, corner.y + size.y - 2*gap.y + 2};
            graphics.draw_sprite(position, sprite);
        }
    }
}

void Camera::add_overlay(const Vec& position, const Sprite& sprite) {
    overlays.emplace_back(position, sprite);
}

void Camera::render_overlays() {
    for (auto [position, sprite] : overlays) {
        render(position, sprite);
    }
}

void Camera::update() {
    overlays.clear();
}


Vec Camera::world_to_screen(const Vec& position) const {
    // World Coords (cartesian, up is positive y) -> Pixel Coords (image, down is positive y):
    // 1. Shift dungeon position by making the camera's location be the origin
    // 2. Multiple this position by zoom and tile_size to convert to pixels
    // 3. Shift the pixel location to the center of the screen
    Vec pixel = zoom * tile_size * (position - location) + screen_center;

    // 4. flip y-axis
    pixel.y = graphics.screen_height - pixel.y;

    // 5. shift up by half a tile to center it
    pixel.y += zoom * tile_size / 2;
    return pixel;
}

void Camera::move_to(const Vec& position) {
    location = position;
    calculate_visibility_limits();
}
    
void Camera::zoom_in() {
    if (zoom < 8) {
        ++zoom;
        calculate_visibility_limits();
    }
}
    
void Camera::zoom_out() {
    if (zoom > 1) {
        --zoom;
        calculate_visibility_limits();
    }
}

void Camera::calculate_visibility_limits() {
    Vec num_tiles = Vec{graphics.screen_width, graphics.screen_height} / (2 * zoom * tile_size) + Vec{1, 1};
    max = location + num_tiles;
    min = location - num_tiles;
}
    
bool Camera::within_view(const Vec& position) const {
    return min.x <= position.x && position.x <= max.x
        && min.y <= position.y && position.y <= max.y;
}

