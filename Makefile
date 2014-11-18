

all:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -Wall -Werror -ansi -pedantic src/hw.cpp -o bin/rshell
	g++ -Wall -Werror -ansi -pedantic src/cp.cpp -o bin/cp
	g++ -Wall -Werror -ansi -pedantic src/ls.cpp -o bin/ls
rshell:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -g -Wall -Werror -ansi -pedantic src/hw.cpp -o bin/rshell
cp:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -Wall -Werror -ansi -pedantic src/cp.cpp -o bin/cp
ls:
	if [ ! -d "./bin" ];\
	then mkdir bin;\
	fi
	g++ -Wall -Werror -ansi -pedantic src/ls.cpp -g -o bin/ls

