#include <iostream>
#include <string>

using namespace std;

string result[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
int n[3][3];

void solve(){
	for(int i = 1; i < 3; i ++){
		for(int j = 0; j < 3; j ++){
			cin >> n[i][j];
		}
	}

	int move[6];

	move[0] = n[1][0] + n[2][0] + n[0][2] + n[2][2] + n[0][1] + n[1][1];
	move[1] = n[1][0] + n[2][0] + n[0][1] + n[2][1] + n[0][2] + n[1][2];
	move[2] = n[1][2] + n[2][2] + n[0][0] + n[2][0] + n[0][1] + n[1][1];
	move[3] = n[1][2] + n[2][2] + n[0][1] + n[2][1] + n[0][0] + n[1][0];
	move[4] = n[1][1] + n[2][1] + n[0][0] + n[2][0] + n[0][2] + n[1][2];
	move[5] = n[1][1] + n[2][1] + n[0][2] + n[2][2] + n[0][0] + n[1][0];
	
	int min = 0;
	for(int i = 0; i < 6; i ++){
		if(move[min] > move[i]){
			min = i;
		}
	}

	cout << result[min] << " " << move[min] << endl;
}

int main(){
	while(cin >> n[0][0] >> n[0][1] >> n[0][2]){
		solve();
	}
	return 0;
}