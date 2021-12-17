brainfuck: interpreter.cpp main.cpp
	g++ -std=c++11 -o bin/brainfuck interpreter.cpp main.cpp

clean:
	rm -r bin/*