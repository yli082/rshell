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


/*void time(int time)
{
    cout << ctime(time);
}
*/
void output(vector<string> v)
{
    unsigned int max = 80;
    unsigned int cur = 0;
    vector<vector<string> > columns;
    vector<string> row;
    for(unsigned int i = 0; i < v.size();++i)
    {

        cur+= v.at(i).size();
        cout << cur << endl;
        if(cur < max)
        {
            row.push_back(v.at(i));
        }
        else
        {
            cur = 0;
            columns.push_back(row);
            row.clear();
        }
    }
    for(unsigned i = 0; i < columns.size();++i)
    {
        for(unsigned x= 0 ; x < columns.at(i).size();++x)
        {
            cout << columns.at(i).at(x) << ' ';
        }
        cout << endl;
    }
}
 void ls(const char* dir, int flag)
{
    string dirName = dir;

     DIR *dirp = opendir(dirName.c_str());
     if(dirp == NULL)
     {
         perror("Error: invalid file name");
         return;
     }
    if(dirName != ".")
    {
        cout << dir << ": " << endl;
    }

     dirent *direntp;
    vector <string>v;
     while ((direntp = readdir(dirp)))
     {
         string word = direntp->d_name;
         v.push_back(word);
     }
     sort(v.begin(), v.end(), locale("en_US.UTF-8"));
     output(v);
  /*
     for(unsigned int x = 0; x < v.size();++x)
     {
         if(flag == 1)
         {
             cout << v.at(x) << endl;
         }
         else {

            if(v.at(x).at(0) == '.');
            else
            cout << v.at(x) << endl;
         }
     }
*/
 closedir(dirp);
 }



    void ls_l(const char* dir, int flaga)
    {
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
            v.push_back(ward);

        }
        sort(v.begin(), v.end(), locale("en_US.UTF-8"));
        for(unsigned int i = 0; i < v.size();++i)
        {
            struct stat buf;
            string words = v.at(i);
            string patherino = "/";
            string newpatherino = dirName + patherino + words;
            lstat(newpatherino.c_str(), &buf);
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
            cout << buf.st_nlink << ' ';
            struct passwd *pw;
            uid_t uid = buf.st_uid;
            pw = getpwuid(uid);
            cout << pw->pw_name << ' ';
            struct group *gp;
            gid_t gid = buf.st_gid;
            gp = getgrgid(gid);
            cout << gp->gr_name << ' ';
            cout << buf.st_size << ' ';
            char date[15];
            strftime(date, 15, "%b %e %R", localtime(&buf.st_mtime));
            cout << date << ' ';
            cout << v.at(i);
            cout << endl;
        }

        closedir(dirp);
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

     for(unsigned int i = 0; i < v.size();++i)
     {
         if(flagl)
         {
         }
         else
             cout << v.at(i) << " ";
     }
     cout << endl;
     for(unsigned i = 0; i < t.size();++i)
     {

         string tmp = t.at(i);

                ls_R(tmp.c_str(), flaga, flagl);
     }
    closedir(dirp);
   return;

 }


void ls_Rawr()
{
    string dirName = ".";
    DIR *dirp = opendir(dirName.c_str());
    dirent *direntp;
    while((direntp= readdir(dirp)))
    {
        string def = direntp->d_name;
        if(def == "." || def == "..")
            continue;

        struct stat buf;
        stat(direntp->d_name, &buf);
        if(S_ISDIR(buf.st_mode))
        ls_R(direntp->d_name, 0, 0);
        //cout << direntp->d_name << ' ';
    }
    cout << "return" << endl;
}


 int main(int argc, char *argv[])
 {

     int flag_a = 0;
     int flag_l = 0;
     int flag_r = 0;
    vector<char*> files;
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
            files.push_back(argv[i]);
        }
     }
     vector<char*> reprint;
     for(unsigned int i = 0; i < files.size();++i)
      {
            struct stat buf;
            stat(files.at(i), &buf);
            if(S_ISREG(buf.st_mode) || S_ISDIR(buf.st_mode)
                || S_ISLNK(buf.st_mode))
            {
                reprint.push_back(files.at(i));
            }

      }
     if(flag_a + flag_r + flag_l == 0)
     {
         if(files.size() == 0)
         {
            string foo= ".";
            ls(foo.c_str(), 0);
         }
         else
         {
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls(files.at(i), 0);
             }
         }
     }
    if(flag_a && flag_r + flag_l == 0)
    {

         if(files.size() == 0)
         {
            string foo= ".";
            ls(foo.c_str(), flag_a);
         }
         else
         {
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls(files.at(i), flag_a);
                 cout << endl;
             }
         }
    }
    if(flag_r)
    {
         if(files.size() == 0)
         {
            string a = ".";
            ls_R(a.c_str(), flag_a, flag_l);
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
    if(flag_l && flag_a + flag_r == 0)
    {
         if(files.size() == 0)
         {
            string foo= ".";
            ls_l(foo.c_str(), flag_a);
         }
         else
         {
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls_l(files.at(i), flag_a);
                 cout << endl;
             }
         }
    }
    if(flag_a + flag_r == 2 && !flag_l)
    {
        cout << "a + r" << endl;
    }
    if(flag_l + flag_r == 2 && !flag_a)
    {
        cout << "l + r" << endl;
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
    if(flag_a + flag_l == 2 && !flag_r)
    {
         if(files.size() == 0)
         {
            string foo= ".";
            ls_l(foo.c_str(), flag_a);
         }
         else
         {
             for(unsigned int i = 0; i < files.size(); ++i)
             {
                 ls_l(files.at(i), flag_a);
                 cout << endl;
             }
         }
    }
    return 0;
}

