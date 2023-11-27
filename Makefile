sequential: sequential.c
	gcc -o sequential sequential.c -Wall -fopenmp

parallel: parallel.c
	gcc -o parallel parallel.c -Wall -fopenmp
