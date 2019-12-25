#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
//1 1 2 3 6 7 30
int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());
	int Sum = 0;
	for (int i = 0; i < weight.size(); i++) {
		if (Sum + 1 >= weight[i]) Sum += weight[i];
		else break;
	}
	return Sum + 1;
}
int main() {
	vector<int> w = { 3,1,6,2,7,30,1 };
	cout << solution(w);
	return 0;
}