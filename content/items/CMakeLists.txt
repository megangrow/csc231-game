add_library(items
        bite.cpp
        staff_red.cpp
        sword.cpp
        axe.cpp
        potion_red.cpp
        staff_green.cpp
        staff_green.h
        coin.cpp
        coin.h
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
