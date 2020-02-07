#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int solution(vector<int> budgets, int M) {
	int size = budgets.size(); //지방의 수
	ll total = 0;	//지방 예산 총합
	for (auto b : budgets)
		total += b;
	sort(budgets.begin(), budgets.end()); //오름차순 정렬
	
	if (total <= M) return budgets[size - 1];
	ll avg = M / size; //국가 예산의 평균 (121)
	ll sum = 0; 

	/*
	 110 / 120 / 140 / 150
	*/
	for (auto b : budgets) {
		if (b > avg)return avg;
		sum += b;
		size--;
		avg = (M - sum) / size;
	}
}
int main() {
	vector<int> budgets = { 120,110,140,150 };
	cout << solution(budgets, 485) << endl;
	return 0;
}