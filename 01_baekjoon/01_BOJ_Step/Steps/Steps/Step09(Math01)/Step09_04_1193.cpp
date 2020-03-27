/*4번부터 할 차례*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_1193();
int main() {
	solution_1193();
	return 0;
}
void solution_1193() {
	int N =0,i=0;
	scanf("%d", &N);
	while (N>0){
		N -= ++i;
	}
	int n = i + N;
	if (i % 2 == 0) printf("%d/%d\n", n, i - (n - 1));
	else printf("%d/%d\n", i - (n - 1), n);
}	