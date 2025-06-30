#include <iostream>
#include <algorithm>
#include <math.h>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int number_of_station, number_of_buses;
    int lines[100][100] = {0};
    
    void init_line();
    void get_all_possible_lines();
    void print_all_lines();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_line();
    //print_all_lines();
    get_all_possible_lines();
    print_all_lines();
}

void MainClass::init_line() {
    int start, end, weight;
    
    cin >> number_of_station >> number_of_buses;
    for(auto i = 0; i < number_of_buses; i++) {
        cin >> start >> end >> weight;
        if(lines[start-1][end-1] == 0 or lines[start-1][end-1] > weight) { lines[start-1][end-1] = weight; }
    }
}

void MainClass::get_all_possible_lines() {
    int w, in, out;
    
    for(auto pass = 0; pass < number_of_station; pass++) {
        for(auto start = 0; start < number_of_station; start++) {
            if(start == pass) { continue; }
            
            for(auto end = 0; end < number_of_station; end++) {
                
                if(start == end or pass == end) { continue; }
                
                in = lines[start][pass];
                out = lines[pass][end];
                
                if(in == 0 or out == 0) { continue;; }
                
                w = lines[start][pass] + lines[pass][end];
                if(lines[start][end] > w or lines[start][end] == 0) { lines[start][end] = w; }
            }
        }
    }
    
}

void MainClass::print_all_lines() {
    for(auto start = 0; start < number_of_station; start++) {
        for(auto end = 0; end < number_of_station; end++) { 
            if(lines[start][end] == 0) { cout << "0 "; }
            else { cout << lines[start][end] << " "; }
        }
        cout << "\n";
    }
}
