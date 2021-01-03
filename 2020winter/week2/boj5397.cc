#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        string log;
        cin >> log;
        list<char> password;
        list<char>::iterator cursor;
        
        for(char ch : log) {
            if(ch == '<') {
                if(!password.empty() && cursor != password.begin())
                    cursor--;
            }
            else if(ch == '>') {
                if(!password.empty() && cursor != password.end())
                    cursor++;
            }
            else if(ch == '-') {
                if(!password.empty() && cursor != password.begin()) {
                    cursor = password.erase(--cursor);
                }
            }
            else {
                if(password.empty()) {
                    password.push_back(ch);
                    cursor = password.end();
                }
                else {
                    cursor = password.insert(cursor, ch);
                    cursor++;
                }
            }
        }

        for(auto it = password.begin(); it != password.end(); it++)
            printf("%c", *it);
        printf("\n");
    }

    return 0;
}