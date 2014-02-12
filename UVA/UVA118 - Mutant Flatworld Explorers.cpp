#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int grid[100][100];

class POINT{
public:
	int x;
	int y;
};

class DIRE_LOST{
public:
	char dire;
	bool lost;
};

DIRE_LOST mock(string instru, char dire);
bool islegal();
bool islost();
void return_pos(char dire);
void set_grid(char dire);
POINT pos;
int grid_x, grid_y;

bool islegal(){
	if(pos.x < 0 || pos.y < 0 || pos.x > grid_x || pos.y > grid_y)
		return false;
	else
		return true;
}

bool islost(){
	if(grid[pos.x][pos.y] == 0)
		return true;
	else
		return false;
}

void return_pos(char dire){
	if(dire == 'N')
		pos.y --;
	else if(dire == 'S')
		pos.y ++;
	else if(dire == 'E')
		pos.x --;
	else if(dire == 'W')
		pos.x ++;
}

void set_grid(char dire){
	if(dire == 'N')
		grid[pos.x][grid_y] = 0;
	else if(dire == 'S')
		grid[pos.x][0] = 0;
	else if(dire == 'E')
		grid[grid_x][pos.y] = 0;
	else if(dire == 'W')
		grid[0][pos.y] = 0;
}

DIRE_LOST mock(string instru, char dire){
	DIRE_LOST temp;
	for(int i = 0; i < (signed)instru.size(); i ++){
		if(dire == 'N'){
			if(instru[i] == 'F')
				pos.y ++;
			else if(instru[i] == 'R')
				dire = 'E';
			else if(instru[i] == 'L')
				dire = 'W';
		}
		else if(dire == 'S'){
			if(instru[i] == 'F')
				pos.y --;
			else if(instru[i] == 'R')
				dire = 'W';
			else if(instru[i] == 'L')
				dire = 'E';
		}
		else if(dire == 'W'){
			if(instru[i] == 'F')
				pos.x --;
			else if(instru[i] == 'R')
				dire = 'N';
			else if(instru[i] == 'L')
				dire = 'S';
		}
		else{
			if(instru[i] == 'F')
				pos.x ++;
			else if(instru[i] == 'R')
				dire = 'S';
			else if(instru[i] == 'L')
				dire = 'N';
		}
		if(!islegal()){
			temp.dire = dire;
			temp.lost = true;
			return_pos(dire);
			if(islost()){
				temp.lost = false;
			}
			else{
				set_grid(dire);
				return temp;
			}
		}
	}
	temp.lost = false;
	temp.dire = dire;
	return temp;
}

void solve(){
	DIRE_LOST result;
	char dire;
	string instru;
	scanf("%d %d", &grid_x, &grid_y);
	for(int i = 0; i <= grid_x; i ++){
		grid[i][0] = 1;
		grid[i][grid_y] = 1;
	}

	for(int j = 0; j <= grid_y; j ++){
		grid[0][j] = 1;
		grid[grid_x][j] = 1;
	}

	while(~scanf("%d %d %c", &pos.x, &pos.y, &dire)){
		cin >> instru;
		result = mock(instru, dire);
		printf("%d %d %c", pos.x, pos.y, result.dire);
		if(result.lost){
			printf(" LOST\n");
		}
		else{
			printf("\n");
		}
	}
}

int main(){
	solve();
	return 0;
}