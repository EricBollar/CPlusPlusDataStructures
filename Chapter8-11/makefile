# the compiler we use, with correct version
CC = g++ -std=c++11
# -c means compile, -Wall shows warnings
CFLAGS = -c -Wall

all: connect4

CFourClass.o: CFourClass.cpp
	$(CC) $(CFLAGS) CFourClass.cpp

Operator.o: Operator.cpp
	$(CC) $(CFLAGS) Operator.cpp

ConnectFour.o: ConnectFour.cpp
	$(CC) $(CFLAGS) ConnectFour.cpp
 
connect4: CFourClass.o Operator.o ConnectFour.o 
	$(CC)  CFourClass.o Operator.o ConnectFour.o -o connect4

clean:
	rm *.o connect4