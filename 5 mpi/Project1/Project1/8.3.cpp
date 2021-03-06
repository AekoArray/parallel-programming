//#include <stdio.h>
//#include <mpi.h>
//#include <math.h>
//#include <time.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//
//
//void sort(int* v, int n) {
//    int i, j;
//    for (i = n - 2; i >= 0; i--)
//        for (j = 0; j <= i; j++)
//            if (v[j] > v[j + 1]){
//                int t;
//                t = v[j];
//                v[j] = v[j + 1];
//                v[j + 1] = t;
//            }
//}
//
//int* mergeArrays(int* v1, int n1, int* v2, int n2) {
//    int i, j, k;
//    int* result;
//
//    result = new int[n1 + n2];
//    i = 0;
//    j = 0;
//    k = 0;
//
//    while (i < n1 && j < n2)
//        if (v1[i] < v2[j]) {
//            result[k] = v1[i];
//            i++;
//            k++;
//        }
//        else {
//            result[k] = v2[j];
//            j++;
//            k++;
//        }
//
//    if (i == n1)
//        while (j < n2) {
//            result[k] = v2[j];
//            j++;
//            k++;
//        }
//    if (j == n2)
//        while (i < n1) {
//            result[k] = v1[i];
//            i++;
//            k++;
//        }
//
//    return result;
//}
//
//int main(int argc, char** argv) {
//
//    int* data;
//    int* ar;
//
//    int r, s;
//    const int N = 15;
//    int i;
//
//    int* sub;
//    int m;
//    int move;
//
//    int rank, size;
//    MPI_Status status;
//    srand(time(0));
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//
//    if (rank == 0) {
//        s = N / size;
//        r = N % size;
//
//        data = new int[N + size - r];
//
//        for (i = 0; i < N; i++)
//        {
//            data[i] = (rand() % 10 + 1);
//            printf("%d ",data[i]);
//        }
//        printf("\n");
//        if (r != 0) {
//            for (i = N; i < N + size - r; i++)
//            {
//                data[i] = 0;
//            }
//            s = s + 1;
//        }
//
//        MPI_Bcast(&s, 1, MPI_INT, 0, MPI_COMM_WORLD);
//        ar = new int[s];
//        MPI_Scatter(data, s, MPI_INT, ar, s, MPI_INT, 0, MPI_COMM_WORLD);
//        sort(ar, s);
//    }
//    else {
//        MPI_Bcast(&s, 1, MPI_INT, 0, MPI_COMM_WORLD);
//        ar = new int[s];
//        MPI_Scatter(&data, s, MPI_INT, ar, s, MPI_INT, 0, MPI_COMM_WORLD);
//        sort(ar, s);
//    }
//
//    move = 1;
//
//    while (move < size) {
//        if (rank % (2 * move) == 0) {
//            if (rank + move < size) {
//                MPI_Recv(&m, 1, MPI_INT, rank + move, 0, MPI_COMM_WORLD, &status);
//                sub = new int[m];
//                MPI_Recv(sub, m, MPI_INT, rank + move, 0, MPI_COMM_WORLD, &status);
//                ar = mergeArrays(ar, s, sub, m);
//                s = s + m;
//            }
//        }
//        else {
//            int near = rank - move;
//            MPI_Send(&s, 1, MPI_INT, near, 0, MPI_COMM_WORLD);
//            MPI_Send(ar, s, MPI_INT, near, 0, MPI_COMM_WORLD);
//            break;
//        }
//
//        move = move * 2;
//    }
//
//    if (rank == 0) {
//
//        sort(data, N+size-r);
//        for (i = size-r; i < N + size - r; i++)
//        {
//            printf("%d ", ar[i]);
//        }
//        printf("\n");
//    }
//
//    MPI_Finalize();
//}
//


