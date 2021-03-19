//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//using namespace std;
//
//
//
//int main(int argc, char** argv) {
//
//    int newGroupOfProcesses[5] = { 8, 3, 9, 1, 6 };
//
//    int rank;
//    int world_size;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    MPI_Status status;
//
//    MPI_Group groupFirst;
//    MPI_Group groupSecond;
//    MPI_Comm_group(MPI_COMM_WORLD, &groupFirst);
//    MPI_Group_incl(groupFirst, 5, newGroupOfProcesses, &groupSecond);
//
//    MPI_Comm comm;
//    MPI_Comm_create(MPI_COMM_WORLD, groupSecond, &comm);
//
//    int current_rank = -1;
//
//    int a[10];
//
//    if (comm != MPI_COMM_NULL) {
//        MPI_Comm_rank(comm, &current_rank);
//    }
//
//    if (current_rank == 0 && comm != MPI_COMM_NULL) {
//
//        for (int i = 0; i < 10; i++) {
//
//            a[i] = rand() % 10;
//
//        }
//
//        MPI_Bcast(&a, 10, MPI_INT, 0, comm);
//
//    }
//
//    if (current_rank != -1 && comm != MPI_COMM_NULL) {
//
//        MPI_Bcast(&a, 10, MPI_INT, 0, comm);
//
//        cout << "Process = " << current_rank << " array: " << endl;
//
//        for (int i = 0; i < 10; i++) {
//
//            cout << a[i] << " ";
//
//        }
//
//        cout << endl;
//
//        if (current_rank == 4) {
//
//            MPI_Send(a, 10, MPI_INT, 0, 0, MPI_COMM_WORLD);
//
//        }
//
//    }
//
//    if (rank == 0) {
//
//        MPI_Recv(a, 10, MPI_INT, 6, 0, MPI_COMM_WORLD, &status);
//
//        cout << "Results " << endl;
//
//        for (int i = 0; i < 10; i++) {
//
//            cout << a[i] << " ";
//
//        }
//
//        cout << endl;
//
//    }
//
//    if (comm != MPI_COMM_NULL) {
//
//        MPI_Comm_free(&comm);
//
//    }
//
//    MPI_Group_free(&groupSecond);
//    MPI_Finalize();
//    return 0;
//}