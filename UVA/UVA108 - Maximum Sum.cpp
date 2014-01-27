#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
int m[maxn][maxn], s[maxn][maxn], a[maxn], n;

int maxSeq(int a[], int len){
	int res = a[0];
	int sum = 0;
	for(int i = 0; i < len; i ++){
		if(sum < 0){
			sum = a[i];
		}
		else{
			sum += a[i];
		}
		
		if(res < sum){
			res = sum;
		}
	}
	return res;
}

void solve(){
	memset(m, 0, sizeof m);
	memset(s, 0, sizeof s);

	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			scanf("%d", &m[i][j]);
			s[i][j] = s[i - 1][j] + m[i][j];
		}
	}

	int ans = -0xfffffff;
	for(int i = 0; i <= n - 1; i ++){
		for(int j = i + 1; j <= n; j ++){
			for(int k = 1; k <= n; k ++){
				a[k] = s[j][k]- s[i][k];
			}
			int res = maxSeq(a + 1, n);
			ans = max(ans, res);
		}
	}
	printf("%d\n", ans);
}

int main(){
	solve();
	return 0;
}
