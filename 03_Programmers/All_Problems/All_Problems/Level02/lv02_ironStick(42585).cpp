#include <iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

// ����   (((
// arr () (((()())
int solution(string arr) {
	int answer = 0;
	vector<int> v;	// ����
	for (int i = 0; i < arr.size(); i++){
		if (arr[i] == '(') v.push_back(arr[i]);		
		else {
			v.pop_back();
			if (arr[i - 1] == '(') answer += v.size();
			else answer++;
		}
	}
	return answer;
}
int main() {
	cout << solution("()(((()())(())()))(())") << endl;
	return 0;
}


//int solution(string arr) {
//	int answer = 0;
//	queue<int> q;
//
//	for (int i = 0; i < arr.size() - 1; i++)
//		if (arr[i] == '('&& arr[i + 1] == '(')
//			q.push(i);	// ����� ������
//
//	answer += q.size();
//	while (!q.empty()) {
//		int idx = q.front(), end = 1;// ������� ���۰� ��
//		q.pop();
//		char cur = arr[idx];
//
//		for (int i = idx + 1; i < arr.size(); i++) {
//			char next = arr[i];
//			if (next == ')')end--;
//			else end++;
//			if (cur == ')'&& next == ')' && end == 0)break;	// �� ���� ����� ����
//			else if (cur == '(' && next == ')') answer++;	// ������ �߻�!
//			cur = next;
//		}
//	}
//	return answer;
//}