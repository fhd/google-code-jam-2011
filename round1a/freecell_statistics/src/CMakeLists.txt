find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(freecell_statistics main.cpp)
target_link_libraries(freecell_statistics ${Boost_LIBRARIES})
