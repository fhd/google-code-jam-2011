include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(square_tiles_test square_tiles_test.cpp)
target_link_libraries(square_tiles_test ${Boost_LIBRARIES})
add_test(square_tiles square_tiles_test)
