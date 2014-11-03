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
		cerr << "Not enough arguments" << endl;
		return 0;
	}
	if(argc ==  4){
		all = true;
	}
	else{
		fastest = true;
	}
	struct stat buf;
	string path = argv[1];
	string tmp = "./";
	path = tmp + path;
	if(stat(path.c_str(), &buf) == -1){
		perror("stat");
		exit(0);
	}
	if(S_ISDIR(buf.st_mode)){
		cerr << "Input file is dir" << endl;
		exit(0);
	}
	path = argv[2];
	tmp = "./";
	path = tmp + path;
	if(stat(path.c_str(), &buf) == -1){
		perror("stat");
		exit(0);
	}
	if(S_ISDIR(buf.st_mode)){
		cerr << "Input file is dir" << endl;
		exit(0);
	}
	if(ifstream(argv[2])){
		cerr << "Output file already exists" << endl;
		return 0;
	}
	else{
		ofstream tmp(argv[2]);
		if(!tmp.good()){
			cerr << "Unable to open file" << endl;
			return 0;
		}
		tmp.close();
	}
	if(all){
		Timer t;
		double eTime;
		t.start();
		ifstream in(argv[1]);	
		ofstream out(argv[2]);
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
		int infile = open(argv[1], O_RDONLY);
		if(infile == -1){
			perror("open");
			exit(0);
		}
		int outfile = open(argv[2], O_WRONLY);
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
		int infile = open(argv[1], O_RDONLY);
		if(infile == -1){
			perror("open");
			exit(0);
		}
		int outfile = open(argv[2], O_WRONLY);
		if(outfile == -1){
			perror("open");
			exit(0);
		}
		char* buf = new char[BUFSIZ];
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
		delete[] buf;
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
