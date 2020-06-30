#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;
int main () {
    cout << "Auto movie scheduler 0.1" << endl;
    string del = "del filenames.txt";
    string dir = "dir /b > filenames.txt";
    string command = del;
    system(command.c_str());
    command = dir;
    system(command.c_str());
    string start = "start";
    string vlc = "\"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe\"";
    string line;
    string pos;
    ifstream myfile ("filenames.txt");
    ifstream cache ("cache.txt");
    int i = 0, cachei = 0;
  if (cache.is_open())
  {
       while ( getline (cache,pos) )
    {
        stringstream toint(pos);
        toint >> cachei;
        break;
    }
  }
  cache.close();
     if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        if (i == cachei){
            command = start + " " + vlc + " \"" + line + "\"";
            system(command.c_str());
            break;
        }
        i++;
}
}
myfile.close();
del = "del cache.txt";
command = del;
system(command.c_str());
ofstream myfile2;
myfile2.open ("cache.txt");
myfile2 << i+1;
myfile2.close();
}
