counter:: main.o counter.o
	g++ main.o counter.o -o counter
	clear
main.o:: main.cc counter.h
	g++ -c main.cc
counter.o:: counter.cc counter.h
	g++ -c counter.cc
clean:
	rm *.o
