#include <cstdio>
#include <cstring>

const int maxn = 35;

int arr[maxn], n;

void rev(int cut){
	printf("%d ", n - cut);
	for(int i = 0; i <= cut / 2; i ++){
		int tmp = arr[i];
		arr[i] = arr[cut - i];
		arr[cut - i] = tmp;
	}
}

int scan(){
	char ch = 0;
	memset(arr, 0, sizeof(arr));
	if (scanf("%d", &arr[0]) == EOF) return 0;
	int i = 1;
	while ((ch = getchar())  && ch != '\n') {
		scanf("%d", &arr[i++]);
	}
	return i;
}

void solve(){
	printf("%d", arr[0]);
	for(int i = 1; i < n; i ++)
		printf(" %d", arr[i]);
	printf("\n");

	int cnt = n;
	while(cnt){
		int max = 0, rec;
		for(int i = 0; i < cnt; i ++){
			if(arr[i] > max) {
				max = arr[i];
				rec = i;
			}
		}
		if(rec != cnt - 1){
			if(rec != 0)
				rev(rec);
			rev(cnt - 1);
		}
		cnt --;
	}
	printf("0\n");
}

int main(){
	while(n = scan()){
		solve();	
	}
	return 0;
}