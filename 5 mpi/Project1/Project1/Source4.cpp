//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <omp.h> 
//#include <stdlib.h>
//#include <time.h>
//#include <vector>
//
//int main(int argc, char* argv[]) {
//	int processId, size;
//	srand(time(0));
//	int x[12];
//	int y[12];
//	const int a = 2;
//	const int b = 3;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//	MPI_Status status;
//
//	if (processId == 0) {
//		for (int i = 0; i < 12; i++) {
//			x[i] = rand() % 100;
//			y[i] = rand() % 100;
//		}
//		printf("Number of process - %d and total - %d\n", processId, size);
//		int block = 12 / size + 1;
//		int k = 0;
//		int* z = new int[block];
//		int* z2 = new int[block];
//		int* recvX = new int[block];
//		int* recvY = new int[block];
//		for (int i = 1; i < size; i++) {
//			int* newX = new int[block];
//			int* newY = new int[block];
//			for (int j = 0; j < block; j++) {
//				if (k <= 11) {
//					newX[j] = x[k];
//					newY[j] = y[k];
//					printf("x = %i and y = %i\n", newX[j], newY[j]);
//				}
//				else {
//					newX[j] = 0;
//					newY[j] = 0;
//				}
//				k++;
//			}
//			printf("\n");
//			MPI_Send(newX, block, MPI_INT, i, 1, MPI_COMM_WORLD);
//			MPI_Send(newY, block, MPI_INT, i, 1, MPI_COMM_WORLD);
//
//			MPI_Recv(z, block, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
//			MPI_Recv(z2, block, MPI_INT, MPI_ANY_SOURCE, 2, MPI_COMM_WORLD, &status);
//			MPI_Recv(recvX, block, MPI_INT, MPI_ANY_SOURCE, 3, MPI_COMM_WORLD, &status);
//			MPI_Recv(recvY, block, MPI_INT, MPI_ANY_SOURCE, 4, MPI_COMM_WORLD, &status);
//			for (int i = 0; i < block; i++) {
//					printf("z = %d\n", z[i]);
//					printf("z2 = %d\n", z2[i]);
//					printf("recvX = %d\n", recvX[i]);
//					printf("recvY = %d\n", recvY[i]);
//					printf("\n");
//				}
//			printf("\n");
//		}
//	}
//	if (processId != 0) {
//				int stat;
//				int count;
//				MPI_Probe(0, 1, MPI_COMM_WORLD, &status);
//				MPI_Get_count(&status, MPI_INT, &count);
//				int* x = new int[count];
//				int* y = new int[count];
//				int* z = new int[count];
//				int* z2 = new int[count];
//				int buf;
//				printf("Number of process - %d and total - %d\n", processId, size);
//				MPI_Recv(x, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
//				MPI_Recv(y, count, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
//				for (int i = 0; i < count; i++) {
//					z2[i] = x[i] * y[i];
//					z[i] = a * x[i] + b * y[i];
//					buf = x[i];
//					x[i] = y[i];
//					y[i] = buf;
//				}
//				MPI_Send(z, count, MPI_INT, 0, 1, MPI_COMM_WORLD);
//				MPI_Send(z2, count, MPI_INT, 0, 2, MPI_COMM_WORLD);
//				MPI_Send(x, count, MPI_INT, 0, 3, MPI_COMM_WORLD);
//				MPI_Send(y, count, MPI_INT, 0, 4, MPI_COMM_WORLD);
//			}
//		
//			MPI_Finalize();
//		
//			return 0;
//}