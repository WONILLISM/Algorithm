#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> solution(int brown, int red) {
	vector<int> answer;
	int n, w, h;
	for (int i = 1; i <= 1414; i++) {
		if (red%i == 0) {
			n = red / i;
			if (brown == 2 * n + 2 * i + 4) {
				h = i + 2, w = n + 2;
				answer.push_back(w);
				answer.push_back(h);
				break;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> a;
	a = solution(24, 24);
	
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	return 0;
}