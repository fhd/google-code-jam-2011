find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(bot_trust main.cpp)
target_link_libraries(bot_trust ${Boost_LIBRARIES})
