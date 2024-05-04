#pragma once

#include "animatedsprite.h"
#include "vec.h"
#include "sprite.h"
#include <memory>
#include <vector>

// forward declarations
class Engine;
class Action;
class Item;

constexpr int default_speed{8}, max_inventory{5};
enum class Team { Hero, Monster };

// base class for all interacting beings
class Entity {
public:
    Entity(Engine& engine, Vec position, Team team);

    // movement
    [[nodiscard]] Vec get_position() const;
    void move_to(Vec position);
    [[nodiscard]] Vec get_direction() const;
    void change_direction(Vec new_direction);
    void remove_item(Item* item);
    [[nodiscard]] bool is_visible() const;

    // functions to be called after move_to is called
    std::vector<std::function<void(Engine& engine, Entity& entity)>> on_move;

    // combat
    void take_damage(int amount);
    void set_max_health(int value);
    [[nodiscard]] std::pair<int, int> get_health() const; // returns health, max_health
    [[nodiscard]] bool is_alive() const;
    void set_team(Team new_team);
    [[nodiscard]] Team get_team() const;

    // managing items within the inventory
    [[nodiscard]] bool is_inventory_full() const;
    void add_to_inventory(std::shared_ptr<Item> item);
    [[nodiscard]] std::shared_ptr<Item> get_current_item() const;
    void select_item(int index);
    std::shared_ptr<Item> remove_item(int index);
    // returns selected item number and names of all items in inventory
    [[nodiscard]] std::pair<int, std::vector<std::string>> get_inventory_list() const;

    // taking turns
    std::unique_ptr<Action> take_turn();
    std::function<std::unique_ptr<Action>(Engine& engine, Entity& entity)> behavior;

    // drawing
    void set_sprite(const std::string& name);
    void update();
    [[nodiscard]] std::vector<Sprite> get_sprites() const;

private:
    Engine& engine;
    AnimatedSprite sprite;
    Vec position, direction{1, 0};

    // health gets reduced by calling take damage
    int health{1}, max_health{1};
    bool alive{true};
    
    // teams can be used to determine who can attack whom
    Team team;

    // speed is energy gain per turn, once an entity has enough energy
    // it can take a turn
    int speed{default_speed}, energy{0};

    // inventory stores up to max_inventory items
    std::vector<std::shared_ptr<Item>> inventory;
    int current_item; // item that entity is currently holding and using
    // visually orient the item based on entity's direction
    void adjust_item_position();

    friend class Entities;
};

