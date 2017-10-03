#include <sys/types.h>
#include <time.h>
#include <grp.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <algorithm>
#include <errno.h>
#include <iostream>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

int blocksize(vector<string> v, const char* dir)
{
    int total = 0;
    struct stat buf;
    for(unsigned int i = 0; i < v.size();++i)
    {
        string slash = "/";
        string yes = v.at(i);
        string path = dir + slash + yes;
        if(stat(path.c_str(), &buf)== -1)
        {
            perror("error");
            exit(1);
        }
        total += buf.st_blocks;

    }
    total /=2;
    string dire = dir;
    if(dire == ".")
    {
        total -=4;
    }

    return total;

}
void output(vector<string> v, const char* dir)
{
    unsigned int max = 80;
    unsigned int cur = 0;
    vector<vector<string> > columns;
    vector<string> row;
    for(unsigned int i = 0; i < v.size();++i)
    {
        cur+= v.at(i).size();
        if(cur < max)
        {

            row.push_back(v.at(i));
        }
        else
        {
            cur = 0;
            columns.push_back(row);
            row.clear();

            row.push_back(v.at(i));
        }
    }
    if(row.size()!= 0)
        columns.push_back(row);
    unsigned int jalapenos = columns.size();
    if(jalapenos == 0)
    columns.push_back(row);
    for(unsigned i = 0; i < columns.size();++i)
    {
        for(unsigned x= 0 ; x < columns.at(i).size();++x)
        {

            struct stat buf;
            string word = columns.at(i).at(x);
            string path = "/";
            string newpath = dir + path + word;
            if(lstat(newpath.c_str(), &buf)==-1)
            {
                perror("Error");
                exit(1);
            }
            if(word[0] == '.')
            {
                if(S_ISLNK(buf.st_mode))
                {
                    cout << "\033[1;100;36m" << columns.at(i).at(x) << "\033[0m" <<  '@' << ' ';

                }
                else if(S_ISDIR(buf.st_mode))
                {
                    cout << "\033[1;100;34m" << columns.at(i).at(x) << "\033[0m" << '/' <<  ' ';
                }
                else if((S_IXUSR & buf.st_mode) || (S_IXGRP & buf.st_mode) || (S_IXOTH & buf.st_mode))
                {
                    cout << "\033[100;32m" << columns.at(i).at(x) << "\033[0m" << '*' << ' ';

                }
                else cout << columns.at(i).at(x) << ' ';
            }
            else
            {
                if(S_ISLNK(buf.st_mode))
                {
                    cout << "\033[1;36m" << columns.at(i).at(x) << "\033[0m" <<  '@' << ' ';

                }
                else if(S_ISDIR(buf.st_mode))
                {
                    cout << "\033[1;34m" << columns.at(i).at(x) << "\033[0m" << '/' << ' ';
                }

                else if((S_IXUSR & buf.st_mode) || (S_IXGRP & buf.st_mode) || (S_IXOTH & buf.st_mode))
                {
                    cout << "\033[1;32m" << columns.at(i).at(x) << "\033[0m" << '*' << ' ';

                }
                else cout << word << ' ';
            }

        }
        cout << endl;
    }
}
 void ls(const char* dir, int flag, int size)
{
    string dirName = dir;
    if(size >1)
    {
        cout << dir << ": " << endl;
    }
     DIR *dirp = opendir(dirName.c_str());
     if(dirp == NULL)
     {
         struct stat boof;
         if(stat(dir, &boof) != 0)
         {
             perror("Error: ");
             return;
         }
         else
         {
             cout << dir << endl;
             return;
         }
         perror("Error: invalid file name");
         return;
     }

     dirent *direntp;
    vector <string>v;
     while ((direntp = readdir(dirp)))
     {
         if(direntp == NULL)
         {
             perror("Error ");
             exit(1);
         }
         string word = direntp->d_name;
         if(!flag)
         {
            if(word[0] == '.')
                continue;
            else
            v.push_back(word);
         }
         else
             v.push_back(word);
     }
     sort(v.begin(), v.end(), locale("en_US.UTF-8"));
     output(v, dirName.c_str());
 if(-1==closedir(dirp)){
     perror("Error closing");
     exit(1);
 }
 }



    void ls_l(const char* dir, int flaga)
    {
        int max = 4;
        string dirName = dir;
        DIR *dirp = opendir(dir);
        if (dirp == NULL)
        {
            perror("Error opening");
            exit(1);
        }
        dirent *direntp;
            vector <string>v;
            while((direntp = readdir(dirp)))
            {
                if(direntp == NULL)
                {
                    perror("Error on -l");
                    exit(1);
                }
                string ward = direntp->d_name;
                if((ward[0] == '.') && !flaga);
                    else
            v.push_back(ward);

        }
        int blocksized = blocksize(v, dir);
        cout << "total: " << blocksized << endl;
        sort(v.begin(), v.end(), locale("en_US.UTF-8"));
        for(unsigned int i = 0; i < v.size();++i)
        {
            struct stat buf;
            string words = v.at(i);
            string patherino = "/";
            string newpatherino = dirName + patherino + words;
            if(lstat(newpatherino.c_str(), &buf))
            {
                perror("Error on line 215");
                exit(1);
                }
            if((words == "." || words == "..") && !flaga)
            {
                continue;
            }
            if(words[0] == '.' && !flaga)
            {
                continue;
            }
            if(S_ISDIR(buf.st_mode))
            {
                    cout << 'd';
            }
            else if(S_ISLNK(buf.st_mode))
                cout << 'l';
            else cout << '-';
            if(S_IRUSR&buf.st_mode)
                cout << 'r';
            else cout << '-';
            if(S_IWUSR & buf.st_mode)
                cout << 'w';
                else cout << '-';
            if(S_IXUSR & buf.st_mode)
                cout << 'x';
                else cout << '-';
            if(S_IRGRP&buf.st_mode)
                cout << 'r';
            else cout << '-';
            if(S_IWGRP & buf.st_mode)
                cout << 'w';
                else cout << '-';
            if(S_IXGRP & buf.st_mode)
                cout << 'x';
                else cout << '-';
             if(S_IROTH&buf.st_mode)
                cout << 'r';
            else cout << '-';
            if(S_IWOTH & buf.st_mode)
                cout << 'w';
                else cout << '-';
            if(S_IXOTH & buf.st_mode)
                cout << "x ";
                else cout << "- ";
            cout <<  buf.st_nlink << ' ';
            struct passwd *pw;
            uid_t uid = buf.st_uid;
            pw = getpwuid(uid);
            if(1 == -1){
     perror("Error closing");
     exit(1);
 }
            cout << pw->pw_name << ' ';
            struct group *gp;
            gid_t gid = buf.st_gid;
            gp = getgrgid(gid);
            if(1 ==-1){
     perror("Error closing");
     exit(1);
 }
            cout << gp->gr_name << ' ';
            if(buf.st_size> 10000)
                max = 5;
            cout << setw(max)  << right << buf.st_size << ' ';
            char date[15];
            strftime(date, 15, "%b %e %R", localtime(&buf.st_mtime));
            cout << date << ' ';
            if(words[0] == '.')
            {
                if(S_ISLNK(buf.st_mode))
                {
                    cout << "\033[1;100;36m" << words << "\033[0m" << '@' <<  ' ';

                }
                else if(S_ISDIR(buf.st_mode))
                {
                    cout << "\033[1;100;34m" << words << "\033[0m" <<  '/'<<  ' ';
                }
                else if((S_IXUSR & buf.st_mode) || (S_IXGRP & buf.st_mode) || (S_IXOTH & buf.st_mode))
                {
                    cout << "\033[100;32m" << words << "\033[0m" <<  '*'<<  ' ';

                }
                else cout << words << ' ';
            }
            else
            {
                if(S_ISLNK(buf.st_mode))
                {
                    cout << "\033[1;36m" << words << "\033[0m" << '@' << ' ';

                }
                else if(S_ISDIR(buf.st_mode))
                {
                    cout << "\033[1;34m" << words << "\033[0m" << '/' << ' ';
                }

                else if((S_IXUSR & buf.st_mode) || (S_IXGRP & buf.st_mode) || (S_IXOTH & buf.st_mode))
                {
                    cout << "\033[1;32m" << words << "\033[0m" << '*' << ' ';

                }
                else cout << words << ' ';
            }
            cout << endl;
        }

        if(-1==closedir(dirp)){
     perror("Error closing");
     exit(1);
 }
    }
