all: hello-cpp-world hello-c-world media teste

%: %.cc
	g++ -std=c++11 $< -o bin/$@

%: %.c
	gcc $< -o bin/$@

