#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_space(const vector<int>& vec) {
  int result = 0;
  int space = 0;
  for (int n : vec) {
    if(n) {
      if (result < space) result = space;
      space = 0;
    }
    else space++;
  }
  return result;
}

int min_space(const vector<int>& vec) {
  int result = vec.size();
  int space = vec.size();
  for (int n : vec) {
    if(n) {
      if (result > space) result = space;
      space = 0;
    }
    else space++;
  }
  return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> seat;
    int start = 0;
    while(s[start] != '1') start++;
    int end = n-1;
    while(s[end] != '1') end--;
    end = n-end-1;
    for(int i=start; i<n; i++) {
      seat.emplace_back(s[i] - '0');
    }

    if (max_space(seat) >= min_space(seat)*2 + 1) cout << min_space(seat)+1;
    else cout << max(max(start, (end)), ((max_space(seat)+1) / 2));

    return 0;
}