#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K, Min = 100000;
int idx, answer;

void solution() {
	K--;
	int len;
	if (idx > 0) {
		len = idx;
		answer += len % K == 0 ? len / K : (len / K) + 1;
	}
	len = N - idx + 1;
	answer += len % K == 0 ? len / K : (len / K) + 1;

	cout << answer << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (Min > a) {
			Min = a;
			idx = i;
		}
	}
	solution();
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int N, K, Min = 100000;
//vector<int> v;
//int idx, answer;
//
//void solution() {
//	int l = idx + 1 - K-1;
//	answer++;
//	if (l > 0) {
//		answer += l % (K - 1) == 0 ? l / (K - 1) : (l / (K - 1)) + 1;
//	}
//	int r = N - (idx + 1);
//	r -= K-1;
//	answer++;
//	if (r >0) {
//		answer += r % (K - 1) == 0 ? r / (K - 1) : (r / (K - 1)) + 1;
//	}
//	cout << answer << endl;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cout.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		int a; cin >> a;
//		v.push_back(a);
//		if (Min > a) {
//			Min = a;
//			idx = i;
//		}
//	}
//	solution();
//}