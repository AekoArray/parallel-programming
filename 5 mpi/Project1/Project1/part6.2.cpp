//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
////5
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
//    int matrix[8][8];
//
//    struct Rows {
//        int rows[16];
//    };
//
//    MPI_Datatype rowsType;
//    int lengths[1] = { 16 };
//    const MPI_Aint displacements[1] = { 0 };
//    MPI_Datatype types[1] = {MPI_INT};
//    MPI_Type_create_struct(1, lengths, displacements, types, &rowsType);
//    MPI_Type_commit(&rowsType);
//
//    if (processId == 0) {
//        printf("Matrix a:\n");
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                matrix[i][j] = rand() % 10;
//                printf("%i ", matrix[i][j]);
//            }
//            printf("\n");
//        }
//        for (int i = 0; i < 4; i++) {
//            Rows pair;
//            for (int j = 0; j < 8; j++) {
//                pair.rows[j] = matrix[i][j];
//            }
//            for (int j = 0; j < 8; j++) {
//                pair.rows[8 + j] = matrix[i + 4][j];
//            }
//            MPI_Send(&pair, 1, rowsType, i + 1, 0, MPI_COMM_WORLD);
//        }
//    } else {
//        Rows recv;
//        MPI_Recv(&recv, 1, rowsType, 0, 0, MPI_COMM_WORLD, &status);
//        printf("procces id: %i, matrix: \n", processId);
//        for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < 8; j++) {
//                printf("%i ", recv.rows[8 * i + j]);
//            }
//            printf("\n");
//        }
//    }
//    MPI_Finalize();
//}