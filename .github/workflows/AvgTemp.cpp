#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& vect){
	for(auto k : vect){
		cout << k << " ";
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	
	int sum = 0;
	for (auto& k : v){
		cin >> k;
		sum += k;
	}
	
	int mean_arithm = sum/n;
	
	vector<int> tmp;
	int counter = 0;
	for (int i = 0; i < n; ++i){
		if (v[i] > mean_arithm){
			++counter;
			tmp.push_back(i);
		}
	}
	
	cout << counter << endl;
	PrintVector(tmp);
	
	return 0;
}


