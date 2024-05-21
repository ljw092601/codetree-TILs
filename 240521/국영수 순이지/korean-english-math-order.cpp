#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    tuple <int, int, int, string> stu_tuple[10];
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        stu_tuple[i] = make_tuple(kor, eng, math, name);
    }
    sort(stu_tuple, stu_tuple+n, [](auto a, auto b){return a>b;});
    for (int i=0; i<n; i++) {
        string name;
        int kor, eng, math;
        tie(kor, eng, math, name) = stu_tuple[i];
        cout << name << " " << kor << " " << eng << " " << math << endl;
    }
    return 0;
}