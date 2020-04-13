#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int solution()
{
	int answer = 666;
	while (1)
	{
		string num = to_string(answer);
		for (int i = 0; i < num.size() - 2; i++)
		{
			string tmp = num.substr(i, 3);
			if (tmp == "666")
			{
				N--;
				if (!N)
					return answer;
				break;
			}
		}
		answer++;
	}
	return answer;
}
int main()
{
	cin >> N;
	cout << solution() << endl;
	return 0;
}