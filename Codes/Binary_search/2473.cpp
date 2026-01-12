#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <utility>

#define ll long long
#define INF 1e16

#define SWAP(a, b) do { auto temp = (a); (a) = (b); (b) = temp; } while (0)

using namespace std;

class Alg {
private:
    ll arr[5000] = {0};
    int size_of_arr;
    
public:
    void run();
    
private:
    void solve();
    void init_arr();
    void quicksort(ll* arr, int low, int high);
    int partition(ll* arr, int low, int high);
    void print_arr();
    void find_num();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    init_arr();
    solve();
}

void Alg::init_arr() {
    cin >> size_of_arr;
    for(int i = 0; i < size_of_arr; i++) { cin >> arr[i]; }
}

void Alg::solve() {
    quicksort(arr, 0, size_of_arr - 1);
    //print_arr();
    find_num();
}

void Alg::quicksort(ll* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int Alg::partition(ll* arr, int low, int high) {
    ll pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Alg::print_arr() { for(int i = 0; i < size_of_arr; i++) { cout << arr[i] << " "; } }

void Alg::find_num() {
    ll closestSum = INF;
    ll sum;
    
    ll closestTriple[3];

    for (int i = 0; i < size_of_arr - 2; ++i) {
        int left = i + 1;
        int right = size_of_arr - 1;

        while (left < right) {
            sum = arr[i] + arr[left] + arr[right];

            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                closestTriple[0] = arr[i];
                closestTriple[1] = arr[left];
                closestTriple[2] = arr[right];
            }

            if (sum < 0) { ++left; }
            else { --right; }
        }
    }
    
    for(auto i : closestTriple) { cout << i << " "; }
}

/*
 3
 1000000000 1000000001 1000000002
 */
