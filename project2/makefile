CC=g++
CFLAGS=--std=c++11 -Wall

stackqueuemapdemo: stackqueuemapdemo.o main.cpp menulist.o  dynmap.o
	$(CC) $(CFLAGS) menulist.o  dynmap.o stackqueuemapdemo.o main.cpp -o stackqueuedemo

stackqueuemapdemo.o: StackQueueMapDemo.h StackQueueMapDemo.cpp 
	$(CC) $(CFLAGS) -c  StackQueueMapDemo.cpp -o stackqueuemapdemo.o

menulist.o: MenuList.cpp MenuList.h
	$(CC) $(CFLAGS) -c MenuList.cpp -o menulist.o

dynmap.o: DynMap.cpp DynMap.h 
	$(CC) $(CFLAGS) -c DynMap.cpp -o dynmap.o
