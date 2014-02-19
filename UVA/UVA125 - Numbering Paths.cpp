#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35;

int m, f[N][N], cas = 0;
int a, b, n;

void init(){
	n = 0;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < m; i ++){
		scanf("%d%d", &a, &b);
		f[a][b] = 1;
		n = max(max(a, b), n);
	}
}

void floyd(){
	for(int k = 0; k <= n; k ++){
		for(int i = 0; i <= n; i ++){
			for(int j = 0; j <= n; j ++){
				f[i][j] += f[i][k] * f[k][j];
			}
		}
	}
	for(int k = 0; k <= n; k ++){
		if(f[k][k]){
			for(int i = 0; i <= n; i ++){
				for(int j = 0; j <= n; j ++){
					if(f[i][k] && f[k][j]){
						f[i][j] = -1;
					}
				}
			}
		}
	}
}

void solve(){
	init();
	floyd();
	printf("matrix for city %d\n", cas ++);
	for(int i = 0; i <= n; i ++) {
		for(int j = 0; j < n; j ++)
			printf("%d ", f[i][j]);
		printf("%d\n", f[i][n]);
	}
}

int main(){
	while(~scanf("%d", &m)){
		solve();
	}
	return 0;
}