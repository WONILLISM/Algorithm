#include<iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 10000000;
int prime[MAX];
string nums;
vector<bool> chk;
string ans;
int answer;
void checkPrimeNum() {
	prime[0] = 1;
	prime[1] = 1;

	int i = 2, j = 2;
	while (i*j < MAX) {
		for (int j = 2; j*i < MAX; j++)
			if (!prime[i*j])prime[i*j] = 1;
		i++;
	}
}
void process(int i, int cnt) {
	if (cnt > nums.size())return;
	if (cnt > 0) {
		int res = stoi(ans);
		if (!prime[res]) {
			answer++;
			prime[res] = 2;//한 번 찾았으면 2로 바꿔줌
		}
	}

	for (int j = 0; j < nums.size(); j++) {
		if (!chk[j]) {
			chk[j] = true;
			ans.push_back(nums[j]);
			process(j, cnt + 1);
			ans.pop_back();
			chk[j] = false;
		}
	}
}
int solution(string numbers) {
	nums = numbers;
	chk.assign(nums.size(), false);
	checkPrimeNum();
	process(0, 0);
	return answer;
}
int main() {
	cout << solution({ "011" }) << endl;
	return 0;
}