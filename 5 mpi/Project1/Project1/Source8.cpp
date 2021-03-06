//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
////10
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	srand(time(0));
//    int processId, size;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//	MPI_Status status;
//
//    int n = 200;
//    int* a = new int[200];
//
//    if (processId == 0) {
//
//        for (int i = 0; i < n; i++) {
//                a[i] = rand() % 10;
//        }
//    }
//
//    int* b = new int[50];
//
//    MPI_Scatter(a, 50, MPI_INT, b, 50, MPI_INT, 0, MPI_COMM_WORLD);
//
//    int norm = 0;
//    for (int i = 0; i < 50; i++) {
//        norm += abs(b[i]);
//    }
//    printf("norm = %i and process is %i\n", norm, processId);
//
//    int res = 0;
//    MPI_Reduce(&norm, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if (processId == 0) {
//        printf("Result is = %i\n", res);
//    }
//
//    MPI_Finalize();
//}