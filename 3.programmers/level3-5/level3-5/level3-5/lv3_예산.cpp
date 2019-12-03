#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정합니다.
2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정합니다.
   상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정합니다.
   110 120 140 150
   485  -> 121
   520  -> 130
*/
int solution(vector<int> budgets, int M) {
	int size = budgets.size();
	long long sum = 0;
	sort(budgets.begin(), budgets.end());
	for (int i = 0; i < size; i++)
		sum += budgets[i];
	if (sum < M)return budgets[size - 1];
	long long avg = sum / size;
	long long sum1 = 0;
	long long avg1 = M / size;

	for (int i = 0; i < budgets.size(); i++) {
		if (budgets[i] > avg1)return avg1;
		sum1 += budgets[i];
		size--;
		avg1 = (M - sum1) / size;
	}
}
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

//int solution(vector<int> budgets, int M) {
//	int size = budgets.size();
//	long long sum = 0;
//	sort(budgets.begin(), budgets.end());
//	for (int i = 0; i < budgets.size(); i++)
//		sum += budgets[i];
//	if (sum < M) return budgets[size - 1];
//
//	long long avg = sum / size;
//	long long sum1 = 0;
//	long long avg1 = M / size;
//
//	for (int i = 0; i < budgets.size(); i++) {
//		if (budgets[i] > avg1) return avg1;
//		sum1 += budgets[i];
//		size--;
//		avg1 = (M - sum1) / size;
//	}
//}
