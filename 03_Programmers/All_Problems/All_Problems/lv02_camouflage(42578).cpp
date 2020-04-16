#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//unordered_map<string, vector<string>> um;
unordered_map<string, int> um;
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	for (int i = 0; i < clothes.size(); i++) {
		string key = clothes[i][1];
		//string value = clothes[i][0];
		if (um.find(key) == um.end()) {
			//um.insert({ key, vector<string>() });
			//um[key].push_back(value);
			um.insert({ key, 1 });
		}
		else um[key]++;
			//um[key].push_back(value); 
	}
	
	for (auto iter = um.begin(); iter != um.end(); iter++)
		answer *= iter->second + 1;
		

	return answer - 1;
}
int main() {
	//cout << solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} }) << endl;
	cout << solution({ {"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face"} }) << endl;
	return 0;
}