//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
////13
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
//    int A[m][n];
//    int B[m][n];
//    int C[m][n];
//    
//    if (processId == 0) {
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                A[i][j] = rand() % 10;
//                B[i][j] = rand() % 10;
//            }
//        }
//    }
//
//    int Ap[2][n];
//    int Bp[2][n];
//    int Cp[2][n];
//
//    MPI_Scatter(A, 16, MPI_INT, &Ap,
//        16, MPI_INT, 0, MPI_COMM_WORLD);
//
//    MPI_Scatter(B, 16, MPI_INT, &Bp,
//        16, MPI_INT, 0, MPI_COMM_WORLD);
//
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < n; j++) {
//            Cp[i][j] = Ap[i][j] * Bp[i][j];
//        }
//    }
//        printf("process is %i\n", processId);
//
//    MPI_Gather(Cp, 16, MPI_INT,
//        &C, 16, MPI_INT, 0, MPI_COMM_WORLD);
//
//    if (processId == 0) {
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                printf("%i ", C[i][j]);
//            }
//            printf("\n");
//        }
//    }
//
//    MPI_Finalize();
//
//}