/* void ls_RR(vector<string> ve)
 {
     for(unsigned int i = 0; i < ve.size();++i)
     {
        struct stat buf;
        stat(ve.at(i), &buf);
        if(S_ISDIR(buf.st_mode))
        {
            cout <<"asdasd" << endl;
        }

     }

 }
 */

 void ls_R(const char* dir, int flaga, int flagl)
{
     string dirName = dir;
     cout << dir << ": " << endl;

     vector <string>t;
     if(flagl)
     {
         ls_l(dir, flaga);
     }
     DIR *dirp = opendir(dir);
     if(dirp == NULL)
     {
         struct stat boof;
         if(stat(dir, &boof) != 0)
         {
             perror("Error: ");
             return;
         }
         else
         {
             cout << dir << endl;
             return;
         }
         perror("Error opening directory");
         exit(1);
     }
     dirent *direntp;
     vector <string>v;
     while ((direntp = readdir(dirp)))
     {
         if(direntp == NULL)
         {
             perror("Error");
             exit(1);
         }
         char * word = direntp->d_name;
         string words = direntp->d_name;
         string patherino = "/";
         string newpatherino = dirName + patherino + word;
         struct stat buf;
            if(stat(newpatherino.c_str(), &buf))
            {
                perror("Error");
                exit(1);
            }
         if(words == "." || words  == "..");
         else{
            if(word[0] == '.' && !flaga)
            {
                continue;
            }
            v.push_back(words);
            if(S_ISDIR(buf.st_mode))
            {
                string path ="/";
                string newpath = dirName + path + word;
                t.push_back(newpath);
            }
         }

     }
     sort(v.begin(), v.end(), locale("en_US.UTF-8"));
     sort(t.begin(), t.end(), locale("en_US.UTF-8"));

         if(flagl)
         {
         }
         else
            output(v, dir);
     for(unsigned i = 0; i < t.size();++i)
     {
      cout << endl;

         string tmp = t.at(i);

                ls_R(tmp.c_str(), flaga, flagl);
     }
    if(-1==closedir(dirp)){
     perror("Error closing");
     exit(1);
 }
   return;

 }



