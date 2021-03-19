#include <iostream>
#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

//int main()
//{
//    int min = 0;
//    int max = 0;
//    int d[6][8];
//    srand(time(0));
//
//    for (int i = 0; i < 6; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            d[i][j] = rand() % 100;
//        }
//    }
//    omp_set_num_threads(4);
//#pragma omp parallel for
//        for (int i = 0; i < 6; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//#pragma omp critical
//                if (d[i][j] < min) {
//                    min = d[i][j];
//                }
//                else if (d[i][j] > max) {
//                    max = d[i][j];
//                }
//            }
//            printf("%d\n", omp_get_thread_num());
//        }
//        printf("Min = %d and Max = %d,\n ", min, max);
//}

//int main() {
//    int a[30] = {};
//    int sum = 0;
//    srand(time(0));
//    for (int i = 0; i < 30; i++)
//    {
//        a[i] = rand() % 100;
//    }
//    omp_set_num_threads(4);
//#pragma omp parallel for
//    for (int i = 0; i < 30; i++)
//    {
//        if (a[i] % 7 == 0)
//        {
//#pragma omp atomic
//            sum++;
//        }
//        printf("%d\n", omp_get_thread_num());
//    }
//    printf("Answer is = %d", sum);
//}

//int main() {
//    int arr[50];
//    srand(time(0));
//    for (int i = 0; i < 50; i++)
//    {
//        arr[i] = rand() % 100;
//    }
//    int max = arr[0];
//    int count = 0;
//
//#pragma omp parallel for shared(max) schedule(dynamic)
//    for (int i = 0; i < 50; i++)
//    {
//        if (arr[i] % 7 == 0)
//        {
//#pragma omp critical
//            if (arr[i] > max)
//            {
//                max = arr[i];
//            }
//        }
//        printf("%d\n", omp_get_thread_num());
//    }
//    printf("Max = %i", max);
//}

//int main() {
//
//    // 1
//    int* threads = new int[8];
//    omp_set_num_threads(8);
//#pragma omp parallel
//    {
//#pragma omp for
//        for (int i = 0; i < 8; ++i)
//            threads[i] = omp_get_thread_num();
//#pragma omp for ordered
//        for (int i = 7; i >= 0; --i) {
//#pragma omp ordered
//            {
//                printf("Current thread: %i; Total number of threads: %i; Hello World!\n", threads[i], omp_get_num_threads());
//            }
//        }
//    }
//
//    printf("\n");
//
//    // 2
//#pragma omp parallel num_threads(8)
//    {
//        for (int i = omp_get_num_threads() - 1; i >= 0; i--) {
//#pragma omp barrier
//            {
//                if (i == omp_get_thread_num()) {
//#pragma omp critical
//                    printf("Hello world, thread num = %i, num of threads = %i\n", omp_get_thread_num(),
//                        omp_get_num_threads());
//                }
//            }
//        }
//    }
//
//    printf("\n");
//}

