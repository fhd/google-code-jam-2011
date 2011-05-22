find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(perfect_harmony main.cpp)
target_link_libraries(perfect_harmony ${Boost_LIBRARIES})
