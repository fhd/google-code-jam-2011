include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(bot_trust_test bot_trust_test.cpp)
target_link_libraries(bot_trust_test ${Boost_LIBRARIES})
add_test(bot_trust bot_trust_test)
