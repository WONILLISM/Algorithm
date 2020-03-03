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

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	int start = 1;			// ������
	int end = distance;		// ����

	// �̺�Ž�� ����
	while (start <= end) {
		int mid = (start + end) / 2;
		int del = 0;			// ���� ���� ����
		int lastIdx = -1;		
		
		//cout << "������: " << start << " ����: " << end << " �߰���: " << (start + end) / 2 << endl;
		for (int i = 0; i <= rocks.size(); i++) {
			int d;				// �� ���� ������ �Ÿ�
			if (lastIdx == -1)d = rocks[i]; 
			else {
				if (i == rocks.size())d = distance - rocks[lastIdx];
				else d = rocks[i] - rocks[lastIdx];
			}
			// if (mid == 12) cout << "i: " << i << " lstidx: " << lastIdx << " d: " << d << endl;
			if (d < mid)del++;		// �� ���� ������ �Ÿ��� mid ���� ������ ���� �ϳ� ����
			else lastIdx = i;		// mid ���� �̻� Ž�� �ߴٸ� �ε��� ��ü
		}
		 //cout << del << endl;
		if (del > n) end = mid - 1;	// ���� ���� ���� n���� ������ ���� = mid - 1
		else if(del<=n){
			start = mid + 1;			// ���� ���� ���� n���� �۰ų� ������ ������ = mid + 1
			answer = mid;
		}
	}

	return answer;
}
int main() {
	//cout << solution(25, { 2,14,11,21,17 }, 2) << endl;
	//cout << solution(34, { 5,19,28 }, 2) << endl;
	cout << solution(1234, { 1,2,3 }, 3) << endl;
	return 0;
}