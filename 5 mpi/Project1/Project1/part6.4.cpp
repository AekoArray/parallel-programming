//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#define BUFF_SIZE 300
//
//using namespace std;
//
//
//int main(int argc, char* argv[]) {
//
//	int processId, size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &processId);
//
//	int position;
//	char buff[BUFF_SIZE];
//
//	int ints[10];
//	float doubles[8];
//
//	if (processId == 0) {
//
//		for (int i = 0; i < 10; i++) {
//			ints[i] = i;
//			if (i < 8) {
//				doubles[i] = double(i) / 2;
//			}
//		}
//
//		position = 0;
//		MPI_Pack(ints, 10, MPI_INT, buff, BUFF_SIZE, &position, MPI_COMM_WORLD);
//		MPI_Pack(doubles, 8, MPI_DOUBLE, buff, BUFF_SIZE, &position, MPI_COMM_WORLD);
//	}
//
//	position = 0;
//
//	MPI_Bcast(buff, 144, MPI_PACKED, 0, MPI_COMM_WORLD);
//
//	MPI_Unpack(buff, BUFF_SIZE, &position, ints, 10, MPI_INT, MPI_COMM_WORLD);
//	MPI_Unpack(buff, BUFF_SIZE, &position, doubles, 8, MPI_DOUBLE, MPI_COMM_WORLD);
//
//	        printf("Process = %i\n", processId);
//        printf("integers: \n");
//        for (int i = 0; i < 10; i++) {
//            printf("%i ", ints[i]);
//        }
//        printf("\ndoubles: \n");
//        for (int i = 0; i < 8; i++) {
//            printf("%lg ", doubles[i]);
//        }
//
//	MPI_Finalize();
//
//	return 0;
//
//}