void printfiles(vector<char*> v)
{
    if(v.size() == 0)
        return;
    for(unsigned i = 0; i < v.size();++i)
    {
        cout << v.at(i) << ' ';
    }
    cout << endl;

}

void printfilesl(vector<char*> v)
{
   for(unsigned int i = 0; i < v.size();++i)
        {
            struct stat buf;
            if(lstat(v.at(i), &buf))
            {
                perror("Error on line 215");
                exit(1);
                }
            if(S_ISDIR(buf.st_mode))
            {
                    cout << 'd';
            }
            else if(S_ISLNK(buf.st_mode))
                cout << 'l';
            else cout << '-';
            if(S_IRUSR&buf.st_mode)
                cout << 'r';
            else cout << '-';
            if(S_IWUSR & buf.st_mode)
                cout << 'w';
                else cout << '-';
            if(S_IXUSR & buf.st_mode)
                cout << 'x';
                else cout << '-';
            if(S_IRGRP&buf.st_mode)
                cout << 'r';
            else cout << '-';
            if(S_IWGRP & buf.st_mode)
                cout << 'w';
                else cout << '-';
            if(S_IXGRP & buf.st_mode)
                cout << 'x';
                else cout << '-';
             if(S_IROTH&buf.st_mode)
                cout << 'r';
            else cout << '-';
            if(S_IWOTH & buf.st_mode)
                cout << 'w';
                else cout << '-';
            if(S_IXOTH & buf.st_mode)
                cout << "x ";
                else cout << "- ";
            cout <<  buf.st_nlink << ' ';
            struct passwd *pw;
            uid_t uid = buf.st_uid;
            pw = getpwuid(uid);
            if(1==-1){
     perror("Error closing");
     exit(1);
 }
            cout << pw->pw_name << ' ';
            struct group *gp;
            gid_t gid = buf.st_gid;
            gp = getgrgid(gid);
            if(0==-1){
     perror("Error closing");
     exit(1);
 }
            cout << gp->gr_name << ' ';
            cout << buf.st_size << ' ';
            char date[15];
            strftime(date, 15, "%b %e %R", localtime(&buf.st_mtime));
            cout << date << ' ';
           cout << v.at(i) << endl;
        }
}
 int main(int argc, char *argv[])
 {

     int flag_a = 0;
     int flag_l = 0;
     int flag_r = 0;
    vector<char*> files1;
    for(int i = 1; i < argc ; ++i)
    {
        if(argv[i][0] == '-')
        {
             for(unsigned int k = 1; k < strlen(argv[i]);++k)
             {
                if(argv[i][k] == 'a')
                {
                    flag_a = 1;
                }
                else if(argv[i][k] == 'l')
                {
                    flag_l = 1;
                }
                else if(argv[i][k] == 'R')
                {
                    flag_r = 1;
                }
                else
                {
                    cerr << "Error: LS: Command not found" << endl;
                    return 0;
                }
             }
        }
        else
        {
            files1.push_back(argv[i]);
        }
     }
     vector<char*> files;
     vector<char*> goodfiles;
     vector<char*> directories;
     for(unsigned int i = 0; i < files1.size();++i)
      {
            struct stat buf;
            if(stat(files1.at(i), &buf))
            {
                files.push_back(files1.at(i));
            }
            else if(S_ISDIR(buf.st_mode))
                directories.push_back(files1.at(i));
                else
                goodfiles.push_back(files1.at(i));
            if(1==2){
     perror("Error closing");
     exit(1);
 }

      }
      for(unsigned int i = 0; i < directories.size();++i)
          files.push_back(directories.at(i));
     if(flag_a + flag_r + flag_l == 0)
     {
         if(files.size() == 0)
         {
            if(goodfiles.size() == 0)
            {
            string foo= ".";
            ls(foo.c_str(), 0, directories.size());
            }
            else
                printfiles(goodfiles);
         }
         else
         {
             if(goodfiles.size() > 0)
             {
                printfiles(goodfiles);
                cout << endl;
             }
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 if(goodfiles.size() > 0)
                 ls(files.at(i),0, 5);
                 else
                 ls(files.at(i), 0, directories.size());
             }
         }
     }
    if(flag_a && flag_r + flag_l == 0)
    {

         if(files.size() == 0)
         {
            if(goodfiles.size() == 0)
            {
            string foo= ".";
            ls(foo.c_str(), flag_a, directories.size());
            }
            else
                printfiles(goodfiles);
         }
         else
         {
             if(goodfiles.size()>0)
             {
                printfiles(goodfiles);
                cout << endl;
             }
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 if(goodfiles.size() > 0)
                     ls(files.at(i),flag_a,5);
                     else
                 ls(files.at(i), flag_a, directories.size());
                 cout << endl;
             }
         }
    }
    if(flag_r)
    {

         if(files.size() == 0)
         {
             if(goodfiles.size() == 0)
             {
            string a = ".";
            ls_R(a.c_str(), flag_a, flag_l);
             }
             else
                 printfiles(goodfiles);
         }
         else
         {
             printfiles(goodfiles);
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls_R(files.at(i), flag_a, flag_l);
             }
         }
    }
    if(flag_l && flag_a + flag_r == 0)
    {
         if(files.size() == 0)
         {
             if(goodfiles.size()==0)
             {
            string foo= ".";
            ls_l(foo.c_str(), flag_a);
             }
             else
                 printfilesl(goodfiles);
         }
         else
         {
             printfilesl(goodfiles);
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls_l(files.at(i), flag_a);
                // cout << endl;
             }
         }
    }
    /*
    if(flag_l + flag_r == 2 && !flag_a)
    {
        if(files.size() == 0)
         {
            string foo= ".";
            ls_R(foo.c_str(), flag_a, flag_l);
         }
         else
         {
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls_R(files.at(i), flag_a, flag_l);
                 cout << endl;
             }
         }
    }
    */
    if(flag_a + flag_l == 2 && !flag_r)
    {
         if(files.size() == 0)
         {
             if(goodfiles.size() ==0)
             {
            string foo= ".";
            ls_l(foo.c_str(), flag_a);
             }
             else
                 printfilesl(goodfiles);
         }
         else
         {
             printfilesl(goodfiles);
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls_l(files.at(i), flag_a);
                 cout << endl;
             }
         }
    }
    return 0;
}

