#ifndef _BITVEC_H_
#define _BITVEC_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Exception.h"

class BitVector
{
    public:
        // CONSTRUCTORS

        // constructor. create bit vector of 0 bits
        BitVector(int numBits = 16);

        // constructor. create a bit vector whose
        // bits are initialized as follows:
        // bit 0:   b[0]
        // bit 1:   b[1]
        //          ...
        // bit n-1: b[n-1]
        BitVector(int b[], int n);


        // ASSIGNMENT OPERATORS
        // assign the bit vector the bits of v
        BitVector& operator= (int v);
        // assign the bit vector the 8-bits of c
        BitVector& operator= (char c);

        // ACCESS AND UPDATE FUNCTIONS
        // number of bits in the bit vector
        int size() const;

        // the functions bit(), set(), and clear() have
        // the following precondition.
        // Precondition: 0 <= i < numberOfBits. if the
        // condition is violated, the function throws
        // the IndexRangeError exception

        // return value of bit i
        int bit(int i) const;
        // set bit i
        void set(int i);
        // clear bit i
        void clear(int i);
        // clear all bits in the bit vector
        void clear();

        // BIT SET OPERATORS

        // the operators ==, |, &, and ^ have
        // the following precondition.
        // Precondition: the bit vectors must have the same size.
        // if the condition is violated, the function throws
        // the RangeError exception

        // bit vector equality
        friend bool operator== (const BitVector& x,
                                        const BitVector& y);
        // bitwise OR
        friend BitVector operator| (const BitVector& x,
                                             const BitVector& y);
        // bitwise AND
        friend BitVector operator& (const BitVector& x,
                                             const BitVector& y);
        // bitwise EOR
        friend BitVector operator^ (const BitVector& x,
                                             const BitVector& y);

        // shift bit vector to the left n bits
        friend BitVector operator<< (const BitVector& x, int n);
        // shift bit vector to the right n bits
        friend BitVector operator>> (const BitVector& x, int n);
        // bitwise NOT
        BitVector operator~ ();

        // BIT SET I/O
        // output the bit vector to the binary file ostr
        void write(fstream& ostr);
        // read the numBits bit vector from the binary file istr
        void read(fstream& istr, int numBits);
        // output the bit vector in ASCII form
        friend std::ostream& operator<< (std::ostream& ostr, const BitVector& x);

    private:
        // number of bits in the vector
        int numberOfBits;

        // number of bytes in bit vector
        int vectorSize;
        // the vector itself
        std::vector<unsigned char> member;

        // determine the index of the vector element
        // containing bit i
        int vectorIndex(int i) const;

        // bit i is represented by a bit in member[vectorIndex(i)].
        // return an unsigned char value with a 1 in the
        // position that represents bit i
        unsigned char bitMask(int i) const;
};

int BitVector::vectorIndex(int i) const
{
    // return i / 8
    return i >> 3;
}

unsigned char BitVector::bitMask(int i) const
{
    // use & to find the remainder after dividing by
    // 8. remainder 0 puts a 1 in the left-most bit
    // and 7 puts a 1 in the right-most bit
    return 1 << (7 - (i & 7));
}

BitVector::BitVector(int numBits): numberOfBits(numBits)
{
    // number of unsigned characters needed to hold
    // numberOfBits elements
    vectorSize = (numberOfBits + 7) >> 3;

    // resize the vector with all bytes 0
    member.resize(vectorSize);
}

BitVector::BitVector(int b[], int n): numberOfBits(n)
{
    int i;

    // number of unsigned characters needed to hold
    // numberOfBits elements
    vectorSize = (numberOfBits + 7) >> 3;

    // resize the vector with all bytes 0
    member.resize(vectorSize);

    // set all bits i for which b[i] != 0
    for (i=0; i < numberOfBits; i++)
        if (b[i] != 0)
            set(i);
}

