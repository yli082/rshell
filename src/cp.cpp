#include <iostream>
#include "Timer.h"
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]){
	bool all = false;
	bool fastest = false;
	if(argc < 3){
		cout << "cp: missing file operand" << endl;
        cout << "To copy using all methods use the -a flag, without flag copies using the fastest method" << endl;
		return 0;
	}
	if(argc ==  4){
		all = true;
	}
	else{
		fastest = true;
	}
	string path;
	string tmp;
	struct stat buf;
    int file1;
    int file2;
    if(all && argv[1][0] == '-'){
        if(argv[1][1] != 'a'){
            cerr << "Invalid flag" << endl;
            return 0;
        }
        file1 = 2;
        file2 = 3;
    }
    else if(all && argv[2][0] == '-'){
        if(argv[2][1] != 'a'){
            cerr << "Invalid lag" << endl;
            return 0;
        }
        file1 = 1;
        file2 = 3;
    }
    else if(all && argv[3][0] == '-'){
        if(argv[3][1] != 'a'){
            cerr << "Invalid flag" << endl;
            return 0;
        }
        file1 = 1;
        file2 = 2;
    }
    else{
        file1 = 1;
        file2 = 2;
    }
	if(argv[file1][0] != '.' && argv[file1][0] != '/' ){
		path = argv[file1];
		string tmp = "./";
		path = tmp + path;
		if(stat(path.c_str(), &buf) == -1){
			perror("stat");
			exit(0);
		}
		if(S_ISDIR(buf.st_mode)){
			cerr << "Input parameter is dir" << endl;
			exit(0);
		}
	}
	else{
		if(stat(argv[file1], &buf)){
			perror("stat");
			exit(0);
		}
		if(S_ISDIR(buf.st_mode)){
			cerr << "Input files if dir" << endl;
			exit(0);
		}
	}
	if(ifstream(argv[file2])){
        if(-1 == stat(argv[2], &buf)){
            perror("stat");
            exit(0);
        }
        if(S_ISDIR(buf.st_mode)){
            cerr << "Output parameter is dir" << endl;
            exit(0);
        }
        else{
    		cerr << "Output file already exists" << endl;
	    	exit(0);
        }
	}
	else{
		ofstream tmp(argv[file2]);
		if(!tmp.good()){
			cerr << "Unable to open file" << endl;
			return 0;
		}
		tmp.close();
	}
	if(argv[file2][0] != '.' && argv[file2][0] != '/'){
		path = argv[file2];
		tmp = "./";
		path = tmp + path;
		if(stat(path.c_str(), &buf) == -1){
			perror("stat");
			exit(0);
		}
		if(S_ISDIR(buf.st_mode)){
			cerr << "Output file is dir" << endl;
			exit(0);
		}
	}
	else{
		if(stat(argv[file2], &buf) == -1){
			perror("stat");
			exit(0);
		}
		if(S_ISDIR(buf.st_mode)){
			cerr << "Input file is dir" << endl;
			exit(0);
		}
	}

	if(all){
		Timer t;
		double eTime;
		t.start();
		ifstream in(argv[file1]);
		ofstream out(argv[file2]);
		if(!in.good() || !out.good()){
			cerr << "Unable to open file" << endl;
			return 0;
		}
		while(in.good()){
			char c = in.get();
			if(in.good()){
				out.put(c);
			}
		}
		cout << "Method 1: " << endl;
		t.elapsedUserTime(eTime);
		cout <<  "User time: " << eTime << endl;
		t.elapsedWallclockTime(eTime);
		cout << "Wall clock time: " << eTime << endl;
		t.elapsedSystemTime(eTime);
		cout << "System time: " << eTime << endl;
		in.close();
		out.close();
	}
	if(all){
		Timer t;
		double eTime;
		t.start();
		int infile = open(argv[file1], O_RDONLY);
		if(infile == -1){
			perror("open");
			exit(0);
		}
		int outfile = open(argv[file2], O_WRONLY);
		if(outfile == -1){
			perror("open");
			exit(0);
		}
		char buf[1];
		int n;
		while((n = read(infile, &buf, 1))){
			int w = write(outfile, &buf, 1);
			if(w == -1){
				perror("write");
				exit(0);
			}
		}
		if(n == -1){
			perror("read");
			exit(0);
		}
		cout << "Method 2: " << endl;
		t.elapsedUserTime(eTime);
		cout << "User time: " << eTime << endl;
		t.elapsedWallclockTime(eTime);
		cout << "Wall clock time: " << eTime << endl;
		t.elapsedSystemTime(eTime);
		cout << "System time: " << eTime << endl;
	}
	if(all || fastest){
		Timer t;
		double eTime;
		t.start();
		int infile = open(argv[file1], O_RDONLY);
		if(infile == -1){
			perror("open");
			exit(0);
		}
		int outfile = open(argv[file2], O_WRONLY);
		if(outfile == -1){
			perror("open");
			exit(0);
		}
		char buf[BUFSIZ];
		int n = read(infile, buf, BUFSIZ);
		if(n == -1){
			perror("read");
			exit(0);
		}
		int w = write(outfile, buf, BUFSIZ);
		if(w == -1){
			perror("write");
			exit(0);
		}
		cout << "Method 3: " << endl;
		t.elapsedUserTime(eTime);
		cout << "User time: " << eTime << endl;
		t.elapsedWallclockTime(eTime);
		cout << "Wall clock time: " << eTime << endl;
		t.elapsedSystemTime(eTime);
		cout << "System time: " << eTime << endl;
	}
	return 0;
}
