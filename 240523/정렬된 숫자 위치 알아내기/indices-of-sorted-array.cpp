#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int num;
    int grade;
};

int main() {
    int n;
    cin >> n;
    vector<Student> stu_vec;
    for (int i=0; i<n; i++) {
        Student stu;
        stu.num = i+1;
        cin >> stu.grade;
        stu_vec.push_back(stu);
    }
    sort(stu_vec.begin(), stu_vec.end(), [](auto a, auto b){
        if (a.grade == b.grade) return a.num < b.num;
        return a.grade < b.grade;
    });
    vector<int> grade_vec;
    for(auto s : stu_vec) {
        grade_vec.push_back(s.num); 
        // 2 7 4 1 3 5 6
    }
    int *arr = new int[stu_vec.size()];
    for (int i=0; i<grade_vec.size(); i++) {
        arr[grade_vec[i]-1] = i+1;
    }
    for (int i=0; i<grade_vec.size(); i++) {
        cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}