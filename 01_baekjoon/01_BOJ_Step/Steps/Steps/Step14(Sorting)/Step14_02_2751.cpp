#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#define endl '\n'
using namespace std;
vector<int> v;
vector<int> tmp;
void process(int start, int end) {
	int i = start;
	int mid = (start + end) / 2;
	int j = mid + 1;

	int tmp_idx = start;

	if (start >= end)return;
	while (i <= mid && j <= end) {
		if (v[i] < v[j])tmp[tmp_idx++] = v[i++];
		else tmp[tmp_idx++] = v[j++];
	}
	while (i <= mid)tmp[tmp_idx++] = v[i++];
	while (j <= end)tmp[tmp_idx++] = v[j++];
	for (i = start; i < end; i++)v[i] = tmp[i];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	v.assign(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	tmp.assign(v.size(), 0);
	process(0, v.size() - 1);

	bool chk = false;
	for (int i = 0; i < v.size(); i++) {
		if (!chk) {
			chk = true;
			cout << v[i] << endl;
		}
		else {
			if (v[i - 1] != v[i])chk = false;
			if (!chk) {
				chk = true;
				cout << v[i] << endl;
			}
		}
	}
	return 0;
}