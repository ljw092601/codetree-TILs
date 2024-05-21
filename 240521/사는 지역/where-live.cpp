#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Address {
    string name;
    string number;
    string city;
};

int main() {
    int n;
    cin >> n;
    vector<Address> address_vec;
    while(n--) {
        Address people;
        cin >> people.name >> people.number >> people.city;
        address_vec.push_back(people);
    }
    
    sort(address_vec.begin(), address_vec.end(), [](Address a, Address b){
        return a.name > b.name;
    });

    cout << "name " << address_vec[0].name << endl
        << "addr " << address_vec[0].number << endl
        << "city " << address_vec[0].city << endl;
    return 0;
}