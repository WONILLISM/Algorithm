#include<cstdio>
int D[1000000];
int Tmp[1000000];
void MergeSort(int start, int end, int *data) {
	int i = start;
	int k = start;
	int m = (start + end) / 2;
	int j = m + 1;
	if (start >= end)return;
	MergeSort(start, m, data);
	MergeSort(m + 1, end, data);
	while ((i <= m) && (j <= end)) {
		if (data[i] < data[j])Tmp[k++] = data[i++];
		else Tmp[k++] = data[j++];
	}
	while (i <= m)Tmp[k++] = data[i++];
	while (j <= end)Tmp[k++] = data[j++];
	for (i = start; i <= end; i++)data[i] = Tmp[i];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &D[i]);
	MergeSort(0, n - 1, D);
	for (int i = 0; i < n; i++)printf("%d\n", D[i]);
	return 0;
}