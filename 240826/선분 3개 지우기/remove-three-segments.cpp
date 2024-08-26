#include <iostream>
#include <vector>
using namespace std;

struct Line {
    int start;
    int end;
};

int main() {
    int n;
    cin >> n;
    vector<Line> line_vec;
    for (int i=0; i<n; i++) {
        Line line;
        cin >> line.start >> line.end;
        line_vec.emplace_back(line);
    }
    int cases = 0;
    for (int i=0; i<n-2; i++) {
        for (int p=i+1; p<n-1; p++) {
            for (int t=p+1; t<n; t++) {
                vector<int> zero_vec(100,0);
                for (int l=0; l<n; l++) {
                    if(l!=i && l!=p && l!=t) {
                        for(int q=line_vec[l].start; q<=line_vec[l].end; q++) {
                            zero_vec[q]++;
                        }
                    }
                }
                bool put = false;
                for (int v:zero_vec) {
                    if (v > 1) put = true;
                }
                if(!put) cases++;
            }
        }
    }
    cout << cases;
    return 0;
}