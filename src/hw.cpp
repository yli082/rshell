#include <iostream>
#include <signal.h>
#include <dirent.h>
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
}

int countfun(string s)
{
    int cuont = 0;
    for(unsigned int i = 0; i < s.size();++i)
        if(s[i] == '|') cuont ++;

        return cuont;
}

char* getpath(char* command)
{
    char *path = getenv("PATH");
    string cmd = command;
    char *paht = strtok(path, ":");
    while(paht != NULL)
    {
        //cout << paht << endl;
        struct stat buf;
        if(stat(paht, &buf) == -1)
        {
            if(1==0)
                perror("asdasd");
        }
        else
        {
        DIR *dirp = opendir(paht);
        if(dirp == NULL)
        {
            perror(paht);
            exit(1);
        }
        dirent *direntp;
        while((direntp = readdir(dirp)))
        {
            string match = direntp->d_name;
            if(direntp == NULL)
            {
                perror("Error");
                exit(1);
            }
            if(cmd == match && (S_IXUSR & buf.st_mode))
            {
                strcat(paht, "/");
                strcat(paht, command);
                return paht;
            }


        }
        }
        paht = strtok(NULL, ":");
    }
    //strcat(paht, "/");
    //strcat(paht, command);
    return command;
}
static void sighand(int sig)
{
    if(sig == SIGINT)
    {
    int child = getpid();
    if(-1 == child)
    {
        exit(0);
    }
    if(child == 0)
    {
        exit(0);
    }
    }

}
int main()
{
   if(SIG_ERR== signal(SIGINT, sighand))
   {
       perror("err");

   }



while(1)
{
    	string stringz;
/*	char *host = new char[256];
	if(-1==gethostname(host, 256))
    {
        perror("Error host name");
        exit(1);
    }

	cout << getlogin() << '@' << host<< "$ ";
    */
    char bzxc[1024];
    getcwd(bzxc, sizeof(bzxc));
    cout << bzxc << ' ' << "$" << ' ';
    if(0 == -1)
    {
        perror("Error get login");
        exit(1);
    }
	//delete [] host;

	getline(cin, stringz);
	if(stringz == "exit")
    return 0;
	//cout << stringz << endl;
	char *str= new char[stringz.size()+1];
	strcpy(str, stringz.c_str());
	char *str2 = new char[stringz.size()+1];
	strcpy(str2, stringz.c_str());
	char *test = strtok(str2, " ;&|");
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
            (countfun(command) == 1)
            )

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
               // cout << newcommand << endl;
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
                            string argmsize = argm[i];
                            char **argtwelve = new char*[argmsize.size()+1];
			             	char *moo;
				            moo =strtok(argm[i], " <>");
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
				        	    moo = strtok(NULL, " <>");
			            	}
					argtwelve[numberino] = NULL;
             string lala = argtwelve[0];
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
                 int validecinput = 0;
                 if(ecinput)
                 {

                            string pie = argtwelve[numberino-1];
                        if(argtwelve[1][0] == '\"')
                        {
                            ++validecinput;
                            argtwelve[1] = strtok(argtwelve[1], "\"");
                        }

                        if(argtwelve[numberino-1][pie.size()-1] == '\"')
                        {
                            ++validecinput;
                            argtwelve[numberino-1] = strtok(argtwelve[numberino-1], "\"");

                        }

                 }
                 if(validecinput == 2);
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
                        fdo = open(argtwelve[numberino -2], O_RDWR|O_CREAT|O_TRUNC, 00700);
                        if(-1==fdo){
                             perror("Error!");
                             exit(1);
                         }
                        if(flagec);
                        else{
                           if(-1== close(1)){
                            perror("Error!!");
                            exit(1);
                    }
                        }
                    }
                            if(-1==dup2(fdo, 1)){
                            perror("Error!!!!");
                            exit(1);
                    }

                        argtwelve[numberino -2] = NULL;
                        argtwelve[numberino -1] = NULL;
                    }






                 if(numer > 1)
                 {
                     if(i != 0)
                     {
                         if(-1==dup2(prevfd, 0))
                         {
                             perror("Error");
                             exit(1);
                         }
                         if(-1==close(prevfd))
                         {
                             perror("Error");
                             exit(1);
                         }
                     }
                     else
                     {
                        if(-1==dup2(fd[1], 1)){
                             perror("Error");
                             exit(1);
                         }
                     if(-1==close(prevfd)){
                             perror("Error");
                             exit(1);
                         }
                     prevfd = dup(fd[0]);
                     if(prevfd==-1){
                             perror("Error");
                             exit(1);
                         }
                     }
                     if(-1==close(fd[0])){
                             perror("Error");
                             exit(1);
                         }

                     if(-1==close(fd[1])){
                             perror("Error");
                             exit(1);
                         }
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
                 char *s = getpath(argtwelve[0]);
                 argtwelve[0] = s;
                 if(lala == "cd");
                 else if(execv(s, argtwelve) == -1)
                 {
                     perror("erRROr");
                     exit(1);

                 }
                 exit(0);
              }
              else if(pid > 0)
              {
                  if(lala == "cd")
                  {
                      if(-1==chdir(argtwelve[1]))
                      {
                          perror("err");
                      }
                  }
                  if(-1==close(prevfd)){
                             perror("Error");
                             exit(1);
                         }
                        prevfd = fd[0];
                        if(-1==close(fd[1])){
                             perror("Error");
                             exit(1);
                         }

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

                        string lala = argtwelve[0];

                        int pid = fork();
                        if(pid == -1)
                        {
                            perror("error");
                            exit(1);
                        }
                        else if(pid == 0)
                        {
                            if(i==0);
                            else{
                                if(-1==dup2(prevfd, 0)){
                             perror("Error");
                             exit(1);
                         }
                            }
                            if(-1==close(prevfd)){
                             perror("Error");
                             exit(1);
                         }
                            if(i!= numer-1)
                            {
                               if(-1== dup2(fd[1], 1)){
                             perror("Error");
                             exit(1);
                         }

                                if(-1==close(fd[0])){
                             perror("Error");
                             exit(1);
                         }
                                if(-1==close(fd[1])){
                             perror("Error");
                             exit(1);
                         }
                            }
                            char *s = getpath(argtwelve[0]);
                            argtwelve[0] = s;
                            if(lala == "cd");
                            else if(-1==execv(s, argtwelve))
                            {
                                perror("error");
                                exit(1);
                            }
                            exit(0);
                        }
                        else if(pid > 0)
                        {
                            if(lala == "cd")
                            {
                                if(-1==chdir(argtwelve[1]))
                                {
                                    perror("err ");
                                }

                            }
                            if(-1==close(prevfd)){
                             perror("Error");
                             exit(1);
                         }
                            prevfd = fd[0];
                            if(-1==close(fd[1])){
                             perror("Error");
                             exit(1);
                         }
                        }


            }
                    while(wait(NULL)!=-1);
                    if(1 == 2){
                             perror("Error");
                             exit(1);
                         }
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
                    string pazxxx = argtwelve[0];
                        int pid = fork();
                        if(pid == -1)
                        {
                            perror("yes");
                            exit(1);
                        }
                        else if(pid == 0)
                        {
                            char *s = getpath(argtwelve[0]);
                            argtwelve[0] = s;
                            if(pazxxx == "cd");
				            else if(execv(s, argtwelve) == -1)
			            	{
					                perror("erRROr");
                                exit(1);

				            }
                            exit(0);
                        }
                        else if(pid > 0)
                        {
                            if(pazxxx == "cd")
                            {
                                if(-1==chdir(argtwelve[1]))
                                {
                                    perror("err");
                                }
                            }

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
                            string lala = argtwelve[0];
                            int pid = fork();
                           if(pid == -1)
                           {
                               perror("yes");
                               exit(1);
                           }
                           else if(pid == 0)
                           {
                               char *s = getpath(argtwelve[0]);
                               argtwelve[0] = s;
                               if(lala == "cd");
				               else if(execv(s, argtwelve) == -1)
			            	   {

					                   perror("ERROR");

                                   exit(1);

                    delete [] argm;

            }
                exit(0);
            	}
                else if(pid > 0)
                {
                    if(lala == "cd")
                    {
                        if(-1==chdir(argtwelve[1]))
                            perror(argtwelve[1]);
                    }
                    delete [] argtwelve;
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



            }
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

                string lala = argtwelve[0];
                if(lala == "cd")
                {

                if(-1==chdir(argtwelve[1]))
                    perror(argtwelve[1]);

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
            char* zebras = getpath(argtwelve[0]);
            argtwelve[0] = zebras;
                if(execv(zebras, argtwelve) == -1)
				{

					perror(zebras);
				}
                return 0;
				//exit(0);
			}

		else if(pid >0)
		{

			if(-1 == wait(0))
			perror("ERROR WAITING");
		}
                }
        argtwelve = cats;
        delete [] argtwelve;
}

	}
    argv = curargv;
        delete  [] argv;
        delete [] str;

}

}
	return 0;
}
