//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
////14
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
//    const int n = 2;
//
//    int arr[m][n];
//    int vec[m];
//
//    if (processId == 0) {
//            for (int i = 0; i < m; i++) {
//                for (int j = 0; j < n; j++) {
//                arr[i][j] = rand() % 10;
//            }
//        }
//            for (int i = 0; i < n; i++) {
//                vec[i] = rand() % 10;
//            }
//    }
//
//    int arrPart[2][2];
//    int vecPart[2];
//
//    MPI_Bcast(vec, n, MPI_INT, 0, MPI_COMM_WORLD);
//    
//    MPI_Scatter(arr, 4, MPI_INT, &arrPart, 4, MPI_INT, 0, MPI_COMM_WORLD);
//
//    for (int i = 0; i < 2; i++) {
//        int res = 0;
//        for (int j = 0; j < n; j++) {
//            res += arrPart[i][j] * vec[j];
//        }
//        vecPart[i] = res;
//    }
//    printf("process is %i\n", processId);
//
//    MPI_Gather(vecPart, 2, MPI_INT, &vec, 2, MPI_INT, 0, MPI_COMM_WORLD);
//    
//    if (processId == 0) {
//        for (int i = 0; i < m; i++) {
//            printf("%i ", vec[i]);
//        }
//        printf("\n");
//    }
//
//    MPI_Finalize();
//}