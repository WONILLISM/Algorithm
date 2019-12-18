#include <cstdio>
//#include<iostream>
#include <cstring>
//#include <algorithm>

using namespace std;
int N, x, ans;
char s[15];

void solution() {
	while (N--) {
		scanf("%s", &s);
		if (s[2] == 'd') {	//add
			scanf("%d", &x);
			int a = 1 << (x - 1);
			ans = ans | a;
		}
		else if (s[2] == 'm') {	//remove
			scanf("%d", &x);
			int a = 1 << (x - 1);
			ans = ans ^ a;
		}
		else if (s[2] == 'e') {	//check
			scanf("%d", &x);
			int a = 1 << (x - 1);
			if (ans&a)printf("1\n");
			else printf("0\n");
		}
		else if (s[2] == 'g') {	//toggle
			scanf("%d", &x);
			int a = 1 << (x - 1);
			if (ans&a)ans = ans ^ a;//ans = ans & ~a;
			else ans = ans | a;
		}
		else if (s[2] == 'l') {	//all
			ans = (1 << 20) - 1;
		}
		else if (s[2] == 'p') {	//empty
			ans = 0;
		}
	}
	
}
int main() {
	freopen("01.in", "r", stdin);
	scanf("%d", &N);
	solution();
	return 0;
}