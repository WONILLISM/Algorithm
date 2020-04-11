#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int arr[5], answer = 1 << 30;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 3; i++)
		answer = min(arr[i] + arr[3] - 50, min(arr[i] + arr[4] - 50, answer));
	cout << answer << endl;
	return 0;
}