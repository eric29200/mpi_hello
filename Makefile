TARGET  := mpi_hello
CFLAGS  := -Wall -O2 
CC      := mpicc

mpi_hello: mpi_hello.o
	$(CC) $(CFLAGS) -o $@ $^

.o: .c 
	$(CC) $(CFLAGS) -c $^ 

clean :
	rm -f *.o $(TARGET)
