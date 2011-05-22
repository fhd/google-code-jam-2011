include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(rpi_test rpi_test.cpp)
target_link_libraries(rpi_test ${Boost_LIBRARIES})
add_test(rpi rpi_test)
