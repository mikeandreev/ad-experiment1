#include "calc/f1.h"

#include "adcalc/dsquare.h"
#include <iostream>

void f1(int start, int end)
{
    for(double i=start; i<end; i++) {
        //auto f = square(i);
        const auto [f, dx] = dsquare(i);
        std::cout << 
            "f("<< i <<")=" << f << 
            ", df/dx(" << i << ")=" << dx << "\n";
    }
}

