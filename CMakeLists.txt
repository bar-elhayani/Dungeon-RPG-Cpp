cmake_minimum_required(VERSION 3.28)
project(HW5)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW5 main.cpp
                    Entity.h
                    Entity.cpp
                    Room.h
                    Room.cpp
                    Game.h
                    Game.cpp
                    Fighter.cpp
                    Fighter.h
                    Sorcerer.cpp
                    Sorcerer.h
                    Dragon.cpp
                    Dragon.h
                    Goblin.cpp
                    Goblin.h
                    Player.cpp
                    Player.h
                    Monster.cpp
                    Monster.h
                    Exceptions.cpp
                    Exceptions.h
)
