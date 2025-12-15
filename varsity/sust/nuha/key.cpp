#include <iostream>
#include <string>
using namespace std;

int main() {
    string key = "Q29uZ3JhdHVsYXRpb25zIQogWW91IGhhdmUgcGFzc2VkIHRoZSBmaXJzdCBzdGVwIG9mIGJlY29taW5nIGEgaGFja2VyISAKIAogaHR0cHM6Ly90Lm1lLytWWXBHbFJlVm9ocG1OV1ZsIDwtLS10aGUgbGluawo=";
    for(int i = 0; i < 128; i++) {
        for(int j = 0; j < key.size(); j++) {
            cout << (char)(key[j]-i);
        }
        cout << '\n';
    }
    for(int i = 0; i < 128; i++) {
        for(int j = 0; j < key.size(); j++) {
            cout << (char)(key[j]+i);
        }
        cout << '\n';
    }

}