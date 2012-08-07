find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(rpi main.cpp)
target_link_libraries(rpi ${Boost_LIBRARIES})
