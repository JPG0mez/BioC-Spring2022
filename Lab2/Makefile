CC = g++

preprocessing.o: gomezj_pre_processing.cpp gomezj_pre_processing.hpp
	$(CC) -c $^ 

cluster.o: gomezj_k_means.cpp gomezj_k_means.hpp
	$(CC) -c $^ 

vectorops.o: gomezj_vector_ops.cpp gomezj_vector_ops.hpp
	$(CC) -c $^ 

stats.o: gomezj_stats.cpp gomezj_stats.hpp gomezj_stats_test.cpp
	$(CC) -c $^

vectorops_exec: gomezj_vector_ops.o
	$(CC) -o $@ $^

stats_exec: gomezj_stats.o gomezj_stats_test.o
	$(CC) -o $@ $^

preprocessing_exec: gomezj_pre_processing.o gomezj_vector_ops.o
	$(CC) -o $@ $^ 

cluster_exec: gomezj_k_means.o gomezj_stats.o
	$(CC) -o $@ $^ 

all: stats_exec preprocessing_exec cluster_exec 

clean:
	rm -f cluster_exec
	rm -f preprocessing_exec
	rm -f vectorops_exec
	rm -f stats_exec
	rm -f *.o
	rm -f *.gch