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
	/*int i= 0;
	for(; c[i] != 0;++i)
	{
		delete c[i];
	}
	delete c[i];
*/
}
int main()
{


while(1)
{

	string stringz;
	char *host = new char[256];
	gethostname(host, 256);
	cout << getlogin() << '@' << host<< "$ ";
	delete [] host;

	getline(cin, stringz);
	if(stringz == "exit")
    return 0;
	//cout << stringz << endl;
	char *str= new char[stringz.size()+1];
	strcpy(str, stringz.c_str());
	char *str2 = new char[stringz.size()+1];
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
        delete [] str;
        delete [] str2;
		cerr << ("Error");
        exit(1);
	}
	else
    {
        delete [] str2;
	char **argv = new char*[stringz.size()+1];
    char **curargv = argv;
	char *wordd;
	wordd = strtok(str, ";");
	int num =0;
	while(wordd !=NULL)
	{
        argv[num] = wordd;
		num++;

		wordd = strtok(NULL, ";");
	}
    argv = curargv;
	argv[num] = NULL;
	for(int i = 0; i < num;++i)
	{
			if(strchr(argv[i], '|'))
			{

				char *pch = strchr(argv[i], '|');

				if((pch[1]=='|') && (pch[0]=='|'))
				{
					if(pch[2] == '|' )
					{
						cerr << ("Error, syntax error near |");

						exit(1);
					}
                    string forsizea = argv[i];
					char **argm = new char*[forsizea.size()+1];
                    char **cats = argm;
					char *moo;
					moo = strtok(argv[i], "|");
					int numer = 0;
					while (moo != NULL)
					{
                        argm[numer] = moo;
						numer++;
						moo = strtok(NULL, "|");
					}
                    int nu;
					argm[numer] = NULL;
                    for(int i = 0; i < numer;i++ )
                    {

                            string argmsize = argm[i];
                            char **argtwelve = new char*[argmsize.size()+1];
			             	char *moo;
				            moo =strtok(argm[i], " ");
				            int numberino = 0;
			            	while(moo != NULL)
			            	{
                                string exitcomp = moo;
                                if(exitcomp == "exit")
                                {
                                    exit(0);
                                }
                                argtwelve[numberino] = moo;
					            numberino++;
				        	    moo = strtok(NULL, " ");
			            	}
					argtwelve[numberino] = NULL;
                        int pid = fork();
                        if(pid == -1)
                        {
                            perror("yes");
                            exit(1);
                        }
                        else if(pid == 0)
                        {
				            if(execvp(argtwelve[0], argtwelve) == -1)
			            	{
					                perror("erRROr");
                                exit(1);

				            }
                        }
                        else if(pid > 0)
                        {

                            if(waitpid(-1, &nu, 0)==-1)
                            {
                                perror("Error |");
                                exit(1);
                            }
                            if(nu!= 0 )
                            {
                                continue;

                            }


                        }
                        break;
                    }
                    argm = cats;
                    delete [] argm;
				}

			}
			else if(strchr(argv[i], '&'))
		   	{
			    char *pch = strchr(argv[i], '&');
			    if((pch[1]=='&') && (pch[0]='&'))
				{
				    if(pch[2] == '&' )
				    {
					    cerr << ("Error, syntax error near &");
					    exit(1);
				    }
                    string asize = argv[i];
				    char **argm = new char*[asize.size()+1];
                    char **cats = argm;
				    char *moo;
				    moo = strtok(argv[i], "&");
				    int numer = 0;
				    while (moo != NULL)
			    	{
                        argm[numer] = moo;
					    numer++;
					    moo = strtok(NULL, "&");
			    	}
                       int nu;
			    	argm[numer] = NULL;
                       for(int i = 0; i < numer;i++ )
                       {

                               string america = argm[i];
                               char **argtwelve=new char*[america.size()+1];
			             	   char *moo;
				               moo =strtok(argm[i], " ");
				               int numberino = 0;
			            	   while(moo != NULL)
			            	   {
                                   string asd = moo;
                                   if(asd == "exit")
                                       exit(0);
                                   argtwelve[numberino] = moo;
					               numberino++;
				        	       moo = strtok(NULL, " ");
			            	   }
				        		argtwelve[numberino] = NULL;
                            int pid = fork();
                           if(pid == -1)
                           {
                               perror("yes");
                               exit(1);
                           }
                           else if(pid == 0)
                           {
				               if(execvp(argtwelve[0], argtwelve) == -1)
			            	   {

					                   perror("ERROR");

                                   exit(1);

				            }
				              exit(1);
                        }
                        else if(pid > 0)
                        {

                            if(waitpid(-1, &nu, 0) == -1)
                            {
                                perror("error");
                                exit(1);
                            }
                            if(nu!= 0 )
                            {
                                break;
                                exit(1);
                            }

                        }
                    }

                    argm = cats;
                    delete [] argm;
				}



			}
			else
			{
        	int pid = fork();
		if(pid == -1)
		{
			perror("HI I'M SPOON");
			exit(1);
		}
		else if(pid ==0)
		{
                string flabs = argv[i];
				char **argtwelve= new char*[flabs.size()+1];
                char **cats = argtwelve;
				char *moo;
				moo =strtok(argv[i], " ");
				int numberino = 0;
				while(moo != NULL)
				{
                    argtwelve[numberino] = moo;
					numberino++;
					moo = strtok(NULL, " ");
				}
				argtwelve[numberino] = NULL;
                argtwelve = cats;
				if(execvp(argtwelve[0], argtwelve) == -1)
				{
					perror("ERRROR");
				}
				foroopsies(argtwelve);
				exit(1);
			}

		else if(pid >0)
		{
			if(-1 == wait(0))
			perror("ERROR WAITING");
		}
}

	}
    argv = curargv;
        delete  [] argv;
        delete [] str;

}
	//int yes = execvp(

//	delete [] str;
//	for(int i = 0; i < 2;++i)
//	{
//		delete argv[i];
//	}

}

	return 0;
}
