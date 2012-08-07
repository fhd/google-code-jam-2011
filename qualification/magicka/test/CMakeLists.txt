include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(magicka_test magicka_test.cpp)
target_link_libraries(magicka_test ${Boost_LIBRARIES})
add_test(magicka magicka_test)
