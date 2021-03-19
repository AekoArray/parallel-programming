// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
//int main() {
//	int a = 210;
//	int num = 0;
//#pragma omp parallel for lastprivate(num)
//	for (int i = 1; i < a * 2; i = i + 2) {
//		num = num + i;
//	}
//	printf("%i", num);
//}
//int main() {
//	int first, second;
//	std::cout << "Enter two number: ";
//	std::cin >> first >> second;
//	printf("\nNumbers: \n");
//	omp_set_num_threads(4);
//#pragma omp parallel for
//	for (int i = first; i < second; i++) {
//		bool simple = true;
//		for (int j = 2; j <= sqrt(i); j++) {
//			if (i % j == 0) {
//				simple =  false;
//			}
//		}
//		if (simple) {
//			printf("%d\n", i);
//		}
//	}
//}
