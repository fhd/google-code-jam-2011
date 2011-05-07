find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(magicka main.cpp)
target_link_libraries(magicka ${Boost_LIBRARIES})
