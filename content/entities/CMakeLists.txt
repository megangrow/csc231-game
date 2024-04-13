add_library(entities
        heroes.cpp
        monsters.cpp
)

target_include_directories(entities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entities PUBLIC engine actions items)
