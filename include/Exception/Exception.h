#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>
#include <sstream>

class BaseException
{
    public:
        BaseException(const std::string& str = ""):
            msgString(str)
        {
            if (msgString == "")
                msgString = "Unspecified exception";
        }

        std::string what() const
        {
            return msgString;
        }

    // protected allows a derived class to access msgString.
    protected:
        std::string msgString;
};

// index out of range
class IndexRangeError: public BaseException
{
    public:
        IndexRangeError(const std::string& msg, int i, int size):
            BaseException()
        {
            std::ostringstream indexErr;

            indexErr << msg << "  index " << i << "  size = " << size << std::ends;
            // IndexRangeError can modify msgString, since it is in
            // the protected section of BaseException
            msgString = indexErr.str();
        }
};

// attempt to erase from an empty container
class UnderflowError: public BaseException
{
    public:
        UnderflowError(const std::string& msg = ""):
            BaseException(msg)
        {}
};

// attempt to insert into a full container
class OverflowError: public BaseException
{
    public:
        OverflowError(const std::string& msg = ""):
            BaseException(msg)
        {}
};

// error in expression evaluation
class ExpressionError: public BaseException
{
    public:
        ExpressionError(const std::string& msg = ""):
            BaseException(msg)
        {}
};

// bad object reference
class ReferenceError: public BaseException
{
    public:
        ReferenceError(const std::string& msg = ""):
            BaseException(msg)
        {}
};

// failure to allocate memory (new() returns NULL)
class MemoryAllocationError: public BaseException
{
    public:
        MemoryAllocationError(const std::string& msg = ""):
            BaseException(msg)
        {}
};

#endif
