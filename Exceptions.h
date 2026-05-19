#pragma once
#include <exception>

/**
 * @brief Exception for memory allocation issues.
 */
class MemoryProblemException : public std::exception {
public:
    /**
     * @return Error message for memory problems.
     */
    virtual const char* what() const throw() {
        return "Memory Problem";
    }
};


/**
 * @brief Exception for invalid room-related issues.
 */
class InvalidRoomException : public std::exception {
public:
    /**
     * @return Error message for invalid room.
     */
    virtual const char* what() const throw() {
        return "Invalid Room";
    }
};

/**
 * @brief Exception for invalid input values.
 */
class InvalidValueException : public std::exception {
public:
    /**
     * @return Error message for invalid input value.
     */
    virtual const char* what() const throw() {
        return "Invalid Value";
    }
};
