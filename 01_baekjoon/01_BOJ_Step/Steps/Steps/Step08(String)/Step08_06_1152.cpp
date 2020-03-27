#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
using namespace std;

void solution_1152();
int main() {
	solution_1152();
	return 0;
}
void solution_1152()
{
	/*const int MAX = 1000002;
	char a[MAX];
	fgets(a, MAX, stdin);
	int len = 0;
	int cnt = 0;
	while (1) {
		if (a[len] == '\n')break;
		if (len > 0 && a[len] == ' ') cnt++;
		len++;
	}
	if (a[len - 1] == ' ') printf("%d", cnt);
	else printf("%d", cnt + 1);*/

	//string s;
	//getline(cin, s);
	//vector<string> v;
	//string tmp;
	//for (int i = 0; i < s.size(); i++) {
	//	if (i!=0&&s[i] == ' ') {
	//		v.push_back(tmp);
	//		tmp.clear();
	//	}
	//	else if(s[i]!=' ')tmp.push_back(s[i]);
	//}
	//if (tmp.size() > 0)v.push_back(tmp);
	//cout << v.size() << endl;

	/*int ans = 0;

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (i != 0 && i != s.size() - 1)
				ans++;
		}
	}
	if (s.size() == 1 && s[0] == ' ') { cout << ans << endl; }
	else cout << ans + 1 << endl;*/

	int ans = 0, len = 0;
	char s[1000002];
	fgets(s, 1000002, stdin);
	for (int i = 0; s[i] != '\n'; i++) {
		len++;
		if (i != 0 && s[i + 1] != '\n'&&s[i] == ' ')ans++;
	}
	if (len == 1 && s[0] == ' ') { cout << ans << endl; }
	else cout << ans + 1 << endl;
}