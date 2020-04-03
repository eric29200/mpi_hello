#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	int world_size;
	int world_rank;
	int number;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	if (world_rank == 0) {
		number = -1;
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else if (world_rank == 1) {
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
			 MPI_STATUS_IGNORE);
		printf("Process 1 received number %d from process 0\n",
		       number);
	}

	return 0;
}
