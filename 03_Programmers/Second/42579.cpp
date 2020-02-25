#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define PIS pair<int,string>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<PIS> v;	//�־��� �Է°� ������
	vector<PIS> tmp;
	vector<PII> max_value;

	for (int i = 0; i < genres.size(); i++)
		v.push_back({ plays[i],genres[i] });

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
			if (tmp[i].second == v[j].second)		//���� �帣��� max_value�� paly �� �� �ε����� �ִ´�
				max_value.push_back({ v[j].first, j });		// �÷��� Ƚ��, �ε���
		}
		sort(max_value.begin(), max_value.end(), greater<pair<int, int>>());	//idx ������ ����
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
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	solution(genres, plays);
	for (auto a : solution(genres, plays)) {
		cout<<a;
	}
	return 0;
}
//priority_queue<PIS> pq;  // �ش� �帣�� play �� ����, ���� ���� ����� �帣 �� ���� ���� ����
//vector<int> solution(vector<string> genres, vector<int> plays) {
//	vector<int> answer;
//	vector<PIS> v;
//	for (int i = 0; i < genres.size(); i++)
//		v.push_back({ plays[i],genres[i] });
//	
//	PIS cur = { plays[0],genres[0] };
//	genres.erase(genres.begin());
//	plays.erase(plays.begin());
//	pq.push(cur);
//	while (!pq.empty()) {
//		for (int j = 0; j < genres.size(); j++) {
//			cur = pq.top();
//			if (cur.second == genres[j]) {		// ���� �帣�� ���� �帣�� ���ٸ�
//				pq.pop();
//				cur.first += plays[j];		// ���� �ε����� �÷��� �� ����
//				genres.erase(genres.begin() + j);	// ���� �帣, �÷��� �� ����
//				plays.erase(plays.begin() + j);
//				j--;
//				pq.push(cur);
//			}
//		}
//	}
//	for (int i = 0; i < genres.size(); i++) {
//		PIS cur = { plays[i],genres[i] };
//		pq.push(cur);
//		for (int j = i + 1; j < genres.size(); j++){
//			cur = pq.top();
//			if (cur.second == genres[j]) {		// ���� �帣�� ���� �帣�� ���ٸ�
//				pq.pop();
//				cur.first += plays[j];		// ���� �ε����� �÷��� �� ����
//				genres.erase(genres.begin() + j);	// ���� �帣, �÷��� �� ����
//				plays.erase(plays.begin() + j);
//				j--;
//				pq.push(cur);
//			}
//		}
//
//	}
//	while (!pq.empty()) {
//		cout << pq.top().first <<" "<< pq.top().second << endl;
//		pq.pop();
//	}
//
//	return answer;
//}