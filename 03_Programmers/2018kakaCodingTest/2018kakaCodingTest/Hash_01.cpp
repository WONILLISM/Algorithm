#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (vector<int>::size_type i = 0; i < completion.size(); ++i) {
		if (participant[i] != completion[i])
			return participant[i];
	}
	answer = participant[participant.size() - 1];
	return answer;
}

int main() {
	vector<string> participant;
	participant.push_back("leo");
	participant.push_back("kiki");
	participant.push_back("eden");
	vector<string> completion;
	participant.push_back("kiki");
	participant.push_back("eden");
	cout << solution(participant, completion) << endl;
	
	return 0;
}