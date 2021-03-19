//#include<stdio.h>
//#include<iostream>
//#include<mpi.h>
//#include <cmath>
//
////8.2
//int main(int argc, char **argv) {
//
//
//    const int n = 2;
//    const int m = 3;
//    int i_process, n_processes;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &n_processes);
//    MPI_Comm_rank(MPI_COMM_WORLD, &i_process);
//
//    if (i_process == 0) {
//        int a[m][n] =
//                {
//                        {1, 2},
//                        {3, 4},
//                        {5, 6}
//                };
//
//        int b[n][m] =
//                {
//                        {1, 2, 3},
//                        {4, 5, 6}
//                };
//
//        int num_of_m = ceil((double) m / (n_processes - 1));
//
//        printf("Number of process - %d and total - %d\n", i_process, n_processes);
//        for (int i = 1; i < n_processes; i++) {
//            int start_m = (i - 1) * num_of_m;
//            if (m - start_m <= num_of_m) {
//                num_of_m = m - start_m;
//            }
//            start_m = (i - 1) * num_of_m;
//
//            MPI_Send(&b[0][0], n * m, MPI_INT, i, 12, MPI_COMM_WORLD);
//            for (int j = start_m; j < start_m + num_of_m; j++) {
//                MPI_Send(&a[j], n, MPI_INT, i, 11, MPI_COMM_WORLD);
//            }
//        }
//        for (int i = 1; i < n_processes; i++) {
//            int * buf_c = new int[m];
//            MPI_Status status;
//
//            for (int j = 0; j < m; j++) {
//                buf_c[j] = 0;
//            }
//            MPI_Recv(buf_c, m, MPI_INT, i, 100, MPI_COMM_WORLD, &status);
//
//            for (int j = 0; j < m; j++) {
//                printf("c = %d ", buf_c[j]);
//            }
//            printf("\n");
//        }
//    } else if (i_process != 0) {
//
//        MPI_Status status_a;
//        MPI_Status status_b;
//
//        int * bfr_a = new int[n];
//        int bfr_b[n][m];
//        int multiplication[m];
//
//        printf("Number of process - %d and total - %d\n", i_process, n_processes);
//        MPI_Recv(bfr_a, n, MPI_INT, 0, 11, MPI_COMM_WORLD, &status_a);
//        MPI_Recv(&bfr_b, n * m, MPI_INT, 0, 12, MPI_COMM_WORLD, &status_b);
//
//        for (int j = 0; j < n; j++) {
//            printf("a[%d] = %d ", j, bfr_a[j]);
//        }
//        printf("\n");
//
//        for (int j = 0; j < n; j++) {
//            for (int i = 0; i < m; i++) {
//                printf("b[%d][%d] = %d ", j, i, bfr_b[j][i]);
//            }
//            printf("\n");
//        }
//
//        for (int i = 0; i < m; i++) {
//            multiplication[i] = 0;
//        }
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                multiplication[i] += bfr_a[j] * bfr_b[j][i];
//            }
//            printf("multiplication[%d] = %d ", i, multiplication[i]);
//        }
//        MPI_Send(&multiplication, m, MPI_INT, 0, 100, MPI_COMM_WORLD);
//    }
//
//    MPI_Finalize();
//}