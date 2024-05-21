#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct Weather_data {
    Date day;
    string week_day;
    string weather;
};

Date string_to_date(const string date) {
    Date ymd;
    ymd.year = stoi(date.substr(0,4));
    ymd.month = stoi(date.substr(5,2));
    ymd.day = stoi(date.substr(8,2));
    return ymd;
}

bool a_is_faster (Date a, Date b) {
    if(a.year < b.year) return true;
    else {
        if (a.year == b.year) {
            if (a.month < b.month) return true;
            else{
                if(a.month == b.month) {
                    if (a.day < b.day) return true;
                }
            }
        }
    }
    return false;
}

void print_weather_data(Weather_data data) {
    cout << data.day.year << "-" 
    << std::setw(2) << std::setfill('0') << data.day.month << "-" 
    << std::setw(2) << std::setfill('0') << data.day.day
    << " " << data.week_day << " " << data.weather;
}

int main() {
    int n;
    cin >> n;
    vector<Weather_data> weather_vec;
    while(n--) {
        string s_date;
        Weather_data day_info;
        cin >> s_date >> day_info.week_day >> day_info.weather;
        day_info.day = string_to_date(s_date);
        if(day_info.weather == "Rain") weather_vec.push_back(day_info);
    }
    sort(weather_vec.begin(), weather_vec.end(), [](auto a, auto b){
        return a_is_faster(a.day, b.day);
    });
    print_weather_data(weather_vec[0]);
    return 0;
}