find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(bot_trust main.cpp)
target_link_libraries(bot_trust ${Boost_LIBRARIES})
