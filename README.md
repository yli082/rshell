rshell
======

Licensing information: READ LICENSE
------
Project source can be downloaded from https://github.com/yli082/rshell.git
-----
Mike Izbicki

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
Exit sometimes doesn't work. Tested this with rshell running multiple rshells.

Used valgrind to check for memory leaks. 1 Possibly lost block.

When chaining nonexistant or commands, will output one extra error.

& works as if && was entered, and | works as if || was entered

If more than 10000 characters entered, will memory leak




```
