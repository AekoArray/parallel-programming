//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//
//int main(int argc, char* argv[]) {
//    srand(time(0));
//    int processId, size;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//    MPI_Status status;
//    MPI_Datatype newType;
//    int matrix[3][3] = {0,0,0,0,0,0,0,0,0};
//
//    if (processId == 0) {
//        /*int matrix[3][3] = { 4, 5, 6,
//                             0 ,3, 2,
//                             0, 0, 1 };*/
//        for (int i = 0; i < 3; i++) {
//            for (int j = 0; j < 3; j++) {
//                if (!(((i == 1) & (j == 0)) || ((i == 2) & (j == 0)) || ((i == 2) & (j == 1)))) {
//                    matrix[i][j] = rand() % 100;
//                }
//                else {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//        printf("Matrix: \n");
//        for (int i = 0; i < 3; i++) {
//            for (int j = 0; j < 3; j++) {
//                printf("%i ", matrix[i][j]);
//            }
//            printf("\n");
//        }
//
//        MPI_Datatype type;
//        int lenghts[3] = { 3, 2, 1 };
//        int displacements[3] = { 0 , 4, 8 };
//        MPI_Type_indexed(3, lenghts, displacements, MPI_INT, &type);
//        MPI_Type_commit(&type);
//
//        for (int i = 1; i < size; i++) {
//            MPI_Send(matrix, 1, type, i, 0, MPI_COMM_WORLD);
//        }
//
//    }
//    //MPI_Datatype type;
//    //int lenghts[3] = { 3, 2, 1 };
//    //int displacements[3] = { 0 , 4, 8 };
//    //MPI_Type_indexed(3, lenghts, displacements, MPI_INT, &type);
//    //MPI_Type_commit(&type);
//
//    /*MPI_Bcast(matrix, 1, type, 0, MPI_COMM_WORLD);*/
//
//    if(processId == 1) {
//        int buf[6];
//        MPI_Recv(&buf, 6, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//        printf("process = %i, matrix: ", processId);
//        for (int i = 0; i < 6; i++) {
//            
//            printf("%i ", buf[i]);
//        }
//        printf("\n");
//    }
//    MPI_Finalize();
//}
//
