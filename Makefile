all:
	g++ -std=c++11 main.cpp -o main -lncurses
install:
	cp main /usr/bin/cpp-ascii-maze
	chmod +x /usr/bin/cpp-ascii-maze
travis:
	g++ -std=c++11 main.cpp -o main -lncurses
	./main < test.txt
clean:
	rm main