//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <omp.h> 
//#include <stdlib.h>
//#include <time.h>
//#include <vector>
////8.1
//int main(int argc, char **argv) {
//
//    const int n = 4;
//    double a[n][n], b[n][n], c[n][n];
//    int i_process, n_processes;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &n_processes);
//    MPI_Comm_rank(MPI_COMM_WORLD, &i_process);
//
//    if (i_process == 0) {
//
//        for (int i = 0; i < n; i ++) {
//            for (int j = 0; j < n; j ++) {
//                a[i][j] = rand() % 10;
//                b[i][j] = rand() % 10;
//            }
//        }
//
//        int num = ceil((double) n / (n_processes - 1));
//        printf("Number of process - %d and total - %d\n", i_process, n_processes);
//        for (int i = 1; i < n_processes; i ++) {
//            int start_row = (i - 1) * num;
//
//            if (n - start_row <= num) {
//                num = n - start_row;
//            }
//            MPI_Send(&num, 1, MPI_INT, i, 5, MPI_COMM_WORLD);
//            MPI_Send(&start_row, 1, MPI_INT, i, 10, MPI_COMM_WORLD);
//
//            for (int j = start_row; j < start_row + num; j ++) {
//                MPI_Send(&a[j][0], n, MPI_DOUBLE, i, 11, MPI_COMM_WORLD);
//                MPI_Send(&b[j][0], n, MPI_DOUBLE, i, 22, MPI_COMM_WORLD);
//            }
//
//            double buffer_c[n][n];
//            MPI_Status status_c;
//
//            for (int j = start_row; j < start_row + num; j ++) {
//                MPI_Recv(buffer_c[j], n, MPI_DOUBLE, i, 55, MPI_COMM_WORLD, &status_c);
//
//                for (int k = 0; k < n; k++) {
//                    printf("arr[%d][%d] = %.2f ", j, k, buffer_c[j][k]);
//                }
//                printf("\n");
//            }
//        }
//    }
//
//    else if (i_process != 0){
//        int elements;
//        int start;
//        MPI_Status status_a;
//        MPI_Status status_b;
//        MPI_Status status_el;
//        MPI_Status status_st;
//
//        MPI_Recv(&elements, 1, MPI_INT, MPI_ANY_SOURCE, 5, MPI_COMM_WORLD, &status_el);
//        MPI_Recv(&start, 1, MPI_INT, MPI_ANY_SOURCE, 10, MPI_COMM_WORLD, &status_st);
//
//        double buffer_a[n][n];
//        double buffer_b[n][n];
//
//        printf("from process = %d \n", i_process);
//        for (int i = start; i < start + elements; i++) {
//            MPI_Recv(&buffer_a[i], n, MPI_DOUBLE, MPI_ANY_SOURCE, 11, MPI_COMM_WORLD, &status_a);
//            MPI_Recv(&buffer_b[i], n, MPI_DOUBLE, MPI_ANY_SOURCE, 22, MPI_COMM_WORLD, &status_b);
//
//            for (int j = 0; j < n; j++) {
//                printf("a[%d][%d] = %.2f ", i, j, buffer_a[i][j]);
//            }
//            printf("\n");
//
//            for (int j = 0; j < n; j++) {
//                printf("b[%d][%d] = %.2f ", i, j, buffer_b[i][j]);
//            }
//
//            printf("\n");
//
//            for (int j = 0; j < n; j++) {
//                c[i][j] = buffer_a[i][j] * buffer_b[i][j];
//                printf("c[%d][%d] = %.2f ", i, j, c[i][j]);
//            }
//            printf("\n");
//
//            MPI_Send(&c[i][0], n, MPI_DOUBLE, 0, 55, MPI_COMM_WORLD);
//        }
//    }
//
//    MPI_Finalize();
//}