cmake_minimum_required(VERSION 3.21)
project(Eksamen_Mario)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(Eksamen_Mario main.cpp object.cpp global.hpp entities.cpp goomba.cpp bricks.cpp castle.cpp pole.cpp coin.cpp)
target_link_libraries(Eksamen_Mario PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio sfml-system)

