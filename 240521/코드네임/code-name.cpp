#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Agent {
    string name;
    int grade;
};

int main() {
    vector<Agent> a_vec;
    for (int i=0; i<5; i++) {
        Agent temp_a;
        cin >> temp_a.name >> temp_a.grade;
        a_vec.push_back(temp_a);
    }
    sort(a_vec.begin(), a_vec.end(), [](Agent a, Agent b){
        return a.grade < b.grade;
    });   
    cout << a_vec[0].name << " " << a_vec[0].grade;
    return 0;
}