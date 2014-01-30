#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 30;

int LCS(int n, int aim[], int now[]){
	int f[maxn][maxn];
	memset(f, 0, sizeof f);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(aim[i] == now[j]){
				f[i + 1][j + 1] = f[i][j] + 1;
			}
			else{
				f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
			}
		}
	}
	return f[n][n];
}

void solve(){
	int n, temp;
	int aim[maxn], now[maxn];

	cin >> n;
	memset(aim, 0, sizeof aim);
	memset(now, 0, sizeof now);
	for(int i = 0; i < n; i ++){
		cin >> temp;
		aim[temp - 1] = i + 1;
	}

	while(cin >> temp){
		now[temp - 1] = 1;
		for(int i = 1; i < n; i ++){
			cin >> temp;
			now[temp - 1] = i + 1;
		}
		int ans = LCS(n, aim, now);
		cout << ans << endl;
	}
}

int main(){
	solve();
	return 0;
}