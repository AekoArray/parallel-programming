#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

int main() {
    int a[30] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
    int num = 0;
    omp_set_num_threads(4);
    #pragma omp parallel for
    for (int i = 0; i < 30; i++) {
        num += a[30 - i - 1] * pow(2, i);
        printf("%d\n", omp_get_thread_num());
    }
    printf("%i", num);
}

