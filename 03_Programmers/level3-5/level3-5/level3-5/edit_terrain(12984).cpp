#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>

using namespace std;

ll solution(vector<vector<int> > land, int P, int Q){
	ll answer = 0;
	vector<ll> v;
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			v.push_back(land[i][j]);
		}
	}
	sort(v.begin(), v.end());	// �� �������� ����
	// ���� ���� ���̷� ����� ��� ��� 
	// (���� ���� ���̶�� ���Ÿ� �ϸ�ȴ�)
	for (int i = 0; i < v.size(); i++)	
		answer += (v[i] - v[0]) * Q;

	ll tmp = answer;
	for (int i = 1; i < v.size(); i++) {
		int add = i; // i��° ��
		int del = v.size() - i; // ������ ��
		
		tmp += add * (v[i] - v[i - 1])*P;	// �� �߰���� ���
		tmp -= del * (v[i] - v[i - 1])*Q;	// �� ���ź�� ��ȯ
		answer = min(answer, tmp);
	}
	return answer;
}
int main() {
	cout << solution({ {4, 4, 3}, {3, 2, 2}, {2, 1, 0} }, 5, 3) << endl;
	return 0;
}