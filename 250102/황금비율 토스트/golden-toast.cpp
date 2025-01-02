#include <iostream>
#include <string>
#include <list>
 
using namespace std;

int n, m;

string s;

int main(){
    cin >> n >> m;
    cin >> s;
    
    list<char> toast;
    for(char c : s) {
        toast.push_back(c);
    }
    list<char>::iterator it = toast.end();
    
    while(m--) { 
        char command;
        cin >> command;
        
        if(command == 'L') {
            if(it != toast.begin())
                it--;
        } 
        else if(command == 'R') {
            if(it != toast.end())
                it++;
        }
        else if(command == 'D') {
            if(it != toast.end())
                it = toast.erase(it);
        }
        else if(command == 'P') {
            char c;
            cin >> c;
            toast.insert(it, c);
        }    
    }
    
    // 출력:
    for (list<char>::iterator it = toast.begin(); it != toast.end(); it++) {
        cout << *it;
    }
    return 0;     
}