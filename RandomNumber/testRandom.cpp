#include <iostream>
#include <fstream>
#include "Random.h"
using namespace std;

int main()
{
    randomNumber rndm1, rndm2(50);
    
    ofstream fout("output.txt", ios_base::trunc);
    for(int i = 0; i < 50; ++i)
    {
        fout << "rndm1 = " << rndm1.random(6) << endl;
    } 
    for(int i = 0; i < 50; ++i)
    {
        fout << "rndm2 = " << rndm2.random(6) << endl;
    }
    for(int i = 0; i < 50; ++i)
    {
        fout << "rndm1 frand = " << rndm1.frandom() << endl;
    }

    return 0;
}
