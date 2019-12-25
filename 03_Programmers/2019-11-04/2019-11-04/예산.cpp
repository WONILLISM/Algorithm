#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int solution(vector<int> budgets, int M) {
	int size = budgets.size();
	long long sum = 0;
	sort(budgets.begin(), budgets.end());
	for (int i = 0; i < budgets.size(); i++) 
		sum += budgets[i];
	if (sum < M) return budgets[size - 1];

	long long avg = sum / size;
	long long sum1 = 0;	
	long long avg1 = M / size;

	for (int i = 0; i < budgets.size(); i++) {
		if (budgets[i] > avg1) return avg1;
		sum1 += budgets[i];
		size--;
		avg1 = (M - sum1) / size;
	}
}
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int numbers = budgets.size();

	sort(budgets.begin(),budgets.end());

	for(auto itr=budgets.begin(); itr!= budgets.end(); itr++){
		if(*itr > (M / numbers)) return M/numbers;
		else{
			M -= *itr;
			numbers--;
		}
	}

	return budgets.back();
}
*/
int main() {
	vector<int> b;
	int m = 485;
	b.push_back(120);
	b.push_back(110);
	b.push_back(140);
	b.push_back(150);
	cout << solution(b, m) << endl;
	return 0;
}