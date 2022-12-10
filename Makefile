all : bin/main_graphe bin/tests_graphe 

bin/tests_graphe : obj/graphe_tests.o obj/Graphe.o obj/MReadWrite.o
	g++ -Wall -g -std=c++11 obj/graphe_tests.o obj/Graphe.o obj/MReadWrite.o -o bin/tests_graphe.out

bin/main_graphe : obj/graphe_main.o obj/Graphe.o obj/MReadWrite.o
	g++ -Wall -g -std=c++11 obj/graphe_main.o obj/Graphe.o obj/MReadWrite.o -o bin/main_graphe.out

obj/graphe_tests.o : graphe_tests.cpp Graphe.h  
	g++ -Wall -std=c++11 -g -c graphe_tests.cpp -o obj/graphe_tests.o

obj/graphe_main.o : graphe_main.cpp Graphe.h
	g++ -Wall -std=c++11 -g -c graphe_main.cpp -o obj/graphe_main.o

obj/Graphe.o : Graphe.cpp Graphe.h MReadWrite.h 
	g++ -Wall -std=c++11 -g -c Graphe.cpp -o obj/Graphe.o

obj/MReadWrite.o : MReadWrite.cpp MReadWrite.h Graphe.h
	g++ -Wall -std=c++11 -g -c MReadWrite.cpp -o obj/MReadWrite.o

clean :
	-rm obj/*.o

veryclean : clean
	-rm bin/*.out
