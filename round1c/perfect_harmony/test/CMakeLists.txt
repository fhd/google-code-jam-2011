include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(perfect_harmony_test perfect_harmony_test.cpp)
target_link_libraries(perfect_harmony_test ${Boost_LIBRARIES})
add_test(perfect_harmony perfect_harmony_test)
