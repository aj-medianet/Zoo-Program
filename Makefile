
output: main.o Animal.o Penguin.o Tiger.o Turtle.o Zoo.o
	g++ main.o Animal.o Penguin.o Tiger.o Turtle.o Zoo.o -o output

main.o: main.cpp
	g++ -c main.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -c Animal.cpp	

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -c Penguin.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -c Tiger.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -c Turtle.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -c Zoo.cpp

clean:
	rm *.o output
