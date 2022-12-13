all : bin/main_graphe.out bin/tests_graphe.out

bin/tests_graphe.out : obj/graphe_tests.o obj/Graphe.o obj/MReadWrite.o
	g++ -Wall -g -std=c++11 obj/graphe_tests.o obj/Graphe.o obj/MReadWrite.o -o bin/tests_graphe.out

bin/main_graphe.out : obj/graphe_main.o obj/Graphe.o obj/MReadWrite.o
	g++ -Wall -g -std=c++11 obj/graphe_main.o obj/Graphe.o obj/MReadWrite.o -o bin/main_graphe.out

obj/graphe_tests.o : src/graphe_tests.cpp src/Graphe.h  
	g++ -Wall -std=c++11 -g -c src/graphe_tests.cpp -o obj/graphe_tests.o

obj/graphe_main.o : src/graphe_main.cpp src/Graphe.h
	g++ -Wall -std=c++11 -g -c src/graphe_main.cpp -o obj/graphe_main.o

obj/Graphe.o :src/Graphe.cpp src/Graphe.h src/MReadWrite.h 
	g++ -Wall -std=c++11 -g -c src/Graphe.cpp -o obj/Graphe.o

obj/MReadWrite.o : src/MReadWrite.cpp src/MReadWrite.h src/Graphe.h
	g++ -Wall -std=c++11 -g -c src/MReadWrite.cpp -o obj/MReadWrite.o

clean :
	-rm obj/*.o

veryclean : clean
	-rm bin/*.out
