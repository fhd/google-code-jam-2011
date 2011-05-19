include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(goro_sort_test goro_sort_test.cpp)
target_link_libraries(goro_sort_test ${Boost_LIBRARIES})
add_test(goro_sort goro_sort_test)
