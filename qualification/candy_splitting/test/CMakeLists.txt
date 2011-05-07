include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(candy_splitting_test candy_splitting_test.cpp)
target_link_libraries(candy_splitting_test ${Boost_LIBRARIES})
add_test(candy_splitting candy_splitting_test)
