//#include <iostream>
//#include <mpi.h>
//#include <stdio.h>
//#include <math.h>
//
//using namespace std;
//
//
//
//int main(int argc, char** argv) {
//
//    int world_rank;
//    int world_size;
//
//    const int N = 4;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    int proc = world_rank / 3;
//
//    MPI_Comm my_comm;
//    MPI_Comm_split(MPI_COMM_WORLD, proc, world_rank % 3, &my_comm);
//
//    int rank = -1;
//    int size = -1;
//
//    if (my_comm != MPI_COMM_NULL) {
//        MPI_Comm_rank(my_comm, &rank);
//    }
//
//    if (my_comm != MPI_COMM_NULL) {
//        MPI_Comm_size(my_comm, &size);
//    }
//
//    int array[N] = { proc, proc, proc, proc };
//
//    int com[N * 3];
//
//    MPI_Gather(&array, 4, MPI_INT, &com, 4, MPI_INT, 0, my_comm);
//
//    if (rank == 0) {
//
//        cout << "Process = " << proc << " arr = ";
//
//        for (int i = 0; i < 12; ++i) {
//
//            cout << com[i] << " ";
//
//        }
//
//        cout << endl;
//
//    }
//
//    int tag = -1;
//    int rlead = -1;
//
//    if (proc == 0) {
//        tag = 333;
//        rlead = 3;
//    }
//
//    if (proc == 1) {
//        tag = 333;
//        rlead = 0;
//    }
//
//    if (proc == 2) {
//        tag = 999;
//        rlead = 9;
//    }
//
//    if (proc == 3) {
//        tag = 999;
//        rlead = 6;
//    }
//
//    MPI_Comm intercomm;
//
//    MPI_Intercomm_create(my_comm, 0, MPI_COMM_WORLD, rlead, tag, &intercomm);
//
//    if ((proc == 0 || proc == 2) && rank == 0) {
//
//        MPI_Send(&com, 12, MPI_INT, 0, proc, intercomm);
//
//    }
//
//    if ((proc == 1 || proc == 3) && rank == 0) {
//
//        int buf[12];
//
//        MPI_Recv(&buf, 12, MPI_INT, MPI_ANY_SOURCE, proc - 1, intercomm, MPI_STATUS_IGNORE);
//
//        cout << "Procces = " << proc << " buf = ";
//
//        for (int i = 0; i < 12; ++i) {
//
//            cout << buf[i] << " ";
//
//        }
//
//    }
//
//    if (my_comm != MPI_COMM_NULL) MPI_Comm_free(&my_comm);
//
//    MPI_Finalize();
//    cout << endl;
//    return 0;
//}
