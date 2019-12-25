#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	map <string, string> Map;
	queue<pair<string, string>> Q;
	for (int i = 0; i < record.size(); i++) {
		string tmp;
		vector<string> v;
		
		for (int j = 0; j < record[i].size(); j++) {
			if (record[i][j] == ' ') {
				v.push_back(tmp);
				tmp.clear();
			}
			else tmp.push_back(record[i][j]);
		}
		v.push_back(tmp);
		if (v[0] == "Enter") {
			Map[v[1]] = v[2];
			Q.push({ v[0], v[1] });
		}
		else if (v[0] == "Leave") {
			Q.push({ v[0],v[1] });
		}
		else //Change
		{
			Map[v[1]] = v[2];
		}
	}
	while(!Q.empty()){
		string commd = Q.front().first;
		string id = Q.front().second;
		string res;
		Q.pop();
		if (commd == "Enter") res = Map[id] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		else res = Map[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		answer.push_back(res);
	}
	return answer;
}
int main() {
	//freopen("01.in.txt", "r", stdin);
	vector<string> r;
	r.push_back("Enter uid1234 Muzi");
	r.push_back("Enter uid4567 Prodo");
	r.push_back("Leave uid1234");
	r.push_back("Enter uid1234 Prodo");
	r.push_back("Change uid4567 Ryan");
	vector<string> ans;
	ans = solution(r);
	for (int i = 0; i<ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}