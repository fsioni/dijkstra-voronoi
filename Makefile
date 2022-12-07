all : graphe_tests

graphe_tests : obj/graphe_tests.o obj/Graphe.o obj/MReadWrite.o
	g++ obj/graphe_tests.o obj/Graphe.o obj/MReadWrite.o -g -o graphe_tests.out

obj/graphe_tests.o : graphe_tests.cpp Graphe.h  
	g++ -Wall -g -c graphe_tests.cpp -o obj/graphe_tests.o

obj/Graphe.o : Graphe.cpp Graphe.h MReadWrite.h 
	g++ -Wall -g -c Graphe.cpp -o obj/Graphe.o

obj/MReadWrite.o : MReadWrite.cpp MReadWrite.h Graphe.h
	g++ -Wall -g -c MReadWrite.cpp -o obj/MReadWrite.o

clean :
	-rm obj/*.o

veryclean : clean
	-rm *.out
