//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
// //3
//using namespace std;
//int main(int argc, char* argv[]) {
//    srand(time(0));
//    int processId, size;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//    MPI_Status status;
//    MPI_Datatype newType;
//
//    const int n = 8;
//    const int m = 8;
//
//    int a[n][m];
//    int b[n / 2][m];
//    int c[n / 2][m];
//
//
//    if (processId == 0) {
//        printf("Matrix a:\n");
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                a[i][j] = rand() % 10;
//                printf("%i ", a[i][j]);
//            }
//            printf("\n");
//        }
//        MPI_Datatype newType;
//        MPI_Type_vector(4, 8, 16, MPI_INT, &newType);
//        MPI_Type_commit(&newType);
//
//                for (int i = 0; i < 2; i++) {
//            MPI_Send(&a[i][0], 1, newType, i + 1, 0, MPI_COMM_WORLD);
//        }
//
//    }
//
//    if (processId == 1) {
//        int rec[32];
//        MPI_Recv(rec, 32, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//        printf("mantrix odd: \n");
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 8; j++) {
//                printf("%i ", rec[8 * i + j]);
//            }
//            printf("\n");
//        }
//    }
//    if (processId == 2) {
//        int rec[32];
//        MPI_Recv(rec, 32, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//        printf("mantrix even: \n");
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 8; j++) {
//                printf("%i ", rec[8 * i + j]);
//            }
//            printf("\n");
//        }
//    }
//
//        MPI_Finalize();
//        return 0;
//}
//
