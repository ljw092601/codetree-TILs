#include <iostream>
#include <vector>
using namespace std;

int main() {
    int people_num, cheese_num, eat_num, ill_num;
    cin >> people_num >> cheese_num >> eat_num >> ill_num;
    vector<int> people(eat_num, 0);
    vector<int> cheess(eat_num, 0);
    vector<int> eat_time(eat_num, 0);
    for (int i=0; i<eat_num; i++) {
        cin >> people[i] >> cheess[i] >> eat_time[i];
    }
    vector<int> ill_people(ill_num, 0);
    vector<int> ill_time(ill_num, 0);
    for (int i=0; i<ill_num; i++) {
        cin >> ill_people[i] >> ill_time[i];
    }

    int max_med = 1;
    for(int i=1; i<=cheese_num; i++) {
        int how_many_eat = 0;
        for(int p=0; p<ill_num; p++) {
            for (int k=0; k<eat_num; k++) {
                if(cheess[k] == i && people[k] == ill_people[p] && eat_time[k] < ill_time[p]) how_many_eat++;
            }
        }
        if (how_many_eat == ill_num) {
            vector<bool> need_med_people(people_num, false);
            for (int k=0; k<eat_num; k++) {
                if(cheess[k] == i) need_med_people[people[k]-1] = true;
            }
            int need_med = 0;
            for (bool ill : need_med_people) {
                if(ill) need_med++;
            }
            if(max_med < need_med) max_med = need_med;
        }
    }

    cout << max_med;

    return 0;
}