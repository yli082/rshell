rshell
======

------
Project source can be downloaded from https://github.com/yli082/rshell.git
-----

Ying Li

All other known bugs and fixes can and should be sent to yl082@ucr.edu

Reported bugs/fixes will be submitted to correction

File List
======
```
.:

Makefile

README.md

LICENSE

./src

./tests

```
```
./src:

ls.cpp

cp.cpp

timer.h

hw.cpp
```
```

./tests:

exec.scrip

```
====
BUGS
====
```

hw0:

Exit sometimes doesn't work. Tested this with rshell running multiple rshells.

Used valgrind to check for memory leaks. 1 Possibly lost block.

When chaining nonexistant or commands, will output one extra error.

& works as if && was entered, and | works as if || was entered

If more than 10000 characters entered, will memory leak

Single commands such as |, &, ; will output an error, which will say success

Random memory corruption


hw1:

Output for ls doesn't output exactly like how normal ls does

-l not formatted nicely when numbers get too big

bin/ls file dir file will print file than print dir than file, rather than print both files before dir

```
