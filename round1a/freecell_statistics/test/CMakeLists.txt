include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(freecell_statistics_test freecell_statistics_test.cpp)
target_link_libraries(freecell_statistics_test ${Boost_LIBRARIES})
add_test(freecell_statistics freecell_statistics_test)
