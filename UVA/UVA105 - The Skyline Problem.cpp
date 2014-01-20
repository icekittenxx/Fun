#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 20005;

class Tree{
public:
	int left, right;
	int high;
};

Tree tree[maxn * 4];
int coordinate[maxn];

void build(int left, int right, int node){
	tree[node].left = left;
	tree[node].right = right;
	tree[node].high = 0;
	if(left == right){
		return;
	}
	int mid = (left + right) / 2;
	build(left, mid, node << 1);
	build(mid + 1, right, node << 1 | 1);
}

void insert(int left, int right, int temp, int node){
	if(tree[node].left >= left && tree[node].right <= right){
		if(tree[node].high < temp){
			tree[node].high = temp;
		}
		return;
	}

	int mid = (tree[node].left + tree[node].right) / 2;
	if(left <= mid){
		insert(left, right, temp, node << 1);
	}
	if(right > mid){
		insert(left, right, temp, node << 1 | 1);
	}
}

int query(int point, int node){
	if(tree[node].left == tree[node].right){
		return tree[node].high;
	}
	int mid = (tree[node].left + tree[node].right) / 2;
	if(point <= mid){
		int ans = query(point, node << 1);
		if(tree[node].high < ans){
			return ans;
		}
		else{
			return tree[node].high;
		}
	}
	else{
		int ans = query(point, node << 1 | 1);
		if(tree[node].high < ans){
			return ans;
		}
		else{
			return tree[node].high;
		}
	}
}

void solve(){
	build(0, maxn, 1);
	
	int start = -1, final = -1;
	int a, b, temp;
	while(~scanf("%d%d%d", &a, &temp, &b)){
		if(start == -1 || start > a){
			start = a;
		}
		if(final == -1 || final	< b){
			final = b;
		}
		insert(a, b - 1, temp, 1);
	}

	for(int i = start; i <= final; i ++){
		coordinate[i] = query(i, 1);
	}

	printf("%d %d", start, coordinate[start]);
	for(int i = start + 1; i < final; i ++){
		if(coordinate[i] != coordinate[i - 1]){
			printf(" %d %d", i, coordinate[i]);
		}
	}
	printf(" %d 0\n", final);
}

int main(){
	solve();
	return 0;
}