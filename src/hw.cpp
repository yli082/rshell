#include <iostream>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
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
        int prevfd = open("/dev/null", O_RDONLY);
        if(prevfd < 0)
        {
            perror("Error");
            exit(1);
        }
        string command = argv[i];
        if(command.find("<") != string::npos || command.find(">")
            != string::npos|| command.find(">>")!= string::npos ||
            ((command.find("|")!= string::npos) &&(command.find("|")+1 != string::npos)))

        {
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
				argm[numer] = NULL;

                char** argtwelve;
                //int savestdout = dup(1);
                //int savestdin = dup(0);
                         for(int i = 0; i < numer;++i)
            {
                 int fd[2];
                if(pipe(fd)==-1)
                {
                    perror("Error with pipe");
                    exit(1);
                }
                string newcommand = argm[i];
                if(newcommand.find("<") != string::npos || newcommand.find(">")
            != string::npos|| newcommand.find(">>")!= string::npos)
                {



                int iput = 0;
                int oput = 0;
                int outorin = 0;
                int appendflag = 0;
                int ecinput = 0;
                string check = argm[i];
                if(check.find(">>")!= string::npos)
                {
                    appendflag = 1;
                }
                if(check.find("<<<")!= string::npos)
                    ecinput = 1;
                string inputfile = "";
                string outputfile = "";
                for(unsigned int x = 0; x < check.size();++x)
                {
                    if(argm[i][x] == '<')
                    {
                        if(outorin == 0)
                        {
                            outorin = 1;
                        }

                        ++iput;
                    }
                    if(argm[i][x] == '>')
                    {
                       if(outorin == 0)
                       outorin = 2;
                        ++oput;
                    }
                }
                    if(iput > 1)
                    {
                        if((iput == 3)&& ecinput)
                        {
                        }
                        else
                        {
                        cerr << "Error: Too many inputs" << endl;
                        exit(1);
                        }
                    }
                    if(oput > 1)
                    {
                        if(appendflag == 0)
                        {
                             cerr <<"Error: Too many outputs" << endl;
                            exit(1);
                        }
                        if(appendflag == 1)
                        {
                            if(oput > 2)
                            {
                                cerr << "Error: Too many outputs" << endl;
                                exit(1);
                            }
                        }

                    }


            //         for(int i = 0; i < numer;i++ )

                            string argmsize = argm[i];
                            char **argtwelve = new char*[argmsize.size()+1];
			             	char *moo;
				            moo =strtok(argm[i], " <>\"");
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
				        	    moo = strtok(NULL, " <>\"");
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
                 int fdi = 0;
                 int fdo = 0;
                 if(ecinput);
                 else if(iput+oput == 1|| (appendflag && oput+iput == 2))

                 {
                     if(iput == 1)
                     {
                         fdi = open(argtwelve[numberino -1], O_RDONLY);
                         if(fdi == -1)
                         {
                             perror("Error line 194");
                             exit(1);
                         }
                             if(-1==close(0))
                        {
                            perror("Error");
                            exit(1);
                        }
                             if(-1==dup(fdi))
                            {
                            perror("Error");
                            exit(1);
                        }
                         argtwelve[numberino-1] = NULL;
                     }
                     if(oput == 1 || oput == 2)
                     {
                         int flagec = 0;
                         int numwewant = numberino-1;
                         int cherker = atoi(argtwelve[numwewant-1]);
                         if(isdigit(argtwelve[numwewant-1][0]))
                         {
                             numwewant = numwewant-1;
                             argtwelve[numwewant] = NULL;
                             flagec =1 ;
                            if(-1== close(cherker)){
                            perror("Error");
                            exit(1);
                        }
                         }
                         if(appendflag==1)
                         {
                             fdo = open(argtwelve[numberino-1], O_RDWR|O_CREAT|O_APPEND, 00700);
                             if(fdo == -1){
                            perror("Error");
                            exit(1);
                        }
                             if(flagec);
                             else{
                                 if(-1==close(1)){
                            perror("Error");
                            exit(1);
                                 }
                        }
                         }
                         else{
                            fdo = open(argtwelve[numberino-1], O_RDWR|O_CREAT|O_TRUNC,00700);
                            if(fdo ==-1){
                            perror("Error");
                            exit(1);
                        }
                            if(flagec);
                            else{
                                if(-1==close(1)){
                            perror("Error");
                            exit(1);
                        }
                            }
                         }
                            if(-1==dup(fdo)){
                            perror("Error");
                            exit(1);
                            }



                         argtwelve[numberino-1] = NULL;

                     }
                 }
                 else if(outorin == 1)
                 {
                    fdi = open(argtwelve[numberino -2], O_RDWR);
                    if(fdi == -1)
                    {
                        perror("Open");
                        exit(1);
                    }
                    if(-1==close(0)){
                            perror("Error");
                            exit(1);
                    }
                    if(-1==dup(fdi)){
                            perror("Error");
                            exit(1);
                    }
                         int flagec = 0;
                         int numwewant = numberino-1;
                         int cherker = atoi(argtwelve[numwewant-1]);
                         if(isdigit(argtwelve[numwewant-1][0]))
                         {
                             numwewant = numwewant-1;
                             argtwelve[numwewant] = NULL;
                             flagec =1 ;
                             if(-1==close(cherker)){
                            perror("Error");
                            exit(1);
                    }
                         }

                    if(appendflag)
                    {
                        fdo = open(argtwelve[numberino -1], O_RDWR|O_CREAT|O_APPEND, 00700);
                        if(fdo == -1){
                            perror("Error");
                            exit(1);
                    }
                        if(flagec);
                        else{
                           if(-1== close(1)){
                            perror("Error");
                            exit(1);
                    }
                        }
                    }
                    else{
                        fdo = open(argtwelve[numberino-1], O_RDWR|O_CREAT|O_TRUNC, 00700);
                        if(fdo == -1){
                            perror("Error");
                            exit(1);
                    }

                        if(flagec);
                        else{
                            if(-1==close(1)){
                            perror("Error");
                            exit(1);
                    }
                        }
                        }
                            if(-1==dup(fdo)){
                            perror("Error");
                            exit(1);
                    }

                        argtwelve[numberino-2] = NULL;
                        argtwelve[numberino-1] = NULL;
                 }
                 else if(outorin == 2)
                 {
                    fdi = open(argtwelve[numberino-1], O_RDWR);
                    if(fdi == -1)
                    {
                        perror("Open");
                        exit(1);
                    }
                    if(-1==close(0)){
                            perror("Error");
                            exit(1);
                    }
                    if(-1==dup(fdi)){
                            perror("Error");
                            exit(1);
                    }
                         int flagec = 0;
                         int numwewant = numberino-2;
                         int cherker = atoi(argtwelve[numwewant-1]);
                         if(isdigit(argtwelve[numwewant-1][0]))
                         {
                             numwewant = numwewant-1;
                             argtwelve[numwewant] = NULL;
                             flagec =1 ;
                             if(-1==close(cherker)){
                            perror("Error");
                            exit(1);
                    }
                         }

                    if(appendflag)
                    {
                        fdo = open(argtwelve[numberino -2], O_RDWR|O_CREAT|O_APPEND, 00700);
                        if(flagec);
                        else{
                           if(-1== close(1)){
                            perror("Error");
                            exit(1);
                    }
                        }
                    }
                    else{
                        fdo = open(argtwelve[numberino -2], O_RDWR|O_CREAT|O_TRUNC, 00700);
                        if(flagec);
                        else{
                           if(-1== close(1)){
                            perror("Error");
                            exit(1);
                    }
                        }
                    }
                           if(-1 ==  close(1)){
                            perror("Error");
                            exit(1);
                    }
                            if(-1==dup(fdo)){
                            perror("Error");
                            exit(1);
                    }


                        argtwelve[numberino -2] = NULL;
                        argtwelve[numberino -1] = NULL;
                    }






                 if(numer > 1)
                 {
                     if(i != 0)
                     {
                         dup2(prevfd, 0);
                         close(prevfd);
                     }
                     else
                     {
                     dup2(fd[1], 1);
                     close(prevfd);
                     prevfd = dup(fd[2]);
                     }
                     close(fd[0]);
                     close(fd[1]);
                 }
                 if(ecinput)
                 {
                for(int z = 1; z < numberino; ++z)
                             {
                                 cout << argtwelve[z] << ' ';

                             }
                             cout << endl;

                     exit(1);
                 }
                 if(execvp(argtwelve[0], argtwelve) == -1)
                 {
                     perror("erRROr");
                     exit(1);

                 }
              }
              else if(pid > 0)
              {
                  close(prevfd);
                        prevfd = fd[0];
                        close(fd[1]);

               }





            }

        else{

                            string argmsize = argm[i];
                            argtwelve = new char*[argmsize.size()+1];
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
                            perror("error");
                            exit(1);
                        }
                        else if(pid == 0)
                        {
                            if(i==0);
                            else
                                dup2(prevfd, 0);
                            close(prevfd);
                            if(i!= numer-1)
                            {
                                dup2(fd[1], 1);
                                close(fd[0]);
                                close(fd[1]);
                            }
                            if(-1==execvp(argtwelve[0], argtwelve))
                            {
                                perror("error");
                                exit(1);
                            }
                        }
                        else if(pid > 0)
                        {
                            close(prevfd);
                            prevfd = fd[0];
                            close(fd[1]);
                        }


            }
                    while(wait(NULL)!=-1);
}
                    argm = cats;
                    delete [] argm;
        //start here
        }

			else if(strchr(argv[i], '|'))
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

                    delete [] argm;
				}
                else if(pid > 0)
                {
                    if(waitpid(-1, &nu, 0)==-1)
                    {
                        perror("Error");
                        exit(1);
                    }
                    if(nu!=0)
                    {
                        break;
                        exit(1);
                        }

                }



            }}
                argm = cats;
                delete [] argm;
	}		}
			else
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

        	int pid = fork();
		if(pid == -1)
		{
			perror("HI I'M SPOON");
			exit(1);
		}
		else if(pid ==0)
		{
                if(execvp(argtwelve[0], argtwelve) == -1)
				{
					perror("ERRROR");
				}
				exit(1);
			}

		else if(pid >0)
		{

			if(-1 == wait(0))
			perror("ERROR WAITING");
		}
        argtwelve = cats;
        delete [] argtwelve;
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
