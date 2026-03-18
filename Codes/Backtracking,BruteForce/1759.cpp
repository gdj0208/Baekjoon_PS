#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <math.h>
#include <time.h>

#define size 15

using namespace std;

class MainClass {
public:
    void run();
private:
    int size_of_pw, size_of_key;
    char key[15];
    bool used[15] = {0};
    int num_of_vowel, num_of_con; // 모음 수, 자음 수
    
    void get_key();
    void get_all_possible_key(int latest_used_loc,int level);
    void print_key();
    bool is_vowel(char key);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    num_of_vowel = num_of_con = 0;
    
    get_key();
    get_all_possible_key(-1, 0);
}

void MainClass::get_key() {
    cin >> size_of_pw >> size_of_key;
    for(int i = 0; i < size_of_key; i++) { cin >> key[i]; }
    
    sort(key, key + size_of_key);
    //for(int i = 0; i < size_of_key; i++) { cout << key[i] << " "; }
    //cout << "\n";
}

void MainClass::get_all_possible_key(int latest_used_loc, int level) {
    int next_loc = latest_used_loc + 1;
    bool vowel;
    
    if(level == size_of_pw) { 
        if(num_of_vowel >= 1 and num_of_con >= 2) { print_key(); }
        return;
    }
    
    for(int i = next_loc; i < size_of_key; i++) {
        vowel = is_vowel(key[i]);
        
        if(vowel) { num_of_vowel++; }
        else { num_of_con++; }
        
        used[i] = true;
        get_all_possible_key(i, level + 1);
        used[i] = false;
        
        if(vowel) { num_of_vowel--; }
        else { num_of_con--; }
    }
}

void MainClass::print_key() {
    int count = 0;
    int loc = 0;
    
    while(count != size_of_pw) {
        if(used[loc]) { cout << key[loc]; count++; }
        loc++;
    }
    cout << "\n";
}

bool MainClass::is_vowel(char key) {
    switch (key) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}
