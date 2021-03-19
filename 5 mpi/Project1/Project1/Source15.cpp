//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include <chrono>
//
//
////task5_3
//using namespace std;
//
//int main(int args, char** argvs) {
//    srand(time(0));
//    int numOfProcess, rank, root = 0;
//    int global[4];
//    int globalSum = 0;
//    int localRandomNum;
//    MPI_Init(&args, &argvs);
//    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcess);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Status status;
//    for (int i = 0; i < 4; i++)
//        global[i] = rand() % 100;
//    if (rank == root)
//    {
//        cout << "array: \n";
//        for (int i = 0; i < 4; i++)
//            cout << global[i] << " ";
//        cout << "\n";
//    }
//    localRandomNum = global[rank];
//    cout << "Process: " << rank << " and number = " << localRandomNum << "\n";
//    auto time1 = std::chrono::high_resolution_clock::now();
//    MPI_Reduce(&localRandomNum, &globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//    MPI_Bcast(&globalSum, 1, MPI_INT, root, MPI_COMM_WORLD);
//    cout << "Process: " << rank << " and sum = " << globalSum << "\n";
//    auto time2 = std::chrono::high_resolution_clock::now();
//    printf("Time reduce and bcast= %i;\n" , std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count());
//    MPI_Finalize();
//    return 0;
//}