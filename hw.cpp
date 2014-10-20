#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;


int main()
{
	string stringz;
while(1)
{
    cout << "$ ";
	getline(cin, stringz);
	if(stringz == "exit")
	exit(1);
	//cout << stringz << endl;
	char *str= new char[stringz.size()];
	strcpy(str, stringz.c_str());


	char *argv[100000];
	char *wordd;
	wordd = strtok(str, ";");
//	argv[0] = new char[stringz.size()];
	int num =0;
	while(wordd !=NULL)
	{
		argv[num] = new char[1000];
		strcpy(argv[num], wordd);
		num++;

		wordd = strtok(NULL, ";");
	}
	argv[num] = NULL;

	for(int i = 0; i < num;++i)
	{
		int pid = fork();
		if(pid == -1)
		{
			perror("HI I'M SPOON");
			exit(1);
		}
		else if(pid ==0)
		{
			if(strchr(argv[i], '|'))
			{
				char *pch = strchr(argv[i], '|');

				if((pch[1]=='|') && (pch[0]=='|'))
				{
					if(pch[3] == '|')
					{
						perror("Error, syntax error near |");
						exit(1);
					}
					char *argm[100000];
					char *moo;
					moo = strtok(argv[i], "|");
					int numer = 0;
					while (moo != NULL)
					{
						argm[numer] = new char[1000];
						strcpy(argm[numer], moo);
						numer++;
						moo = strtok(NULL, "|");
					}
					argm[numer] = NULL;
                    for(int i = 0; i < numer;i++ )
                    {
                        int pid = fork();
                        if(pid == -1)
                        {
                            perror("yes");
                            exit(1);
                        }
                        else if(pid == 0)
                        {

                            char *argtwelve[100000];
			             	char *moo;
				            moo =strtok(argm[i], " ");
				            int numberino = 0;
			            	while(moo != NULL)
			            	{
				       	        argtwelve[numberino] = new char[1000];
					            strcpy(argtwelve[numberino], moo);
                                cout << argtwelve[numberino] << endl;
					            numberino++;
				        	    moo = strtok(NULL, " ");
			            	}
				            if(execvp(argtwelve[0], argtwelve) == -1)
			            	{
                                if(i == numer-1)
                                {
					                perror("OMG WHY");
                                }
                                exit(1);

				            }
                            cout <<" banana " << endl;
				            exit(1);
                        }
                        else if(pid > 0)
                        {
                            int *yesss;

                            if(waitpid(-1, yesss, 0)==-1)
                            {
                                exit(1);
                            }
                            exit(1);
                        }
                    }

				}

			}
		//	if(strchr(argv[i], '&'))
		//	{
		//		char * pch =  strchr(argv[i], '&');
		//		cout << "hello" <<endl;
		//		if((pch[0]== '&') && ('&' == pch[1]))
		//		{
		//			if(pch == pch+2)
		//			{
		//				perror("ERROR");
		//				exit(1);
		//			}
		//			char *argtwelve[100000];
		//			char *moo;
		//			moo =strtok(argv[i], " &");
		//			int numberino = 0;
		//			while(moo != NULL)
		//			{
		//				argtwelve[numberino] = new char[1000];
		//				strcpy(argtwelve[numberino], moo);
		//				if(numberino % 2 == 0)
		//				{
		//					++numberino;
		//					argtwelve[numberino] = NULL;
		//				}
		//				cout << argtwelve[numberino] << numberino << endl;
		//				numberino++;
		//				moo = strtok(NULL, "& ");
		//			}
		//			argtwelve[numberino] = NULL;
		//			if(execvp(argtwelve[0], argtwelve) == -1)
		//			{
		//				perror("OMG WHY");
		//			}
		//			exit(1);
	//
	//			}
	//			else
	//			{
	//				perror("ERROR: REQUIRES && TO FUNCTION");
	//			}
	//			exit(1);
	//
	//		}
			else
			{
				char *argtwelve[100000];
				char *moo;
				moo =strtok(argv[i], " ");
				int numberino = 0;
				while(moo != NULL)
				{
					argtwelve[numberino] = new char[1000];
					strcpy(argtwelve[numberino], moo);
					numberino++;
					moo = strtok(NULL, " ");
				}
				if(execvp(argtwelve[0], argtwelve) == -1)
				{
					perror("OMG WHY");
				}
				exit(1);
			}
		}
		else if(pid >0)
		{
			if(-1 == wait(0))
			perror("ERROR WAITING");
		}



	}
}
	//int yes = execvp(

//	delete [] str;
//	for(int i = 0; i < 2;++i)
//	{
//		delete argv[i];
//	}
	return 0;
}
