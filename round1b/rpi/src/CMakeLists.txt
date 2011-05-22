find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(rpi main.cpp)
target_link_libraries(rpi ${Boost_LIBRARIES})
