#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> n_vec(n,0);
    for (int i=0; i<n; i++) {
        cin >> n_vec[i];
    }
    int max = 0;
    for(int i=0; i<n; i++) {
        for(int p=i+1; p<n; p++) {
            for(int q=p+1; q<n; q++) {
                int a = n_vec[i], b = n_vec[p], c=n_vec[q];
                int num = 0;
                while(true){
                    if(!a && !b && !c) {
                        num = n_vec[i] + n_vec[p] + n_vec[q];
                        break;
                    }
                    if(a%10 + b%10 + c%10 >= 10) break;
                    else {
                        a/=10; b/=10; c/=10;
                    }
                }
                if(max < num) max = num;
            }
        }
    }
    cout << ((max) ? max : -1);
    return 0;
}