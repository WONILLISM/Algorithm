#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_1002() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x1, y1, d1, x2, y2, d2;
		scanf("%d%d%d", &x1, &y1, &d1);
		scanf("%d%d%d", &x2, &y2, &d2);
		int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		int sum = (d1 + d2)*(d1 + d2);	//두 거리의 합
		int dif = (d1 - d2)*(d1 - d2);  //두 거리의 차
		
		//두 원의 중심이 일치할 때
		if (d == 0) {
			if (dif == 0) printf("-1\n"); //두 원이 일치할 때
			else printf("0\n"); //두 원이 일치하지 않을 때
		}
		else if (d == sum || d == dif)printf("1\n");  //외접할 때, 내접할 때
		else if (dif < d&&d < sum) printf("2\n");  //두 점에서 만날 때
		else printf("0\n");  //만나지 않을 때
	}
}
int main() {
	solution_1002();
	return 0;
}