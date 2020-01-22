#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

//�۾��ð��� ���� ���� �� ����
struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};
int solution(vector<vector<int>> jobs) {
	int answer = 0, idx = 0, time = 0;
	//��û�ð��� ���� ������ ����
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //�켱���� ť min heap
	//��⿭�� ���� �켱���� ť�� �������� �ݺ�
	while (idx < jobs.size() || !pq.empty()) {
		//���� ��⿭�� �����ְ�, ��ũ�ð����� �۰ų� ���ٸ�
		if (jobs.size() > idx && time >= jobs[idx][0]) {
			//�켱���� ť�� �߰�
			pq.push(jobs[idx++]);
			//�ε��� ����
			//�����ð��뿡 �ٸ��۾� �ٽ� Ȯ��
			continue;
		}
		//ť�� ������� �ʴٸ�
		if (!pq.empty()) {
			//�ð��� ���۾��� ���������� �ɸ��� �ð���ŭ �߰�
			time += pq.top()[1];
			//�۾��ð��� ��� �ð���ŭ �߰�(����ð� - ���� �ð�)
			answer += time - pq.top()[0];
			//�۾� ����
			pq.pop();
		}
		else //ť�� ����ִٸ� �����۾� �ð����� �ѱ�
			time = jobs[idx][0];
	}
	return answer / jobs.size();
}
int main(){
	cout << solution({ {0,3},{1,9},{2,6} });
	return 0;
}