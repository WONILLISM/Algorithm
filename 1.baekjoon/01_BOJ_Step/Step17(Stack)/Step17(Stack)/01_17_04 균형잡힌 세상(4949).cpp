#include<iostream>
#include<string>
#include<vector>
using namespace std;
string S;
vector<char> st;
void solution() {
	while(getline(cin,S)){
		bool chk = false;
		if (S[0] == '.')return;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '(' || S[i] == '[')st.push_back(S[i]);
			else if (S[i] == ']') {
				if (st.size() == 0) {
					chk = true;
					break;
				}
				else if (st.back()!= '[') {
					chk = true;
					break;
				}
				else st.pop_back();
			}
			else if (S[i] == ')') {
				if (st.size() == 0) {
					chk = true;
					break;
				}
				else if (st.back() != '(') {
					chk = true;
					break;
				}
				else st.pop_back();
			}
		}
		if(chk)cout << "no\n";
		else {
			if (st.empty())cout << "yes\n";
			else cout << "no\n";
		}
		st.clear();
		S.clear();
		chk = false;
	}
}
//int top = 0;
//int n = 0;
//void solution() {
//	bool chk = false;
//	char a;
//	a = getchar();
//	n++;
//	while (a!=EOF) {
//		if (a != '\n'&&a != '.') {
//			if (n == 1) {
//				if (a == ']')chk = false;
//				else if (a == ')')chk = false;
//			}
//			else chk = true;
//		}
//		else if (a != '\n'&&a == '.') {
//			if (!chk)return;
//			if (top)cout << "no\n";
//			else cout << "yes\n";
//		}
//		else if (a == '\n') {
//			for (int i = 0; i < top; i++)
//				st[i] = '\0';
//			top = 0;
//			n = 0;
//			chk = false;
//		}
//		if (a == '(' || a == '[') {
//			st[top++] = a;
//		}
//		if (a == ')') {
//			if (st[top - 1] == '(')st[top--] = '\0';
//		}
//		else if (a == ']') {
//			if (st[top - 1] == '[')st[top--] = '\0';
//		}
//		a = getchar();
//		n++;
//	}
//}
int main() {
	freopen("4949.in", "r", stdin);
	solution();
	return 0;
}