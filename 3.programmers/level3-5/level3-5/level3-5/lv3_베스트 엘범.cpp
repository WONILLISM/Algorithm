#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
/*
���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
*/
//typedef struct box1 {	int sum;	string s;};
////bool compare1(box1 a, box1 b) {	return a.sum < b.sum;}
//typedef struct box2 { int plays, idx; };
////bool compare2(box2 a, box2 b) { return a.idx < b.idx; };
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair <string, int>> v;	//�־��� �Է°� ������
	vector<pair<int,string>> tmp;
	vector<pair<int,int>> max_value;

	for (int i = 0; i < genres.size(); i++)
		v.push_back({ genres[i], plays[i] });

	for (int i = 0; i < genres.size(); i++) {
		tmp.push_back({ plays[i], genres[i] });
		for (int j = i + 1; j < genres.size(); j++) {	
			if (genres[i] == genres[j]) {	//���� �帣�� ���� �帣�� ���ٸ� tmp�� �������ش�.
				tmp[i].first += plays[j];
				genres.erase(genres.begin() + j); //j��° �帣�� �÷��� ���� �����.
				plays.erase(plays.begin() + j);
				j--;
			}
		}
	}
	sort(tmp.begin(), tmp.end(), greater<pair<int, string>>());

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (tmp[i].second == v[j].first)		//���� �帣��� max_value�� paly �� �� �ε����� �ִ´�
				max_value.push_back({ v[j].second, j });
		}
		sort(max_value.begin(), max_value.end(), greater<pair<int,int>>());	//idx ������ ����
		if (max_value.size() >= 2) {
			if (max_value[0].first == max_value[1].first) {	//������ �ε����� ���������� Ǫ��
				answer.push_back(max_value[1].second); 
				answer.push_back(max_value[0].second);
			}
			else {
				answer.push_back(max_value[0].second); 
				answer.push_back(max_value[1].second);
			}
		}
		else answer.push_back(max_value[0].second);	
		max_value.clear();
	}
	return answer;
}
int main() {
	vector<string> g = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> p = { 500, 600, 150, 800, 2500 };
	vector<int> ans=solution(g, p);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
	return 0;
}