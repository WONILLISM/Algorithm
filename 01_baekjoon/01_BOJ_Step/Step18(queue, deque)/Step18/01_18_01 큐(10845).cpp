#include<iostream>
#include<string>
using namespace std;
int N;

class Queue {
private:
	int Q[10000];
	int f, r;
public:
	Queue() :f(0), r(0) {
		for (int i = 0; i < 10000; i++)
			Q[i] = 0;
	}
	~Queue(){}
	bool isEmpty() { return this->f >= this->r; }
	int size() { return this->r - this->f; }
	int front() { return this->r == this->f ? -1 : Q[this->f]; }
	int back() { return this->r == this->f ? -1 : Q[this->r-1]; }
	void push(int x) { Q[this->r++] = x; }
	int pop() {
		if (!this->isEmpty()) {
			return Q[this->f++];
		}
		else return -1;
	}
};
void solution() {
	Queue q;
	cin >> N;
	while (N--) {
		string s;
		int n;
		cin >> s;
		if (s == "push") {
			int a;
			cin >> a;
			q.push(a);
		}
		else {
			if (s == "front")cout << q.front()<<endl;//printf("%d", q.front());
			else if (s == "back")cout << q.back()<<endl;//printf("%d", q.back());
			else if (s == "size")cout << q.size()<<endl;//printf("%d", q.size());
			else if (s == "empty")cout << q.isEmpty()<<endl;//printf("%d", q.isEmpty());
			else if (s == "pop")cout << q.pop() << endl;//printf("%d", q.pop());
		}
	}
}
int main() {
	freopen("01.in", "r", stdin);
	solution();
	return 0;
}