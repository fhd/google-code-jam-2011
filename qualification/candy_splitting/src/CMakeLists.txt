find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(candy_splitting main.cpp)
target_link_libraries(candy_splitting ${Boost_LIBRARIES})
