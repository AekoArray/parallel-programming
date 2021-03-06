//#include <iostream>
//#include <mpi.h>
//#include <stdio.h>
//#include <math.h>
//
//int main(int argc, char** argv) {
//
//    /*
//     * ????? ??????? ?????????????? ????????????? ????? ???????
//     */
//
//    MPI_Init(&argc, &argv);
//
//    const int N = 20;
//    int process_id, size;
//    int arr[N];
//    int sum[2], local_sum[2];
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
//
//    if (process_id == 0) {
//        printf("Array:\n");
//        for (int i = 0; i < N; i++) {
//            arr[i] = rand() % 20-10;
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//    }
//
//    int* len = new int[size];
//
//    int* ind = new int[size];
//
//    int rest = N;
//    int k = rest / size;
//
//    len[0] = k;
//    ind[0] = 0;
//
//    for (int i = 1; i < size; i++) {
//        rest -= k;
//        k = rest / (size - i);
//        len[i] = k;
//        ind[i] = ind[i - 1] + len[i - 1];
//    }
//
//    int nProc = len[process_id];
//    int* aProc = new int[nProc];
//
//    MPI_Scatterv(arr, len, ind, MPI_INT, aProc, nProc,MPI_INT, 0, MPI_COMM_WORLD);
//
//    local_sum[0] = 0;
//    local_sum[1] = 0;
//    for (int i = 0; i < nProc; i++) {
//        if (aProc[i] > 0) {
//
//            local_sum[0] += aProc[i];
//            local_sum[1]++;
//        }
//    }
//
//    MPI_Reduce(&local_sum, &sum, 2, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if (process_id == 0) {
//        double result = (double)sum[0] / sum[1];
//        printf("\nResult: %f\n", result);
//    }
//
//    MPI_Finalize();
//}