#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//bool solution(vector<string> phone_book) {
//	bool answer = true;
//	sort(phone_book.begin(), phone_book.end());
//	for (vector<int>::size_type i = 0; i < phone_book.size(); ++i) {
//		for (int j = i + 1; j < phone_book.size(); ++j) {
//			if (phone_book[i][0] == phone_book[j][0] && phone_book[i].size() != phone_book[j].size())
//				for (int k = 1; k < 20; k++) {
//					if (phone_book[i][k] != phone_book[j][k]) {
//						answer = true;
//						break;
//					}
//					else return answer = false;
//				}
//		}
//	}
//	return answer;
//}
bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
			return false;
	}
	return answer;
}

int main() {
	freopen("phone.in", "r", stdin);
	vector<string> p;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		p.clear();
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			string s;
			cin >> s;
			p.push_back(s);
		}

		if (solution(p))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	/*p.push_back("9999999999");
	p.push_back("999999998");*/
	//p.push_back("789");
	if (solution(p))cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}