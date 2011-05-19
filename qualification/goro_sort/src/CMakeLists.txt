find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(goro_sort main.cpp)
target_link_libraries(goro_sort ${Boost_LIBRARIES})
