#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main() {
	map<int, string>a;
	int n;
	cout << "vvedite vmestimost portfelya: ";
	cin >> n;
	cout << "enter coast,name and weight (for stop enter 0):" << endl;
	while(true){
		int key;
		string value;
		cout << "enter coast or 0 for end:" << endl;
		cin >> key;
		if (key == 0) {
			break;
		}
		cout << "enter weight and name" << endl;
		cin.ignore();
		getline(cin, value);
		a[key] = value;
	}
	map<int, string>b;
	auto it=a.rbegin();
	for (int i = 0; i < n && it != a.rend(); ++it, ++i) {
		b[it->first] = it->second;
	}

	for (const auto& pair : b) {
		cout << "coast: " << pair.first << ",value: " << pair.second << endl;
	}
	return 0;
}