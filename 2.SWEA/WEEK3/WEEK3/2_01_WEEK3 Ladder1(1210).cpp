#include<cstdio>
int arr[100][101];
int N, M;
int main() {
	freopen("WEEK3(1210).in.txt", "r", stdin);
	int dir;
	for (int i = 1; i <= 10; i++)
	{
		int x = 0, y = 0;
		scanf("%*d");
		for (N = 0; N < 100; N++)
			for (M = 0; M < 100; M++)
				scanf("%d", &arr[N][M]);

		for (N = 0; N < 100; N++)
			if (arr[99][N] == 2) x = N;
		y = 99;
		dir = 3;
		while (y > 0) // 도착점 2에서 출발점을 찾는다.(거꾸로)
		{
			if (x < 100 && arr[y][x + 1] == 1 && dir != 1)
			{
				x++;
				dir = 2;
			}
			else if (x > 0 && arr[y][x - 1] == 1 && dir != 2)
			{
				x--;
				dir = 1;
			}
			else if (y > 0 && arr[y - 1][x] == 1)
			{
				y--;
				dir = 3;
			}
		}
		printf("#%d %d\n", i, x);
		x = 0;
	}
	return 0;
}