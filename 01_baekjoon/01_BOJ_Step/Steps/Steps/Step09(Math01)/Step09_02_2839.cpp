#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_2839();
int main() {
	solution_2839();
	return 0;
}
void solution_2839() {
	/*---------------------------------------------
	 *5로 나누었을 때 나누어 떨어진다면 그대로 출력
	 *그렇지 않다면 -3을 하고 카운트 +1
	 *반복
	 ----------------------------------------------*/
	int n;
	int cnt = 0;
	scanf("%d", &n);
	while (1) {
		if (n % 5 == 0) {
			cnt += n / 5;
			printf("%d", cnt);
			break;
		}
		else if (n <= 0) {
			printf("-1");
			break;
		}
		else {
			n -= 3;
			cnt++;
		}
	}
}	