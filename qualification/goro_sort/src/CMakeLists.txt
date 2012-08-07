find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(goro_sort main.cpp)
target_link_libraries(goro_sort ${Boost_LIBRARIES})
