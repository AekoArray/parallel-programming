//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
////12
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
//    const int m = 8;
//    const int n = 8;
//
//    int arr[m][n];
//
//    if (processId == 0) {
//        int c = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                arr[i][j] = rand() % 10;
//            }
//        }
//    }
//
//    int arrPart[2][n];
//
//    MPI_Scatter(arr, 16, MPI_INT, &arrPart, 16, MPI_INT, 0, MPI_COMM_WORLD);
//
//    int max = 0;
//    for (int i = 0; i < 2; i++) {
//        int sum = 0;
//        for (int j = 0; j < n; j++) {
//            sum += abs(arrPart[i][j]);
//        }
//        if (sum > max) {
//            max = sum;
//        }
//    }
//    printf("max = %i and process is %i\n", max, processId);
//
//    int res = 0;
//    MPI_Reduce(&max, &res, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
//    
//    if (processId == 0) {
//        printf("Norm = %i\n", res);
//    }
//
//    MPI_Finalize();
//}