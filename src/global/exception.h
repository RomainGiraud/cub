#ifndef CUB_EXCEPTION_H
#define CUB_EXCEPTION_H

#include <string>
#include <iostream>
#include <exception>

namespace cub
{

class Exception : public std::exception
{
public:
    Exception(std::string msg)
        : _message(msg.c_str())
    {
    }

    Exception(std::string className, std::string methodName, std::string msg)
        : _message(("{" + className + "::" + methodName + "} " + msg).c_str())
    {
    }

    virtual ~Exception() throw() {}

private:
    std::string _message;
    
    friend std::ostream& operator<<(std::ostream& os, const Exception &e);
};

inline
std::ostream& operator<<(std::ostream& os, const Exception &e)
{
    return os << e._message;
}

}

#endif /*CUB_EXCEPTION_H*/