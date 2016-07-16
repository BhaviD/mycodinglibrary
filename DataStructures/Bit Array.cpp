#include <iostream>
#include <string>
using namespace std;

#define BIT_ARRAY_LENGTH 32 + 1
 
struct Bit
{
    unsigned int val : 1;
};

class BitArray
{
    private:
        Bit bits[BIT_ARRAY_LENGTH];
        int size{ 0 };
        int value{ 0 };
        void RecalculateSize()
        {
            for (int pos = 1; pos < BIT_ARRAY_LENGTH; ++pos)
            {
                if (bits[pos].val)
                size = pos;
            }
        }

    public:
        BitArray(int num = 0)
        {
            value = num;
            for (int pos = 1; pos < BIT_ARRAY_LENGTH; ++pos)
            {
                bits[pos].val = (value & (1 << (pos - 1))) >> (pos - 1);
                if (bits[pos].val)
                    size = pos;
            }
        }

        int Size()
        {
            return size;
        }

        unsigned int GetBit(int pos)
        {
            return bits[pos].val;
        }

        void SetBit(int pos)
        {
            if (bits[pos].val)
                return;

            bits[pos].val = 1;
            if (pos > size)
                size = pos;

            value |= 1 << (pos - 1);
        }

        void UnsetBit(int pos)
        {
            if (!bits[pos].val)
                return;

            bits[pos].val = 0;
            if (pos == size)
                RecalculateSize();

            value ^= 1 << (pos - 1);
        }

        int Value()
        {
            return value; 
        }

        void ShowBinaryForm()
        {
            cout << "(" << value << "): ";
            for (int pos = size; pos > 0; --pos)
            {
                cout << GetBit(pos) << " ";
            }
        }
};

int main()
{
    int num;
    cout << "Enter 32 bit integer value(0 - (2^32 - 1)): ";
    cin >> num;

    BitArray* A = new BitArray {num};

    cout << "\nThe value is: " << A->Value() << endl;
    A->ShowBinaryForm();

    A->SetBit(4);
    cout << "\nThe value is: " << A->Value() << endl;
    A->ShowBinaryForm();

    A->UnsetBit(7);
    cout << "\nThe value is: " << A->Value() << endl;
    A->ShowBinaryForm();

    return 0;
}
