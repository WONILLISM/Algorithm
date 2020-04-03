#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> trie;

struct Trie {
	int count;
	bool flag;
	Trie *child[26];

	Trie() :count(0),flag(false) {
		for (int i = 0; i < 26; i++) child[i] = '\0';
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (child[i]) delete child[i];
	}
	void insert(const char *key) {
		if (!*key)flag = true;
		else {
			const int idx = *key - 'a';
			if (!child[idx])
				child[idx] = new Trie();
			child[idx]->count++;
			child[idx]->insert(key + 1);
		}
	}
	int search(const char *key, int cnt) {
		const int idx = *key - 'a';
		if (!*key || !child[idx]) 
			return cnt - 1;
		if (child[idx]->count == 1)
			return cnt;
		return child[idx]->search(key + 1, cnt + 1);
	}
};
int solution(vector<string> words) {
	int answer = 0;
	Trie *root = new Trie();
	for (auto str: words) {
		root->insert(str.c_str());
	}
	for (auto str : words) {
		answer += root->search(str.c_str(), 1);
	}
	delete root;
	return answer;
}
int main() {
	cout << solution({ "go","gone","guild" }) << endl;
	return 0;
}