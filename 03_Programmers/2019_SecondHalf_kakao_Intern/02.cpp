#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(vector<string> a, vector<string> b) { return a.size() < b.size(); }
vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<string>> str;
	bool chk = false;
	string tmp = "";
	int idx = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		char c = s[i];
		if (c == '{') {
			chk = true;
			str.push_back(vector<string>());
		}
		else if (chk) {
			if (c == '}') {
				str[idx++].push_back(tmp);
				tmp.clear();
				chk = false;
			}
			else if(c==','){
				str[idx].push_back(tmp);
				tmp.clear();
			}
			else if (c != ',')tmp += c;
		}
	}	
	sort(str.begin(), str.end(), comp);
	string ans = "";
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < str[i].size(); j++) {
			if (ans.find(str[i][j]) == -1) {
				ans += str[i][j];
				ans += ',';
			}
		}
	}
	int start = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == ',') {
			answer.push_back(stoi(ans.substr(start, i - start)));
			start = i + 1;
		}
	}

	return answer;
}
int main() {
	string s = "{ {2},{2,1},{2,1,3},{2,1,3,4} }";
	//string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	//string s = "{{123}}";
	//string s = "{{20,111},{111}}";
	for (auto ans : solution(s))
		cout << ans << " ";
	return 0;
}