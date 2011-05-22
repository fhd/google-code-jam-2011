find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(square_tiles main.cpp)
target_link_libraries(square_tiles ${Boost_LIBRARIES})
