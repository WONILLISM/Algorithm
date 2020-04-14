#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 6 5 3 1 0 
int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++)
		if (citations[i] < i + 1) return i;
	return citations.size();
}
int main() {
	cout << solution({ 3,0,6,1,5 }) << endl;
	return 0;
}