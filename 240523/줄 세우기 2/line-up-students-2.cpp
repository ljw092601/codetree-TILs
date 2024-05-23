#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int height;
    int weight;
    int idx;
};

int main() {
    int n;
    cin >> n;
    vector<Student> stu_vec;
    for (int i=0; i<n; i++) {
        Student stu;
        stu.idx = i+1;
        cin >> stu.height >> stu.weight;
        stu_vec.push_back(stu);
    }
    sort(stu_vec.begin(), stu_vec.end(), [](auto a, auto b){
        if (a.height == b.height) return a.weight < b.weight;
        return a.height < b.height;
    });
    for (Student s : stu_vec) {
        cout << s.height << " " << s.weight << " " << s.idx << endl;
    }
    return 0;
}