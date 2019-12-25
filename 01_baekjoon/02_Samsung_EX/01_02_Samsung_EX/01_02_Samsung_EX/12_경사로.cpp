#include <iostream>
using namespace std;

const int MAX = 100;
int N, L, ans;
int Map[MAX][MAX];

void Input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
}
/*
D�� 0�̶��, ���� ���̰� ���� ����̴�.
D�� 1�̶��, �ö󰡴� ���ΰ� �ʿ��� ����̴�.
D�� -1�̶��, �������� ���ΰ� �ʿ��� ����̴�.
���� ���̰� ���ٸ� (D == 0), ī��Ʈ�� 1 ������Ų��. ī��Ʈ�� ������ ���̿� ���ϱ� ���� �ʿ��ϴ�.
�ö󰡴� ���ζ�� (D == 1), ī��Ʈ�� ������ ���� L �̻����� Ȯ���Ѵ�. ī��Ʈ�� L �̻��̶��,
���θ� ���� �� �ִ� ����̹Ƿ�, ī��Ʈ�� 1�� �ʱ�ȭ��Ų��.
�������� ���ζ�� (D == -1), ī��Ʈ�� 0 �̻����� Ȯ���Ѵ�. 
0 �̻��̶��, ī��Ʈ�� ������ ���� L��ŭ�� ������ �����. 
���� ī��Ʈ�� �������, �������� ���θ� ����� �ִ� ���̹Ƿ�, ���θ� ���� �� ����.
*/
void slope(int i, bool c) {
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		//���̳� ���̳�
		int d = c == true ? Map[i][j + 1] - Map[i][j] : Map[j + 1][i] - Map[j][i];
		if (d == 0) cnt++;
		else if (d == 1 && cnt >= L) cnt = 1;
		else if (d == -1 && cnt >= 0) cnt = -L + 1;
		else return;
	}
	if (cnt >= 0) ans += 1;
}
void Process() {
	for (int i = 0; i < N; i++) {
		slope(i, true);
		slope(i, false);
	}
}
void Solution() {
	Input();
	Process();
	cout << ans << "\n";
}
int main() {
	freopen("12.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}