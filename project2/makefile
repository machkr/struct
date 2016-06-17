CC=g++
CFLAGS=--std=c++11 -Wall

stackqueuemapdemo: stackqueuemapdemo.o main.cpp
	$(CC) $(CFLAGS) stackqueuemapdemo.o main.cpp -o stackqueuedemo

stackqueuemapdemo.o: menulist.o dynmap.o StackQueueMapDemo.h StackQueueMapDemo.cpp 
	$(CC) $(CFLAGS) menulist.o  dynmap.o StackQueueMapDemo.cpp -o stackqueuemapdemo.o

menulist.o: MenuList.cpp MenuList.h
	$(CC) $(CFLAGS) -c MenuList.cpp -o menulist.o

dynmap.o: DynMap.cpp DynMap.h linkedlist.o
	$(CC) $(CFLAGS) -c DynMap.cpp linkedlist.o -o dynmap.o

linkedlist.o: LinkedList.h 
	$(CC) $(CFLAGS) -c  LinkedList.h -o linkedlist.o
