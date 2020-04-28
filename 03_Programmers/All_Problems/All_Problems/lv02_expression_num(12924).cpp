#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 1;
	int l = 0, r = 0;
	int sum = 0;
	while (r < n) {
		if (sum < n) {
			sum += ++r;
		}
		else if (sum == n) {
			answer++;
			sum += ++r;
		}
		else {
			sum -= ++l;
		}
	}
	return answer;
}
int main() {
	cout << solution(15) << endl;
	cout << solution(10000) << endl;	
	return 0;
}

//for (int i = 1; i <= n; i++) {
//	int sum = 0;
//	for (int j = i; j <= n; j++) {
//		sum += j;
//		if (sum == n) {
//			answer++;
//			break;
//		}
//		else if (sum > n)
//			break;
//	}
//}