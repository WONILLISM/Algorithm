#include<iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> C;
int N;
int solution(int n, vector<int> cores) {
	int low = 0;
	int high = 100000000;
	int mid = (low + high) / 2;

	int count = 0;
	int temp = 0;
	//1 2 3
	while (low < high) {
		cout << " low: " << low << " Mid: " << mid << " High: " << high << endl;
		count = 0;
		temp = 0;
		for(int i=0; i<cores.size(); i++){
			count += (mid / cores[i]) + 1;		//	mid초 동안 처리한 작업 수
			if (mid%cores[i] == 0) {			// cores[i]와 mid가 나누어 떨어질 때, 즉 새로운 작업이 추가 될 때
				temp++;
				count--;
			}
		}
		if (count >= n)					// mid-1초까지 처리한 작업 수 >= n
			high = mid;
		else if (count + temp < n)		// mid초 동안 처리한 작업 수 < n
			low = mid + 1;
		else
			break;
		mid = (high + low) / 2;
	}
	cout << "count: " << count << endl;
	for (int i = 0; i < cores.size(); i++) {
		if (mid%cores[i] == 0)
			count++;
		if (count == n)
			return i + 1;
	}
}
int main() {
	vector<int> c = { 1,2,3 };
	cout << solution(6, c) << endl;
	return 0;
}