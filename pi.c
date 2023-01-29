#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double pi(size_t digit_accuracy) {
    double a = 1.0;
    double b = 1.0 / sqrt(2.0);
    double t = 0.25;
    double p = 1.0;
    size_t n = ceil(log2(digit_accuracy));
    for (size_t i = 0; i < n; i++) {
        double a1 = (a + b) / 2.0;
        double b1 = sqrt(a * b);
        double p1 = 2 * p;
        t = t - p * (a - a1) * (a - a1);
        a = a1;
        b = b1;
        p = p1;
    }
    return (a + b) * (a + b) / (4.0 * t);
}

int main(void) {
    printf("%.15f", pi(10));
    return EXIT_SUCCESS;
}