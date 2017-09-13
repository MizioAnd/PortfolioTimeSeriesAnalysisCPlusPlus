// two_sigma_program.cpp -- the client program
// compile with two_sigma.cpp
// h5c++ -g -O0 two_sigma.cpp two_sigma_program.cpp

#include <iostream>
#include "two_sigma.h"

int main()
{
    using namespace std; 
    TwoSigmaFinModTools tools(false, 11);
    return 0;
}