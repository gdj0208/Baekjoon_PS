#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int number_of_vertics, number_of_edges, search_range;
    int graph[100][100] = {0};
    int vertic[100] = {0};
    
    void init_graph();
    void renew_graph();
    void print_graph();
    void check_area();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_graph();
    renew_graph();
    //print_graph();
    check_area();
}

void MainClass::init_graph() {
    int v1, v2, weight;
    
    cin >> number_of_vertics >> search_range >> number_of_edges;
    
    for(int i = 0; i < number_of_vertics; i++) {
        cin >> vertic[i];
    }
    
    for(int i = 0; i < number_of_edges; i++) {
        cin >> v1 >> v2 >> weight;
        graph[v1-1][v2-1] = graph[v2-1][v1-1] = weight;
    }
}

void MainClass::renew_graph() {
    int w1, w2;
    
    for(int pass = 0; pass < number_of_vertics; pass++) {
        for(int start = 0; start < number_of_vertics; start++) {
            if(pass == start) { continue; }
            
            for(int end = 0; end < number_of_vertics; end++) {
                if(end == pass or end == start) { continue; }
                
                w1 = graph[start][pass];
                w2 = graph[pass][end];
                
                if(w1 == 0 or w2 == 0) { continue; }
                if(graph[start][end] > (w1 + w2) or graph[start][end] == 0) { graph[start][end] = w1 + w2; }
                
            }
        }
    }
}

void MainClass::print_graph() {
    for(int start = 0; start < number_of_vertics; start++) {
        for(int end = 0; end < number_of_vertics; end++) {
            cout << graph[start][end] << " ";
        }
        cout << "\n";
    }
}

void MainClass::check_area() {
    int sum = 0;
    int max = 0;
    
    for(int start = 0; start < number_of_vertics; start++) {
        sum = vertic[start];
        for(int end = 0; end < number_of_vertics; end++) {
            if(graph[start][end] != 0 and graph[start][end] <= search_range) { sum += vertic[end]; }
        }
        max = (max < sum) ? sum : max;
    }
    
    cout << max;
}
