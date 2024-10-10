#include <iostream>

extern double __enzyme_autodiff(void*, double);

double square(double x) {
    return x * x;
}

double dsquare(double x) {
    // This returns the derivative of square or 2 * x
    return __enzyme_autodiff((void*) square, x);
}


int main()
{
    std::cout << "AD Experiment\n";
    for(double i=1; i<5; i++) {
        auto f = square(i);
        auto dx = dsquare(i);
        std::cout << 
            "f("<< i <<")=" << f << 
            ", df/dx (" << i << ")=" << dx << "\n";
    }
    std::cout << "Done: Ok" << std::endl;
}

