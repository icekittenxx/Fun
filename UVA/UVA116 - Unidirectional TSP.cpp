#include <cstdio>
#include <algorithm>

using namespace std;

int f[12][105];
int p[12][105];

int col, row;

void solve(){

	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			scanf("%d", &f[i][j]);
		}
	}

	for(int j = col - 2; j >= 0; j --){
		for(int i = 0; i < row; i ++){
			int x;
			if(f[(i + 1) % row][j + 1] < f[(i - 1 + row) % row][j + 1]){
				x = (i + 1) % row;
			}
			else{
				x = (i - 1 + row) % row;
			}
			if(f[(i + 1) % row][j + 1] == f[(i - 1 + row) % row][j + 1]){
				x = min((i + 1) % row, (i - 1 + row) % row);
			}
			if(f[x][j + 1] > f[i][j + 1] || (f[x][j + 1] == f[i][j+1] && i < x)){
				x = i;
			}
			f[i][j] += f[x][j + 1];
			p[i][j] = x;
		}    
	}

	int ans = (1 << 30) + 1;
	int t;
	for(int i = 0; i < row; i ++){
		if(f[i][0] < ans){
			ans = f[i][0];
			t = i;
		}
	}
	printf("%d", t + 1);
	for(int j = 0; j < col - 1; j ++){
		printf(" %d", p[t][j] + 1);
		t = p[t][j];
	}    

	printf("\n%d\n", ans);
}

int main(){
	while(~scanf("%d%d", &row, &col)){
		solve();
	}
	return 0;
}