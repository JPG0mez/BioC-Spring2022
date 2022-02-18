CC = g++

vectorops.o: gomezj_vector_ops.cpp gomezj_vector_ops.hpp
	$(CC) -c $^ 


stats.o: gomezj_stats.cpp gomezj_stats.hpp gomezj_stats_test.cpp
	$(CC) -c $^

vectorops_exec: gomezj_vector_ops.o
	$(CC) -o $@ $^

stats_exec: gomezj_stats.o gomezj_stats_test.o
	$(CC) -o $@ $^

all: stats_exec vectorops_exec

clean:
	rm -f vectorops_exec
	rm -f stats_exec
	rm -f *.o
	rm -f *.gch