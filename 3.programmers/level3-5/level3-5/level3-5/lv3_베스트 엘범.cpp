#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
/*
속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
*/
//typedef struct box1 {	int sum;	string s;};
////bool compare1(box1 a, box1 b) {	return a.sum < b.sum;}
//typedef struct box2 { int plays, idx; };
////bool compare2(box2 a, box2 b) { return a.idx < b.idx; };
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair <string, int>> v;	//주어진 입력값 재정의
	vector<pair<int,string>> tmp;
	vector<pair<int,int>> max_value;

	for (int i = 0; i < genres.size(); i++)
		v.push_back({ genres[i], plays[i] });

	for (int i = 0; i < genres.size(); i++) {
		tmp.push_back({ plays[i], genres[i] });
		for (int j = i + 1; j < genres.size(); j++) {	
			if (genres[i] == genres[j]) {	//현재 장르와 다음 장르가 같다면 tmp에 누적해준다.
				tmp[i].first += plays[j];
				genres.erase(genres.begin() + j); //j번째 장르와 플래이 수를 지운다.
				plays.erase(plays.begin() + j);
				j--;
			}
		}
	}
	sort(tmp.begin(), tmp.end(), greater<pair<int, string>>());

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (tmp[i].second == v[j].first)		//같은 장르라면 max_value에 paly 수 와 인덱스를 넣는다
				max_value.push_back({ v[j].second, j });
		}
		sort(max_value.begin(), max_value.end(), greater<pair<int,int>>());	//idx 순으로 정렬
		if (max_value.size() >= 2) {
			if (max_value[0].first == max_value[1].first) {	//같으면 인덱스가 빠른순으로 푸시
				answer.push_back(max_value[1].second); 
				answer.push_back(max_value[0].second);
			}
			else {
				answer.push_back(max_value[0].second); 
				answer.push_back(max_value[1].second);
			}
		}
		else answer.push_back(max_value[0].second);	
		max_value.clear();
	}
	return answer;
}
int main() {
	vector<string> g = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> p = { 500, 600, 150, 800, 2500 };
	vector<int> ans=solution(g, p);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
	return 0;
}