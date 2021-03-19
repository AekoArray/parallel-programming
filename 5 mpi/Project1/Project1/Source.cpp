//#include <stdio.h>
//#include <mpi.h>
//
//int main(int argc, char* argv[]) {
//	int processId, size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//  printf("Number of process - %d and total - %d\n", processId, size);
//	printf("Hello world\n");
//	MPI_Finalize();
//
//	return 0;
//}

//#include <stdio.h>
//#include <mpi.h>
//
//int main(int argc, char* argv[]) {
//	int processId, size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//	printf("Number of process - %d and total - %d", processId, size);
//	MPI_Finalize();
//
//	return 0;
//}

//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <omp.h> 
//#include <stdlib.h>
//#include <time.h>
//
//int main(int argc, char* argv[]) {
//	int processId, size;
//	srand(time(0));
//	int arr[10];
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//	MPI_Status status;
//
//	if (processId == 0) {
//		for (int i = 0; i < 10; i++) {
//			arr[i] = rand() % 100;
//		}
//		printf("Number of process - %d and total - %d", processId, size);
//		MPI_Send(arr, 10, MPI_INT, 1, 1, MPI_COMM_WORLD);
//	}
//	if (processId == 1) {
//		int stat;
//		printf("Number of process - %d and total - %d\n", processId, size);
//		MPI_Recv(arr,10 , MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
//		for (int i = 0; i < 10; i++) {
//			printf("%d\n", arr[i]);
//		}
//	}
//	
//	MPI_Finalize();
//
//	return 0;
//}