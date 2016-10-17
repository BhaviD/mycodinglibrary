#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

class BaseException
{
    public:
        BaseException(const string& str = ""):
            msgString(str)
        {
            if (msgString == "")
                msgString = "Unspecified exception";
        }

        string what() const
        {
            return msgString;
        }

    // protected allows a derived class to access msgString.
    protected:
        string msgString;
};

// index out of range
class IndexRangeError: public BaseException
{
    public:
        IndexRangeError(const string& msg, int i, int size):
            BaseException()
        {
            char indexString[80];
            ostrstream indexErr(indexString, 80);

            indexErr << msg << "  index " << i << "  size = " << size << ends;
            // IndexRangeError can modify msgString, since it is in
            // the protected section of BaseException
            msgString = indexString;
        }
};

#endif
