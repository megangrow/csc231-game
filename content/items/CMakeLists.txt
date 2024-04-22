add_library(items
        bite.cpp
        staff_red.cpp
        sword.cpp
        axe.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
