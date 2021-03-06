//#include <stdio.h>
//#include <mpi.h>
//
//int main(int argc, char* argv[]) {
//	int processId, size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//	printf("Hello world\n");
//	MPI_Finalize();
//
//	return 0;
//}

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
	int processId, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
	printf("Number of process - %d and total - %d", processId, size);
}