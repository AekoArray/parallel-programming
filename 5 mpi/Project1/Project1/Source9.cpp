//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
////11
//using namespace std;
//
//int main(int argc, char* argv[]) {
//    srand(time(0));
//    int processId, size;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//    MPI_Status status;
//
//    int n = 200;
//    int* a = new int[200];
//    int* a1 = new int[200];
//
//    if (processId == 0) {
//
//        for (int i = 0; i < n; i++) {
//            a[i] = rand() % 10;
//            a1[i] = rand() % 10;
//        }
//    }
//
//    int* b = new int[50];
//    int* b1 = new int[50];
//
//    MPI_Scatter(a, 50, MPI_INT, b, 50, MPI_INT, 0, MPI_COMM_WORLD);
//    MPI_Scatter(a1, 50, MPI_INT, b1, 50, MPI_INT, 0, MPI_COMM_WORLD);
//
//
//    int scal = 0;
//    for (int i = 0; i < 50; i++) {
//        scal += b[i] * b1[i];
//    }
//    printf("norm = %i and process is %i\n", scal, processId);
//
//    int res = 0;
//    MPI_Reduce(&scal, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if (processId == 0) {
//        printf("Result is = %i\n", res);
//    }
//
//    MPI_Finalize();
//}