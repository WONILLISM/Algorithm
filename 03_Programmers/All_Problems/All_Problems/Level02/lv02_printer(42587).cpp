#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool check[100];// �˻��� �۾����� üũ
int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> temp = priorities;      // �켱���� ������ ����
	int p = priorities[location];       // ����
	int count = priorities.size();
	int i = 0, j = 0;
	int cp = 0;     // ���� �켱����

	sort(temp.begin(), temp.end(), greater<int>());
	cp = temp[i];

	while (count != 0) {
		if ((check[j] == false) && (cp == priorities[j])) {
			check[j] = true;
			count--;
			i++;
			//answer++;
			if ((cp == p) && (j == location))
				break;
			cp = temp[i];
		}
		j++;
		if (j == priorities.size())
			j = 0;

	}

	return answer = i;
}
int main() {
	cout << solution({ 1,1,9,1,1,1 },0) << endl;
	return 0;
}