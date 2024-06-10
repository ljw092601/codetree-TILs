#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[110] = {'\0',};
    while(n--) {
        int idx;
        char c;
        cin >> idx >> c;
        arr[idx] = c;
    }
    int max_dist = 0;
    for(int i=0; i<100; i++) {
        for(int p=0; p<=100-i; p++) {
            int cnt_G = 0, cnt_H = 0;
            int first=0, end=0;
            bool find_first = false;
            for(int k=p; k<=p+i; k++) {
                if(!find_first) {
                    if(arr[k] == 'G' || arr[k] == 'H') {
                        first = k;
                        find_first = true;
                    }
                }
                if(arr[k] == 'G') {
                    cnt_G++;
                    end = k;
                }
                if(arr[k] == 'H') {
                    cnt_H++;
                    end = k;
                }
            }
            if(cnt_G == 0 || cnt_H == 0 || cnt_G == cnt_H) {
                if(max_dist < end-first) max_dist = end-first;
            }
        }
    }
    cout << max_dist;
    return 0;
}