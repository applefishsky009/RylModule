build : main.o #list.o tree.o
	g++ -std=c++0x -o build main.o #list.o tree.o	
main.o : main.cpp
	g++ -std=c++0x -g -c main.cpp
#list.o : list.h list.cpp
	#g++ -std=c++0x -g -c list.cpp
#tree.o : tree.h tree.cpp
	#g++ -std=c++0x -g -c tree.cpp
clean :
	rm main.o build #list.o tree.o 