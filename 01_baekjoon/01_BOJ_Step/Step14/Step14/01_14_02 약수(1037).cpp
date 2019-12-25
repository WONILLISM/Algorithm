#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> num;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}
	sort(num.begin(), num.end());
	cout << num[0] * num[N - 1] << "\n";	
	return 0;
}