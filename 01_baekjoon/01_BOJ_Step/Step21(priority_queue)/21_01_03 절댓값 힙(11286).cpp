//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//int N;
//typedef struct pri_Q {
//	int x;
//	bool operator<(const pri_Q &n)const {
//		int a = x > 0 ? x : -x;
//		int b = n.x > 0 ? n.x : -n.x;
//		if (a == b) {
//			if (x < n.x)return true;
//			else false;
//		}
//		else if (a < b)return true;
//		else return false;
//	}
//};
//
//void solution() {
//	priority_queue<pri_Q> pq;
//	while (N--) {
//		int x;
//		cin >> x;
//		if (x == 0) {
//			if (pq.empty())cout << "0" << endl;
//			else {
//				cout << pq.top().x << endl;
//				pq.pop();
//			}
//		}
//		else pq.push({ x });
//	}
//}
//int main() {
//	freopen("03.in", "r", stdin);
//	cin >> N;
//	solution();
//	return 0;
//}
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<pair<int, int> > pq;
int n, x;
int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &x);
		if (x) pq.push({ -abs(x),-x });
		else if (pq.empty()) puts("0");
		else printf("%d\n", -pq.top().second), pq.pop();
	}
	return 0;
}
