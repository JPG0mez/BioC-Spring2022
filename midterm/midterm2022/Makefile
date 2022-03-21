CC = g++


MoarComplicated.o: MoarComplicated/mowin.cpp MoarComplicated/mowin.hpp MoarComplicated/seememow.cpp MoarComplicated/thehob.cpp MoarComplicated/thehob.hpp MoarComplicated/tthti.cpp
	$(CC) -c $^

MoarComplicated_exec: MoarComplicated/mowin.o MoarComplicated/seememow.o MoarComplicated/thehob.o
	$(CC) -o $@ $^


Multimain.o: Multimain/brennanb_corr.cpp Multimain/brennanb_corr.hpp Multimain/brennanb_stats.cpp Multimain/brennanb_stats.hpp
	$(CC) -c $^

Multimain_exec: Multimain/brennanb_corr.o Multimain/brennanb_stats.o
	$(CC) -o $@ $^


Simple.o: Simple/brennanb_corr.cpp Simple/brennanb_corr.hpp Simple/brennanb_stats.cpp Simple/brennanb_stats.hpp
	$(CC) -c $^

Simple_exec: Simple/brennanb_corr.o Simple/brennanb_stats.o
	$(CC) -o $@ $^


Straightforward.o: Straightforward/dandelion.cpp Straightforward/toss_a_coin.cpp Straightforward/toss_a_coin.hpp Straightforward/valley_of_plenty.cpp Straightforward/valley_of_plenty.hpp Straightforward/wolf.cpp Straightforward/wolf.hpp
	$(CC) -c $^

Straightforward_exec: Straightforward/dandelion.o Straightforward/toss_a_coin.o Straightforward/valley_of_plenty.o Straightforward/wolf.o
	$(CC) -o $@ $^

all: MoarComplicated_exec Multimain_exec Simple_exec Straightforward_exec

clean:
	rm -f MoarComplicated/*.o
	rm -f MoarComplicated/*.gch
	rm -f MoarComplicated_exec
	rm -f Multimain/*.o
	rm -f Multimain/*.gch
	rm -f Multimain_exec
	rm -f Simple/*.o
	rm -f Simple/*.gch
	rm -f Simple_exec
	rm -f Straightforward/*.o
	rm -f Straightforward/*.gch
	rm -f Straightforward_exec
