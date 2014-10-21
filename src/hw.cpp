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

void foroopsies(char *c[10000])
{
	for(int i = 0; c[i] != 0;++i)
	{
		delete c[i];
	}

}
int main()
{
	string stringz;


while(1)
{	
	char *host = new char[256];
	gethostname(host, 256);
	cout << getlogin() << '@' << host<< "$ ";
	delete [] host;
	getline(cin, stringz);
	if(stringz == "exit")
	exit(1);
	//cout << stringz << endl;
	char *str= new char[stringz.size()];
	strcpy(str, stringz.c_str());
	char *str2 = new char[stringz.size()];
	strcpy(str2, stringz.c_str());
	char *test = strtok(str2, ";&|");
	for(unsigned int i = 0; i < stringz.size();++i)
	{
		if(str[i] == '#')
		{
			str[i] = '\0';
			break;
		}
	
	}
	if(test == NULL)
	{
		perror("ERROR");
	}
	else
{
	delete [] str2;
	char *argv[10000];
	char *wordd;
	wordd = strtok(str, ";");
//	argv[0] = new char[stringz.size()];
	int num =0;
	while(wordd !=NULL)
	{
		argv[num] = new char[10000];
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
					if(pch[2] == '|' )
					{
						perror("Error, syntax error near |");

						exit(1);
					}
					char *argm[10000];
					char *moo;
					moo = strtok(argv[i], "|");
					int numer = 0;
					while (moo != NULL)
					{
						argm[numer] = new char[10000];
						strcpy(argm[numer], moo);
						numer++;
						moo = strtok(NULL, "|");
					}
                    int nu;
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

                            char *argtwelve[10000];
			             	char *moo;
				            moo =strtok(argm[i], " ");
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
                                if(i == numer-1)
                                {
					                perror("ERROR");
                                }
								foroopsies(argtwelve);
                                exit(1);

				            }
				            exit(1);
                        }
                        else if(pid > 0)
                        {

                            waitpid(-1, &nu, 0);
                            if(nu!= 0 )
                            {
                                continue;

                            }
                            exit(1);

                        }
                    }
					foroopsies(argm);
				}

			}
			if(strchr(argv[i], '&'))
		   	{
			    char *pch = strchr(argv[i], '&');
			    if((pch[1]=='&') && (pch[0]='&'))
				{
				    if(pch[2] == '&' )
				    {
					    perror("Error, syntax error near &");
					    exit(1);
				    }
				    char *argm[10000];
				    char *moo;
				    moo = strtok(argv[i], "&");
				    int numer = 0;
				    while (moo != NULL)
			    	{
				    	argm[numer] = new char[10000];
					    strcpy(argm[numer], moo);
					    numer++;
					    moo = strtok(NULL, "&");
			    	}
                       int nu;
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
                               char *argtwelve[10000];
			             	   char *moo;
				               moo =strtok(argm[i], " ");
				               int numberino = 0;
			            	   while(moo != NULL)
			            	   {
				       	           argtwelve[numberino] = new char[10000];
					               strcpy(argtwelve[numberino], moo);
					               numberino++;
				        	       moo = strtok(NULL, " ");
			            	   }
				               if(execvp(argtwelve[0], argtwelve) == -1)
			            	   {

					                   perror("ERROR");

									foroopsies(argtwelve);
                                   exit(1);

				            }
				              exit(1);
                        }
                        else if(pid > 0)
                        {

                            waitpid(-1, &nu, 0);
                            if(nu!= 0 )
                            {
                                break;
                                exit(1);
                            }

                        }
                    }
				foroopsies(argm);
				}




			}
			else
			{
				char *argtwelve[10000];
				char *moo;
				moo =strtok(argv[i], " ");
				int numberino = 0;
				while(moo != NULL)
				{
					argtwelve[numberino] = new char[10000];
					strcpy(argtwelve[numberino], moo);
					numberino++;
					moo = strtok(NULL, " ");
				}
				if(execvp(argtwelve[0], argtwelve) == -1)
				{
					perror("ERROR");
				}
				foroopsies(argtwelve);
				exit(1);
			}
		}
		else if(pid >0)
		{
			if(-1 == wait(0))
			perror("ERROR WAITING");
		}


}
foroopsies(argv);
	}
delete [] str;
}
	//int yes = execvp(

//	delete [] str;
//	for(int i = 0; i < 2;++i)
//	{
//		delete argv[i];
//	}
	return 0;
}
