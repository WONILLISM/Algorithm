#include<iostream>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, answer;
	cin >> x >> y;
	if (x > 0 && y > 0)answer = 1;
	else if (x < 0 && y>0)answer = 2;
	else if (x < 0 && y < 0)answer = 3;
	else if (x > 0 && y < 0)answer = 4;
	cout << answer << endl;
	return 0;
}