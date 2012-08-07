find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(square_tiles main.cpp)
target_link_libraries(square_tiles ${Boost_LIBRARIES})
