#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

int solution(vector<int> nums){
	int answer = 0;
	unordered_set<int> s;
	for (auto res : nums) 
		if (!s.count(res)) 
			s.insert(res);
	int n = s.size();
	int r = nums.size() / 2;

	if (n<r) answer = n;
	else answer = r;
	return answer;
}
int main() {
	cout << solution({ 3,1,2,3}) << endl;
	return 0;
}
//
//int solution(vector<int> nums) {
//	int answer = 0;
//	int get = nums.size() / 2;
//	int kind = 1;
//	sort(nums.begin(), nums.end());
//	for (int i = 1; i < nums.size(); i++) {
//		if (nums[i] != nums[i - 1])
//			kind++;
//	}
//	if (get <= kind)answer = get;
//	else answer = kind;
//	return answer;
//}