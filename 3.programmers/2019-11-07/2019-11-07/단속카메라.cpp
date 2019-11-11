#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end()); 
	int start = routes[0][1];
	for (int i = 1; i < routes.size() - 1; i++) { 
		int ne = routes[i][1];
		int nns = routes[i + 1][0];
		if (start > ne) start = ne;
		if (start < nns) {
			answer += 1;
			start = routes[i + 1][1];
		}
	}
	return answer + 1;
}
int main() {
	vector<vector<int>> r;
	r.push_back({ -20,-15 });
	r.push_back({ -14,-5 });
	r.push_back({ -18,-13 });
	r.push_back({ -5,-3 });
	cout << solution(r) << endl;
	return 0;
}