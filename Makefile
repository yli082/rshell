

all:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -Wall -Werror -ansi -pedantic src/hw.cpp -o bin/rshell
	g++ -Wall -Werror -ansi -pedantic src/cp.cpp -o bin/cp

rshell:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -Wall -Werror -ansi -pedantic src/hw.cpp -o bin/rshell
cp:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -Wall -Werror -ansi -pedantic src/cp.cpp -o bin/cp

