all: z1 z2 z3 z4 z5

z1: zad1/permutacje.cpp zad4/kolejka.cpp
	g++ -Wall -pedantic zad1/permutacje.cpp zad4/kolejka.cpp -o z1

z2: zad2/lista.cpp
	g++ -Wall -pedantic zad2/lista.cpp -o z2

z3: zad3/kolejka.cpp
	g++ -Wall -pedantic zad3/kolejka.cpp -o z3

z4: zad4/main.cpp zad4/kolejka.cpp zad4/lista.cpp
	g++ -Wall -pedantic zad4/main.cpp zad4/kolejka.cpp zad4/lista.cpp -o z4

z5: zad5/main.cpp zad5/deque.cpp
	g++ -Wall -pedantic zad5/main.cpp zad5/deque.cpp -o z5

clean:
	rm -f z?