BitVector& BitVector::operator= (int v)
{
    int b;
    // ~0 has value 111...111 in binary.
    // (~0) >> 1 has value 011...111
    // ~((~0) >> 1) has value 100...000.
    // when mask and value are combined with &,
    // all bits but the bit corresponding to the
    // 1 in mask are 0, and the bit corresponding
    // to the 1 in mask retains its value. this
    // allows us to determine if the designated bit
    // is 0 (mask & value == 0) or 1 (mask & value != 0)
    unsigned int mask = ~((unsigned int)(~0) >> 1);

    // compute the number of bits in an int
    numberOfBits = sizeof(int) * 8;
    // number of unsigned characters needed to hold
    // an int
    vectorSize = sizeof(int);

    // adjust the vector
    member.resize(vectorSize);

    for (b = 0; b < numberOfBits; b++)
    {
        // see if the current bit of value is 1. if
        // so, set bit b of x
        if (mask & v)
            set(b);
        else
            clear(b);
        // move the 1 bit to the right
        mask >>= 1;
    }

    return *this;
}

BitVector& BitVector::operator= (char c)
{
    int b;
    // ~0 has value 111...111 in binary.
    // (unsigned char)(~0) >> 1 has value 01111111
    // ~((~0) >> 1) has value 10000000.
    // when mask and value are combined with &,
    // all bits but the bit corresponding to the
    // 1 in mask are 0, and the bit corresponding
    // to the 1 in mask retains its value. this
    // allows us to determine if the designated bit
    // is 0 (mask & value == 0) or 1 (mask & value != 0)
    unsigned char mask = ~((unsigned char)(~0) >> 1);

    // compute the number of bits in a char
    numberOfBits = sizeof(char) * 8;
    // number of unsigned characters needed to hold
    // a character
    vectorSize = sizeof(char);

    // adjust the vector
    member.resize(vectorSize);

    for (b = 0; b < numberOfBits; b++)
    {
        // see if the current bit of value is 1. if
        // so, set bit b of x
        if (mask & c)
            set(b);
        else
            clear(b);
        // move the 1 bit to the right
        mask >>= 1;
    }

    return *this;
}

int BitVector::bit(int i) const
{
    // is i in range 0 to numberOfBits-1 ?
    if (i < 0 || i >= numberOfBits)
        throw IndexRangeError(
                        "BitVector bit(): bit out of range", i, numberOfBits);

    // return the bit corresponding to i
   if ((member[vectorIndex(i)] & bitMask(i)) != 0)
        return 1;
    else
        return 0;
}

void BitVector::set(int i)
{
    // is i in range 0 to numberOfBits-1 ?
    if (i < 0 || i >= numberOfBits)
        throw IndexRangeError(
                "BitVector set(): bit out of range", i, numberOfBits);

    // set bit i
    member[vectorIndex(i)] |= bitMask(i);
}

void BitVector::clear(int i)
{
    // is i in range 0 to numberOfBits-1 ?
    if (i < 0 || i >= numberOfBits)
        throw IndexRangeError(
                "BitVector clear(): bit out of range", i, numberOfBits);

    // clear the bit corresponding to i. note
    // that ~bitMask(i) has a 0 in the bit
    // we are interested in and 1 in all others
    member[vectorIndex(i)] &= ~bitMask(i);
}

int BitVector::size() const
{
    return numberOfBits;
}

void BitVector::clear()
{
    int i;

    for (i=0;i < vectorSize;i++)
        member[i] = 0;
}

bool operator== (const BitVector& x, const BitVector& y)
{
    bool result = true;

    // the bit vectors must have the same size
    if (x.numberOfBits != y.numberOfBits)
        return false;
//        throw RangeError("BitVector ==: bit vectors are not the same size");

    // compare the member vectors byte by byte
    for(int i=0;i < x.vectorSize;i++)
        if (x.member[i] != y.member[i])
        {
            result = false;
            break;
        }

    return result;
}

BitVector operator| (const BitVector& x, const BitVector& y)
{
    int i;

    // the bit vectors must have the same size
    if (x.numberOfBits != y.numberOfBits)
        throw
            RangeError("BitVector |: bit vectors are not the same size");

    // form the bitwise OR in tmp
    BitVector tmp(x.numberOfBits);

    // each vector element of tmp is the bitwise
    // OR of x and y
    for (i = 0; i < x.vectorSize; i++)
        tmp.member[i] = x.member[i] | y.member[i];

    // return the bitwise OR
    return tmp;
}

