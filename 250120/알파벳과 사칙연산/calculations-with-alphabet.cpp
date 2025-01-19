#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

string expression;

int values[6];  // a:0, b:1, ... , f:5
int max_answer = -INT_MAX;

int val_to_int(char v) {
    if(v == 'a') return values[0];
    else if(v == 'b') return values[1];
    else if(v == 'c') return values[2];
    else if(v == 'd') return values[3];
    else if(v == 'e') return values[4];
    else if(v == 'f') return values[5];
}

int cal(int a, char s, int b) {
    if (s == '+') return a + b;
    else if (s == '-') return a - b;
    else if (s == '*') return a * b;
}

int cal_exp() {
    int cal_val = val_to_int(expression[0]);
    for(int i=1; i<expression.size(); i += 2) {
        cal_val = cal(cal_val, expression[i], val_to_int(expression[i+1]));
    }
    return cal_val;
}

void simulation(int n) {
    if(n == 6) {
        max_answer = max(max_answer, cal_exp());
        return;
    }
    for(int i=1; i<=4; i++) {
        values[n] = i;
        simulation(n+1);
    }
}

int main() {
    cin >> expression;

    simulation(0);

    cout << max_answer;

    return 0;
}
