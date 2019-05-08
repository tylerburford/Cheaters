plagiarismCatcher: main.o helper.o hasher.o
	g++ -std=c++0x -o plagiarismCatcher main.o helper.o hasher.o
main.o: main.cpp helper.h hasher.h
	g++ -std=c++0x main.cpp
helper.o: helper.cpp helper.h hasher.h
	g++ -std=c++0x helper.cpp
hasher.o: hasher.cpp hasher.h
	g++ -std=c++0x hasher.cpp