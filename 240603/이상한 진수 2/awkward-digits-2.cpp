#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    string bin;
    cin >> bin;
    bool all_one = true;
    for (char& c : bin) {
        if (c == '0') {
            c = '1';
            all_one = false;
            break;
        }
    }
    if(all_one) *(bin.end()-1) = '0';
    bitset<64> binset(bin);
    unsigned long long deci = binset.to_ullong();
    cout << deci;
    return 0;
}