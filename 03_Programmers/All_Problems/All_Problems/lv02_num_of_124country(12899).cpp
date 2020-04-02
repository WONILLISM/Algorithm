#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[3] = { 1,2,4 };
string solution(int n) {
	string answer = "";
	int r = -1;
	while (n--) {
		r = n % 3;
		answer += to_string(arr[r]);
		n = n / 3;
	}

	reverse(answer.begin(), answer.end());

	return answer;
}
int main() {
	cout << solution(10) << endl;
	return 0;
}