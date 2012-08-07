find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(magicka main.cpp)
target_link_libraries(magicka ${Boost_LIBRARIES})
