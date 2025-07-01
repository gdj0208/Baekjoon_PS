#include <iostream>
#include <algorithm>
#include <limits>
#include <list>
#include <unordered_map>
#include <unordered_set>

#define null NULL
#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int number_of_vertics, number_of_lines, end_point;
    int lines[1000][1000] = {0};
    int s, p ,e , w;
    
    void init_lines();
    void get_all_pass();
    void print_all_lines();
    ll get_longest_way();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> number_of_vertics >> number_of_lines >> end_point;
    end_point--;
    
    //init_lines();
    
    for(int i = 0; i < number_of_lines; i++) {
        cin >> s >> e >> w;
        lines[s - 1][e - 1] = w;
    }
    
    //cout << "\n"; print_all_lines();
    get_all_pass();
    //cout << "\n"; print_all_lines();
    
    cout << get_longest_way();
}

void MainClass::init_lines() {
    /*
     lines = new int*[number_of_vertics];
     
     for(int y = 0; y < number_of_vertics; y++) {
         lines[y] = new int[number_of_vertics];
         
         for(int x = 0; x < number_of_vertics; x++) {
             lines[y][x] = 0;
         }
     }
     */
}

void MainClass::get_all_pass() {
    int start_line, end_line, straight_line;
    
    for(int p = 0; p < number_of_vertics; p++) {
        for(int s = 0; s < number_of_vertics; s++) {
            if(s == p) { continue; }
            
            for(int e = 0; e < number_of_vertics; e++) {
                if(p == e) { continue; }
                
                start_line = lines[s][p];
                end_line = lines[p][e];
                straight_line = lines[s][e];
                
                if(start_line == 0 or end_line == 0) { continue; }
                if(straight_line == 0 or start_line + end_line < straight_line) {
                    lines[s][e] = start_line + end_line;
                }
            }
        }
    }
}

void MainClass::print_all_lines() {
    for(int y = 0; y < number_of_vertics; y++) {
        for(int x = 0; x < number_of_vertics; x++) {
            cout << lines[y][x] << " ";
        }
        cout << "\n";
    }
}

ll MainClass::get_longest_way() {
    ll max = 0;
    ll start_line, end_line;
    
    for(int start_point = 0; start_point < number_of_vertics; start_point++) {
        if(start_point == end_point) { continue; }
        
        start_line = lines[start_point][end_point];
        end_line = lines[end_point][start_point];
        
        max = (start_line + end_line > max) ? start_line + end_line : max;
    }
    
    return max;
}
