#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//	vector<int> answer;
//	vector<int> tmp;
//	for (int i = 0; i < commands.size(); i++) {
//		int s = commands[i][0] - 1;
//		int e = commands[i][1];
//		int t = commands[i][2] - 1;
//		tmp.clear();
//		for (int i = s; i < e; i++) {
//			tmp.push_back(array[i]);
//		}
//		sort(tmp.begin(), tmp.end());
//		answer.push_back(tmp[t]);
//		/*for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter)
//			cout << *iter << endl;*/
//	}
//	return answer;
//}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> tmp;
	for (int i = 0; i < commands.size(); i++) {
		tmp = array;
		sort(tmp.begin() + commands[i][0] - 1, tmp.begin() + commands[i][1]);
		answer.push_back(tmp[commands[i][0]] + commands[i][2] - 2);
	}
	return answer;
}
int main() {
	vector<int> a;
	vector<vector<int>> c;
	a.push_back(1);
	a.push_back(5);
	a.push_back(2);
	a.push_back(6);
	a.push_back(3);
	a.push_back(7);
	a.push_back(4);
	c.push_back({ 2, 5, 3 });
	c.push_back({ 4, 4, 1 });

	/*for (vector<int>::iterator iter = c[0].begin(); iter != c[0].end(); ++iter)
		cout << *iter << endl;*/
	for (int i = 0; i < c.size(); i++) {
		cout << solution(a, c)[i] << endl;
	}
	return 0;
}