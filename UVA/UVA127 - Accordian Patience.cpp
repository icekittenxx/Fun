#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

const int remain_max = 52;
const int maxn = 60;
const int maxl = 100;

class node{
public:
	char rank;
	char suit;
};

class myStack{
public:
	node value[maxn];
	int top;
	myStack(): top(0){}
};

myStack data[maxn];
int vis[maxn];
char str[2][maxl];
int d;

int checkMatch(node a, node b){
	if(a.rank == b.rank || a.suit == b.suit)
		return 1;
	else
		return 0;
}   

int getMatchPos(int pos, node &a){
	if(vis[pos])
		return -1;
	else {
		int count;
		int firstPos, secondPos;
		firstPos = -1;
		secondPos = -1;
		count = 0;
		for(int i = pos - 1; i >= 0; i --){
			if(!vis[i]){
				count ++;
				if(count == 1)
					secondPos = i;
				if(count == 3)
					firstPos = i;
				if(count > 3)
					break;
			}
		}
		if(firstPos == -1 && secondPos == -1)
			return -1;
		else if(firstPos != -1 && checkMatch(data[pos].value[data[pos].top - 1], data[firstPos].value[data[firstPos].top - 1]))
			return firstPos;
		else if(secondPos != -1 && checkMatch(data[pos].value[data[pos].top - 1], data[secondPos].value[data[secondPos].top - 1]))
			return secondPos;
		else
			return -1;
	}
}

int if_can_close_up(){
	int temp[maxn];
	int count = 0;
	for(int i = 0; i < remain_max; i ++){
		if(!vis[i])
			temp[count ++] = i;
	}

	int ok = 1;
	for(int i = 0; i < count - 1; i ++){
		if(!checkMatch(data[i].value[data[i].top - 1], data[i + 1].value[data[i + 1].top - 1])){
			ok = 0;
			break;
		}
	}
	return ok;
}

void solve(){
	int i, j;
	int c = 0;
	for(i = 0; i < 2; i ++){
		int len = strlen(str[i]);
		for(j = 0; j < len; j += 3){
			data[c].top = 0;
			data[c].value[data[c].top].rank = str[i][j];
			data[c].value[data[c].top].suit = str[i][j + 1];
			data[c].top = 1;
			c ++;
		}
	}   
	memset(vis, 0, sizeof(vis));
	i = 0;
	int flag = 0;
	while(i < remain_max){
		if(if_can_close_up()){
			flag = 1;
			break;
		}
		int matchPos = getMatchPos(i, data[i].value[data[i].top - 1]);
		if(matchPos == -1)
			i ++;
		else{
			data[matchPos].value[data[matchPos].top].rank = data[i].value[data[i].top - 1].rank;
			data[matchPos].value[data[matchPos].top].suit = data[i].value[data[i].top - 1].suit;
			data[matchPos].top ++;
			data[i].top --;
			if(data[i].top == 0)
				vis[i] = 1;
			i = matchPos;
		}
	}
	if(flag){
		cout << "1 pile remaining: 52" << endl;
	}
	else{
		int count = 0;
		for(j = 0; j < remain_max; j ++){
			if(vis[j] == 0)
				count ++;
		}
		cout << count << " piles remaining:";
		for(i = 0; i < remain_max; i ++){
			if(!vis[i]){
				cout << " " << data[i].top;
			}
		}
		cout << endl;
	}
}

int main(){
	d = 0;
	while(true){
		gets(str[0]);
		if(strcmp(str[0], "#") == 0)
			break;
		gets(str[1]);
		solve();
	}
	return 0;
}