BitVector operator& (const BitVector& x, const BitVector& y)
{
    int i;

    // the bit vectors must have the same size
    if (x.numberOfBits != y.numberOfBits)
        throw
            RangeError("BitVector &: bit vectors are not the same size");

    // form the bitwise AND in tmp
    BitVector tmp(x.numberOfBits);

    // each vector element of tmp is the bitwise
    // AND of x and y
    for (i = 0; i < x.vectorSize; i++)
        tmp.member[i] = x.member[i] & y.member[i];

    // return the bitwise AND
    return tmp;
}

BitVector operator^ (const BitVector& x, const BitVector& y)
{
    int i;

    // the bit vectors must have the same size
    if (x.numberOfBits != y.numberOfBits)
        throw
            RangeError("BitVector ^: Bitvectors are not the same size");

    // form the bitwise EOR in tmp
    BitVector tmp(x.numberOfBits);

    // each vector element of tmp is the bitwise
    // AND of x and y
    for (i = 0; i < x.vectorSize; i++)
        tmp.member[i] = x.member[i] ^ y.member[i];

    // return the bitwise EOR
    return tmp;
}

BitVector operator<< (const BitVector& x, int n)
{
    // make a copy of x
    BitVector tmp = x;

    int i, j;
    unsigned char prevLeftBit, currLeftBit;
    // ~0 has value 111...111 in binary.
    // (unsigned char)(~0) >> 1 has value 011...111
    // ~((~0) >> 1) has value 100...000.
    // when mask and member[j] are combined with &,
    // all bits but the bit corresponding to the
    // 1 in mask are 0, and the bit corresponding
    // to the 1 in mask retains its value. this
    // isolates the left bit of member[j]
    unsigned char mask = ~((unsigned char)(~0) >> 1);

    // shift left one bit a total of n times
    for (i = 0; i < n; i++)
    {
        prevLeftBit = 0;
        // cycle through member vector right to left
        for (j = tmp.vectorSize - 1; j >= 0; j--)
        {
            // extract the left bit of member[j] and move it
            // to the right 7 bits. it will become
            // the right bit of member[j-1]
            currLeftBit = (tmp.member[j] & mask) >> 7;
            // shift left
            tmp.member[j] <<= 1;
            // add left bit of member[j+1] in right bit
            // of member[j]
            tmp.member[j] |= prevLeftBit;
            // prepare for next iteration
            prevLeftBit = currLeftBit;
        }
    }

    return tmp;
}

BitVector operator>> (const BitVector& x, int n)
{
    // make a copy of x
    BitVector tmp = x;

    int i, j;
    unsigned char prevRightBit, currRightBit;
    // used to isolate the right-most bit of a
    // member entry
    unsigned char mask = 1;

    // shift right one bit a total of n times
    for (i = 0; i < n; i++)
    {
        prevRightBit = 0;
        // cycle through member vector left to right
        for (j = 0; j < tmp.vectorSize; j++)
        {
            // extract right bit of member[j]. it will become
            // the left bit of member[j+1]
            currRightBit = tmp.member[j] & mask;
            // shift right
            tmp.member[j] >>= 1;
            // add right bit of member[j-1] in left bit
            // of member[j]
            tmp.member[j] |= (prevRightBit << 7);
            // prepare for next iteration
            prevRightBit = currRightBit;
        }
    }

    return tmp;
}

BitVector BitVector::operator~ ()
{
    // form the bitwise NOT in tmp
    BitVector tmp(numberOfBits);

    // each vector element of tmp is the bitwise
    // NOT of the current object's member values
    for (int i = 0; i < vectorSize; i++)
        tmp.member[i] = ~member[i];

    // return the bitwise NOT
    return tmp;
}

void BitVector::write(fstream& ostr)
{
    ostr.write((char *)&member[0], vectorSize);
    // send the pending output now
    ostr.flush();
}

void BitVector::read(fstream& istr, int numBits)
{
    // reassign numberOfBits
    numberOfBits = numBits;

    // number of unsigned characters needed to hold numBits
    // elements
    vectorSize = (numberOfBits+7) >> 3;

    // resize the vector
    member.resize(vectorSize);

    // read the bits
    istr.read((char *)&member[0], vectorSize);
}

std::ostream& operator<< (std::ostream& ostr, const BitVector& x)
{
    int b;

    for (b = 0; b < x.numberOfBits; b++)
        if (x.bit(b) != 0)
            ostr << 1;
        else
            ostr << 0;

    return ostr;
}

#endif  // _BITVEC_H_
