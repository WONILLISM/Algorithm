#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> trie;

int solution(vector<string> words) {
	int answer = 0;
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words[i].size(); j++) {
			char key = words[i][j];
			if (j != words[i].size() - 1) {
				char value = words[i][j + 1];
				if (trie.find(key) == trie.end()) {
					trie.insert({ key,vector<char>() });
					trie[key].push_back(value);
				}
				else trie[key].push_back(value);
			}
			else {
				if (trie.find(key) == trie.end()) {
					trie.insert({ key,vector<char>() });
					trie[key].push_back('\0');
				}
				else trie[key].push_back('\0');
			}


		}	
	}
	return answer;
}
int main() {
	cout << solution({ "go","gone","guild" }) << endl;
	return 0;
}