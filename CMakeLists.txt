cmake_minimum_required(VERSION 3.28)
project(Progetto_Laboratorio)

set(CMAKE_CXX_STANDARD 11)

add_executable(Progetto_Laboratorio  main.cpp
        Window.cpp
        GameCharacter.cpp
        GameCharacter.h
        Weapon.cpp
        Weapon.h
        GameEngine.cpp
        GameEngine.h
        Player.cpp
        Player.h
        Sound.cpp
        Sound.h
        Menu.cpp
        Menu.h
)

include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(/SFML/include/SFML)
include_directories(/SFML/lib)
include_directories(Sprite)
target_link_libraries(Progetto_Laboratorio sfml-system sfml-window sfml-graphics sfml-audio sfml-network)