find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(freecell_statistics main.cpp)
target_link_libraries(freecell_statistics ${Boost_LIBRARIES})
