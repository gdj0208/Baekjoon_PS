#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>


using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<string>str;
    int size;
    
    void init_str();
    void sort_str();
    void print();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    int N;
    cin >> N;

    set<string> uniqueWords;
    vector<string> words;

    // 입력 받기
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        uniqueWords.insert(word);
    }

    // set을 vector로 변환 (정렬을 위해)
    words.assign(uniqueWords.begin(), uniqueWords.end());

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.size() == b.size()) { return a < b; }
        return a.size() < b.size();
    });

    // 출력
    for (const string& word : words) {
        cout << word << '\n';
    }
}
