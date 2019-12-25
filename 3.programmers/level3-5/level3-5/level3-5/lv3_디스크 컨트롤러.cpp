#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans;
typedef struct Time {int req, proc;};
bool compare(Time a, Time b) {
	if (a.proc == b.proc)
		return a.req < b.req;
	else return a.proc < b.proc;
}
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	vector<Time> disks;
	for (int i = 0; i < jobs.size(); i++) 
		disks.push_back({ jobs[i][0], jobs[i][1] });
	sort(disks.begin(), disks.end(), compare);
	int t = 0;
	while (!disks.empty()) {
		for (int i = 0; i < disks.size(); i++) {
			Time cur = disks[i];
			if (cur.req <= t) {
				t += cur.proc;
				answer += t - cur.req;
				disks.erase(disks.begin() + i);
				break;
			}
			if (i == disks.size() - 1)t++;
		}
	}
	answer /= jobs.size();
	return answer;
}
int main() {
	vector<vector<int>> j;
	j.push_back({ 0,3 });
	j.push_back({ 1,9 });
	j.push_back({ 2,6 });
	cout << solution(j) << "\n";
	return 0;
}