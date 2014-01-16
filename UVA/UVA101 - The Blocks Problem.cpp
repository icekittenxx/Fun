#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int maxn = 25;

int position[maxn];
stack<int> block[maxn];
stack<int> store;

void returnAbove(int a){
	int posA;
	posA = position[a];
	while(block[posA].top() != a){
		int temp = block[posA].top();
		block[posA].pop();
		position[temp] = temp;
		block[temp].push(temp);
	}
}

void moveOnto(int a, int b){
	int posA, posB;
	posA = position[a];
	posB = position[b];
	if(posA != posB){
		returnAbove(a);
		returnAbove(b);
		block[posA].pop();
		position[a] = posB;
		block[posB].push(a);
	}
}

void moveOver(int a, int b){
	int posA, posB;
	posA = position[a];
	posB = position[b];
	if(posA != posB){
		returnAbove(a);
		block[posA].pop();
		position[a] = posB;
		block[posB].push(a);        
	}
}

void storeAbove(int a){
	int posA;
	posA = position[a];
	while (block[posA].top() != a){
		int temp = block[posA].top();
		block[posA].pop();
		store.push(temp);
	}
}


void moveFromStore(int b){
    int posB;
    posB = position[b];
    while (!store.empty()){
        int temp = store.top();
        store.pop();
        block[posB].push(temp);   
        position[temp] = posB;
    }
}

void pileOnto(int a, int b){
	int posA, posB;
	posA = position[a];
	posB = position[b];
	if(posA != posB){
		storeAbove(a);
		returnAbove(b);
		block[posA].pop();
		position[a] = posB;
		block[posB].push(a);        
		moveFromStore(b);
	}
}

void pileOver(int a, int b){
	int posA, posB;
	posA = position[a];
	posB = position[b];
	if(posA != posB){
		storeAbove(a);
		block[posA].pop();
		position[a] = posB;
		block[posB].push(a);        
		moveFromStore(b);
	}
}

void init(){
	for(int i = 0; i < maxn; i ++){
		position[i] = i;
		while(!block[i].empty()){
			block[i].pop();
		}
		block[i].push(i);
	}
	while(!store.empty()){
		store.pop();
	}
}

void print(int num){
	stack<int> tempSt;
	int temp;
	while(!block[num].empty()){
		temp = block[num].top();
		tempSt.push(temp);
		block[num].pop();
	}
	cout << num << ":";
	while(!tempSt.empty()){
		cout << " " << tempSt.top();
		tempSt.pop();
	}
	cout << endl;
}

void solve(int n){
	init();

	string c1, c2;
	while(cin >> c1){
		if(c1 == "quit"){
			break;
		}
		else{
			int a, b;
			cin >> a >> c2 >> b;

			if((c1 == "move") && (c2 == "onto")){
				moveOnto(a, b);
			}
			else if((c1 == "move") && (c2 == "over")){
				moveOver(a, b);
			}
			else if((c1 == "pile") && (c2 == "onto")){
				pileOnto(a, b);
			}
			else{
				pileOver(a, b);
			}
		}
	}

	for(int i = 0; i < n; i ++){
		print(i);
	}
}

int main(){
	int n;
	while(cin >> n){
		solve(n);
	}
}