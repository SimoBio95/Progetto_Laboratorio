cmake_minimum_required(VERSION 3.28)
project(Progetto_Laboratorio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Aggiungi l'eseguibile principale del progetto
add_executable(Progetto_Laboratorio
        cppFiles/main.cpp
        cppFiles/Window.cpp
        cppFiles/GameCharacter.cpp
        cppFiles/Weapon.cpp
        cppFiles/GameEngine.cpp
        cppFiles/Player.cpp
        cppFiles/Sound.cpp
        cppFiles/Menu.cpp
        cppFiles/MachineGun.cpp
        cppFiles/Bullet.cpp
        cppFiles/Enemy.cpp
        hFiles/Window.h
        hFiles/GameCharacter.h
        hFiles/Weapon.h
        hFiles/GameEngine.h
        hFiles/Player.h
        hFiles/Sound.h
        hFiles/Menu.h
        hFiles/MachineGun.h
        hFiles/Bullet.h
        hFiles/Enemy.h
)

# Trova e linka le librerie SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(Progetto_Laboratorio PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Aggiungi include directories
include_directories(${CMAKE_SOURCE_DIR}/Sprite)
include_directories(${CMAKE_SOURCE_DIR}/test)

# Aggiungi l'eseguibile per i test
add_executable(RunTests
        test/runAllTests.cpp
        test/collisionTest.cpp
        cppFiles/Window.cpp
        cppFiles/GameCharacter.cpp
        cppFiles/Weapon.cpp
        cppFiles/GameEngine.cpp
        cppFiles/Player.cpp
        cppFiles/Sound.cpp
        cppFiles/Menu.cpp
        cppFiles/MachineGun.cpp
        cppFiles/Bullet.cpp
        cppFiles/Enemy.cpp
        hFiles/Window.h
        hFiles/GameCharacter.h
        hFiles/Weapon.h
        hFiles/GameEngine.h
        hFiles/Player.h
        hFiles/Sound.h
        hFiles/Menu.h
        hFiles/MachineGun.h
        hFiles/Bullet.h
        hFiles/Enemy.h
)

# Linka Google Test e le librerie SFML ai test
target_link_libraries(RunTests PRIVATE gtest gtest_main)
target_link_libraries(RunTests PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Aggiungi le directory include per i test
target_include_directories(RunTests PRIVATE ${CMAKE_SOURCE_DIR}/hFiles)

# Abilita il testing
enable_testing()
add_test(NAME RunAllTests COMMAND RunTests)

