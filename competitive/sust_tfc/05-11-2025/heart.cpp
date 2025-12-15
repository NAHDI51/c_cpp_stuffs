#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string heart = "❤️";
    int count = 0;

    for (size_t i = 0; i + heart.size() <= s.size(); ++i) {
        if (s.substr(i, heart.size()) == heart) {
            count++;
        }
    }

    cout << "Number of ❤️ emojis: " << count << endl;
    return 0;
}
