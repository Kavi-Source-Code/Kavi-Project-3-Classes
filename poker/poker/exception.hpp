#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

/**
 * @file exception.hpp
 * @brief This class is mainly used to throw exceptions with custom messages.
 * @note Do not alter this file.
 */
class Exception{
private:
    string message;
public:
    Exception(string message){
        this->message = message;
    }

    string print_message() const{
        return "Exception encountered : " + this->message;
    }
};

#endif