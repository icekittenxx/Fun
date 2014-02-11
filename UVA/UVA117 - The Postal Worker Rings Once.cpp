#include <iostream>
#include <string>

using namespace std;

const int maxn = 30;
const int int_max = (1 << 10);

int graph[maxn][maxn];
int length;
int degree[maxn];

void init(){
	length = 0;
	for(int i = 1; i < maxn; i ++){
		degree[i] = 0;
		for(int j = 1; j < maxn; j ++){
			graph[i][j] = int_max;
		}
	}
}

void floyd(){
	int vertices = maxn - 1;

	for(int i = 1; i <= vertices; i ++){
		graph[i][i] = 0;
	}

	for (int k = 1; k <= vertices; k ++){
		for (int i = 1; i <= vertices; i ++){
			for (int j = 1; j <= vertices; j ++){
				if(graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

void solve(string street){
	if(street == "deadend"){
		int start, end;
		bool found = false;
		for(int i = 1; i < maxn; i ++){
			if(degree[i] & 1){
				if(found == false)
					start = i;
				else
					end = i;
				found = true;
			}
		}

		if(found){
			floyd();
			cout << (length + graph[start][end]) << endl;
		}
		else{
			cout << length << endl;
		}

		init();
	}
	else{
		length += street.length();
		graph[street[0] - 'a' + 1][street[street.length() - 1] - 'a' + 1] = street.length();
		graph[street[street.length() - 1] - 'a' + 1][street[0] - 'a' + 1] = street.length();
		degree[street[0] - 'a' + 1] ++;
		degree[street[street.length() - 1] - 'a' + 1] ++;
	}
}

int main(){
	init();
	string street;
	while(cin >> street){
		solve(street);
	}

	return 0;
}