#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double const eps = 1E-02;

double derivative(double f(double), double x) {
    double fxph = f(x + eps);
    double fxmh = f(x - eps);
    double df = fxph - fxmh; 
    double dx = 2.0 * eps;
    return df / dx;
}

double square(double x) {
    return x * x;
}

double f_double(double x) {
    return 2.0 * x;
}

void test_derivative(double f(double), double df(double), double x) {
    double computed_df = derivative(f, x);
    double real_df = df(x);
    double error = fabs(computed_df - real_df);
    printf("x=%.5e,\tcomputed df=%.5e,\treal df=%5.e,\terror=%.10f\n",
            x, computed_df, real_df, error);
}

int main(void) {
    printf("f(x)=x^2:\n");
    test_derivative(square, f_double, 1.0);
    printf("f(x)=sin(x):\n");
    test_derivative(sin, cos, M_PI);
    return EXIT_SUCCESS;
}