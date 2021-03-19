#include <iostream>
#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <chrono>

int main() {

	const int len = 16000;

	int a[len];

	int b[len - 2];

	int i;

#pragma omp parallel num_threads(2)

	{

		auto time1 = std::chrono::high_resolution_clock::now();

#pragma omp for private(i) schedule(runtime)

		for (i = 0; i < len; i++)
		{
			a[i] = i;
		}

		for (i = 1; i < len - 1; i++)
		{
			b[i - 1] = (a[i - 1] + a[i] + a[i + 1]) / 3;
		}
		auto time2 = std::chrono::high_resolution_clock::now();

		printf("With OpenMP = %lld ms\n", std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count());

	}
}