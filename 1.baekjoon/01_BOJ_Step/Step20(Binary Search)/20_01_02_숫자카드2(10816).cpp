#include <iostream>
#include <algorithm> 
using namespace std;
int N, M, card, Left, Right;
int Card[500001];

int left_bound(int l, int r){
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (Card[mid] < card)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}
int right_bound(int l, int r){
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (Card[mid] <= card)
			l = mid + 1;
		else
			r = mid;
	}
	return r;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("02.in", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Card[i];
	sort(Card + 1, Card + N + 1);
	cin >> M;
	for (int i = 1; i <= M; i++){
		Left = 1;
		Right = N + 1;
		cin >> card;
		Left = left_bound(Left, Right);
		Right = right_bound(Left, Right);
		cout << Right - Left << ' ';
	}
}


//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int MAX = 500001;
//int Card[MAX];
//int Search[MAX];
//int N, M;
//int binarySearch(int left, int right, int count, int num) {
//	int mid = (left + right) / 2;
//	int result;
//	if (left > right) return count;
//	else {
//		if (Card[mid] > num) {
//			result = binarySearch(left, mid - 1, count, num);
//		}
//		else if (Card[mid] < num) {
//			result = binarySearch(mid + 1, right, count, num);
//		}
//		else {
//			result = binarySearch(left, mid - 1, count, num);
//			result += binarySearch(mid + 1, right, count, num);
//			result += 1;
//		}
//		return result;
//	}
//}
//
//int main(void) {
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//		scanf("%d", &Card[i]);
//	scanf("%d", &M);
//	for (int i = 0; i < M; i++)
//		scanf("%d", &Search[i]);
//	sort(Card, Card + N);
//	for (int i = 0; i < M; i++) {
//		int left = 0, right = N - 1;
//		int count = 0;
//		printf("%d ", binarySearch(left, right, 0, Search[i]));
//	}
//	printf("\n");
//	return 0;
//}

