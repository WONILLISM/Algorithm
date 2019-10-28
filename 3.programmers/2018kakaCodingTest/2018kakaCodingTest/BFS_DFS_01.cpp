#include<iostream>
#include<vector>
using namespace std;
int cnt;
void bruteForce(vector<int> &n,int t, int step, int sum) {
	if (step >= n.size()) {
		if (sum == t)cnt++;
		return;
	}
	bruteForce(n, t, step + 1, sum + n[step]);
	bruteForce(n, t, step + 1, sum - n[step]);
}
int solution(vector<int> numbers, int target) {
	bruteForce(numbers, target, 0, 0);
	return cnt;
}
int main() {
	vector<int> n;
	n.push_back(1);
	n.push_back(1);
	n.push_back(1);
	n.push_back(1);
	n.push_back(1);
	cout << solution(n, 3) << endl;
	return 0;
}