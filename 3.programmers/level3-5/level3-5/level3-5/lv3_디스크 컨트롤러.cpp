#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ans;
typedef struct Time {
	int req_T, proc_T;
	bool operator < (const Time &n) const{
		if (proc_T == n.proc_T) {
			return req_T > n.req_T;
		}
		else return proc_T < n.proc_T;
	}
};
//bool compare(Time a, Time b) {
//	if (a.proc_T == b.proc_T)
//		return a.req_T < b.req_T;
//	else return a.proc_T < b.proc_T;
//}
int solution(vector<vector<int>> jobs) {
	int answer = 0;	
	priority_queue<Time> disks;
	//vector<Time> disks;
	for (int i = 0; i < jobs.size(); i++) {
		disks.push({ jobs[i][0], jobs[i][1] });
		//disks.push_back({ jobs[i][0], jobs[i][1] });
	}

	//sort(disks.begin(), disks.end(), compare);
	int t = 0;
	int total = 0;
	while (!disks.empty()) {
		for (int i = 0; i < disks.size(); i++) {
			//Time cur = disks[i];
			Time cur = disks.top();
			disks.pop();
			if (cur.req_T <= t) {
				t += cur.proc_T;
				total += t - cur.req_T;
				//disks.erase(disks.begin() + i);
				break;
			}
			if (i == disks.size() - 1)t++;
		}
	}
	answer = total / jobs.size();
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