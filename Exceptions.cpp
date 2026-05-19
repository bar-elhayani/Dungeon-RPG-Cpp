#include <iostream>
#include "Exceptions.h"

//exception of a memory problem
void allocateMemory() {
    throw MemoryProblemException();
}

//exception of a invalid room problem
void checkRoom() {
    throw InvalidRoomException();
}

//exception of a invalid value problem
void validateValue() {
    throw InvalidValueException();
}