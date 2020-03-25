#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	queue<PII> q;
	for (int i = 0; i < food_times.size(); i++)
		q.push({ i + 1,food_times[i] });

	while (q.size() != 0 && k > 0) {	// ���� ������ ���ų� , �ð��� �� ������ ����
		ll size = q.size();
		ll eat = k / size;
		k %= size;	// �� ���� ���� �� �ִ� �� �����ϰ� ����

		if (eat == 0)break;	// �� �̻� �� ���� ���� �� ������ ����

		ll rest = 0;
		for (int i = 0; i < size; i++) {
			PII a = q.front();
			q.pop();
			a.second -= eat;
			if (a.second <= 0)	// ������ �� �Ծ��ٸ�
				rest -= a.second;	// �ʰ��� �ð� ��ŭ ����
			else
				q.push(a);
		}
		k += rest;
	}
	if (q.empty())return -1;	// �� �̻� ���� ������ ������
	else {
		if (k > 0) {			// �ð��� ���Ҵٸ�
			while (!q.empty()) {	// �ð��� ���� �� �׶��� idx�� ��ȯ
				--k;
				if (k == -1)return q.front().first;
				q.pop();
			}
		}
		else return q.front().first;
	}
	
	return answer;
}
int main() {
	cout << solution({ 3,1,2 }, 5) << endl;
	return 0;
}