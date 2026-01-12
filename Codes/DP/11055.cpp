#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class MainClass {
public:
    void run();
private:
    int *arr, *count;
    int sizeOfArr;
    
    void get_arr();
    int get_sum_of_list(list<int> *li);
    void get_biggest();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    get_arr();
    get_biggest();
}

void MainClass::get_arr() {
    cin >> sizeOfArr;
    arr = (int*)calloc(sizeOfArr, sizeof(int));
    count = (int*)calloc(sizeOfArr, sizeof(int));
    for(int i = 0; i < sizeOfArr; i++) { cin >> arr[i]; count[i] = arr[i]; }
}

void MainClass::get_biggest() {
    int max = count[0];
    
    for(int i = 0; i < sizeOfArr; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) { 
                count[i] = (count[i] > count[j] + arr[i]) ? count[i] : count[j] + arr[i];
            }
        }
        max = (count[i] > max) ? count[i] : max;
    }
    
    cout << max;
}
