#include <iostream>
#include <cmath>

using namespace std;

const int maxn = 1000005;

int gcd(int a, int b){
	return a < b? gcd(b, a): (b? gcd(b, a % b): a);
}

void solve(int n){
	bool used[maxn];
	for(int i = 1; i <= n; i ++){
		used[i] = false;
	}

	int limit = floor(sqrt(n * 1.0));
	int total = 0;
	
	for(int i = 1; i < limit; i ++){
		for(int j = i + 1; j <= limit; j += 2){
			int z = i * i + j * j;
			int x, y;
			if(z <= n && gcd(i, j) == 1){
				x = j * j - i * i;
				y = 2 * i * j;

				total ++;
				for(int start = 1; z * start <= n; start ++){
					used[x * start] = used[y * start] = used[z * start] = true;
				}
			}
		}
	}

	int unused = 0;
	for(int i = 1; i <= n; i ++){
		if(!used[i]){
			unused ++;
		}
	}
	
	cout << total << " " << unused << endl;
}

int main(){
	int n;
	while(cin >> n){
		solve(n);
	}
	return 0;
}