#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 201;

int v[MAX];

int _find(int x){
    if(v[x]==x)return x;
    else return v[x] = _find(v[x]);
}
void _union(int x, int y){
    x = _find(x);
    y = _find(y);
    if(x!=y)
        v[x] = y;
}
void solution_1976() {
	int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0; i<n; i++)
        v[i] = i;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int a;
            scanf("%d",&a);
            if(a==1)
                if(_find(i) != _find(j))
                    _union(i,j);
        }
    }
    int a;
    scanf("%d",&a);
    a-=1;
    a = _find(a);
    for(int i=1; i<m; ++i){
        int x;
        scanf("%d",&x);
        if(a!=_find(x)){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
int main() {
	solution_1976();
	return 0;
}
