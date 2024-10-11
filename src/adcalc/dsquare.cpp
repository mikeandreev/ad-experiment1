#include "adcalc/dsquare.h"

#include "adcalc/enzyme.h"
#include "adcalc/square.h"


std::tuple<double, double> dsquare(double x)
{
    const double f = square(x);
    double dx = 0.;
    __enzyme_autodiff(
        square, 
        enzyme_dup, &x, &dx
    );
    return {f, dx};
}