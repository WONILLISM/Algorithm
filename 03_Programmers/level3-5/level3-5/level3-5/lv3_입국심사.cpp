#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
vector<int> T;
int N;

//time으로 심사대에서 N명을 처리할수 있는가?
bool process(long long time) {
	long long tmp = 0;
	for (int i = 0; i < T.size(); i++)
		tmp += time / T[i];
	return tmp < N;
}
long long solution(int n, vector<int> times) {
	T = times, N = n;
	long long Low = 1, High =10000000000000LL;   //times.size * N
	while (Low <= High) {
		long long mid = (Low + High) / 2;
		if (!process(mid))High = mid - 1;
		else Low = mid + 1;
	}
	return Low;
}
int main() {
	vector<int> t;
	t.push_back(7);
	t.push_back(10);
	cout << solution(6, t);
	return 0;
}