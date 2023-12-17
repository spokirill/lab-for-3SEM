#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "¬ведите количество элементов последовательности: ";
    cin >> N;
    
    vector<int> s;
    vector<int>arr;
    cout << "¬ведите элементы последовательности:" << endl;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s.push_back(a);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] + 1 == s[i + 1]) {
            arr.push_back(s[i]);
        }
        else { break; }
    }
   
    int size = arr.size();
    cout << "ƒлина : " << size << endl;
    cout << " подпоследовательность: ";
    for (int i = 0; i < arr.size();i++ ) {
        cout << arr[i]<<" ";
          }
    cout << endl;

    return 0;
}
