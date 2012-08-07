find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(perfect_harmony main.cpp)
target_link_libraries(perfect_harmony ${Boost_LIBRARIES})
