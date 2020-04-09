#include<iostream>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 3001;
int prime[3000];// ture :  소수가 아니다
vector<int> Nums;
vector<int> v;
vector<int> visit;
int answer;
void checkPrimeNum() {
	prime[0] = true;
	prime[1] = true;
	
	int i = 2, j = 2;
	while (i*j < MAX) {
		for (int j = 2; j*i < MAX; j++)
			if (!prime[i*j])prime[i*j] = true;
		i++;
	}
}
void process(int i, int cnt) {
	if (cnt == 3) {
		int res = 0;
		for (int k = 0; k < v.size(); k++) 
			res += v[k];
		if (!prime[res]) {
			/*for (int k = 0; k < v.size(); k++)
				cout << v[k] << " ";

			cout << endl << answer<<endl;*/
			answer++;
		}
		return;
	}
	for(int j=i; j<Nums.size(); j++){
		if (!visit[j]) {
			visit[j] = true;
			v.push_back(Nums[j]);
			process(j, cnt + 1);
			v.pop_back();
			visit[j] = false;
		}
	}
}
int solution(vector<int> nums) {
	Nums = nums;
	visit.assign(nums.size(), 0);
	checkPrimeNum();
	
	process(0, 0);
	return answer;
}
int main() {
	cout << solution({ 1,2,7,6,4 });

	return 0;
}