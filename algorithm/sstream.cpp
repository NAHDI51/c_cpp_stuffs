#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main() {
    DIR* d = opendir("/media/amogus/huges/stuffs");   
    dirent* dir;
    string prefix = "badoinkvr";
    int cnt = 0;
    while((dir = readdir(d)) != NULL) {
        string name(dir->d_name);
        for(int i = 0; i < name.size(); i++) name[i] = tolower(name[i]);
        cout << name << '\n';
        if(name.find(prefix) != -1) cnt++;
    }
    cout << "Total number of such files: " << cnt << '\n';
}