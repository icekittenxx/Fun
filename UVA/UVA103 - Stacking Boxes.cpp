#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 35;
const int maxm = 15;

class Node{
public:
	int dis[maxm];
	int index;
};

int n, m;
Node node[maxn];
int len[maxn], pre[maxn];

bool nodeCmp(Node a, Node b){
	for(int i = 0; i < m; i ++){
		if(a.dis[i] > b.dis[i])
			return false;
	}
	return true;
}

bool can(Node x, Node y){
	for(int i = 0; i < m; i ++)
		if(x.dis[i] >= y.dis[i])
			return false;
	return true;
}

void print(int x){
	if(x == -1)
		return;
	print(pre[x]);
	cout << node[x].index + 1 << " ";
}

void solve(){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> node[i].dis[j];
			node[i].index = i;
		}
		sort(node[i].dis, node[i].dis + m);
	}

	sort(node, node + n, nodeCmp);

	memset(len, 0, sizeof(len));
	memset(pre, -1, sizeof(pre));

	len[0] = 1;
	pre[0] = -1;

	for(int i = 1; i < n; i ++){
		len[i] = 1;
		for(int j = i - 1; j >= 0; j --){
			if(can(node[j], node[i])){
				if(len[i] < len[j] + 1){
					len[i] = len[j] + 1;
					pre[i] = j;
				}
			}
		}
	}

	int mx = 0;
	int mxpos = 0;
	for(int i = 0; i < n; i ++){
		if(len[i] > mx){
			mx = len[i];
			mxpos = i;
		}
	}

	cout << mx << endl;
	print(pre[mxpos]);
	cout << node[mxpos].index + 1;
	cout << endl;
}

int main(){
	while(cin >> n >> m){
		solve();
	}
	return 0;
}