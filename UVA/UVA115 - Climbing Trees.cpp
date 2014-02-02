#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Node{
public:
	int nPar;
	int nPos;
	vector<int> chi;
};

vector<Node> tree;

map<string, int> nameTable;

vector<int> order, depth;

void buildRMQTable(int nNode, int nDepth){
	
	order.push_back(nNode);
	depth.push_back(nDepth);
	Node &node = tree[nNode];
	
	if(node.nPos == -1){
		node.nPos = order.size() - 1;
	}
	
	for(vector<int>::iterator i = node.chi.begin(); i != node.chi.end(); i ++){
		buildRMQTable(*i, nDepth + 1);
		
		order.push_back(nNode);
		depth.push_back(nDepth);
	}
}

void input(){
	Node newNode = {-1, -1};

	string str1, str2;
	while(cin >> str1 >> str2 && str1 != "no.child"){
		if(nameTable.end() == nameTable.find(str1)){
			nameTable[str1] = tree.size();
			tree.push_back(newNode);
		}
		if(nameTable.end() == nameTable.find(str2)){
			nameTable[str2] = tree.size();
			tree.push_back(newNode);
		}
		tree[nameTable[str2]].chi.push_back(nameTable[str1]);
		tree[nameTable[str1]].nPar = nameTable[str2];
	}

	tree.push_back(newNode);
}

void build(){
	for(vector<Node>::iterator i = tree.begin(); i != tree.end() - 1; i ++){
		if(i->nPar == -1){
			i->nPar = tree.size() - 1;
			tree.back().chi.push_back(i - tree.begin());
		}
	}

	buildRMQTable(tree.size() - 1, 0);
}

void query(){
	string str1, str2;
	while(cin >> str1 >> str2){
		map<string, int>::iterator i1 = nameTable.find(str1);
		map<string, int>::iterator i2 = nameTable.find(str2);

		if (i1 == nameTable.end() || i2 == nameTable.end()) {
			cout << "no relation" << endl;
			continue;
		}
		
		int n1 = tree[i1->second].nPos, n2 = tree[i2->second].nPos;
		
		if(depth[n1] > depth[n2]) {
			swap(n1, n2);
		}
		
		//not O(1)
		vector<int>::iterator iAnc = min_element(depth.begin() + min(n1, n2), depth.begin() + max(n1, n2) + 1);

		if(tree[order[iAnc - depth.begin()]].nPar == -1){
			cout << "no relation" << endl;
			continue;
		}

		int nRemoved = depth[n2] - depth[n1];
		int nCousin = depth[n1] - *iAnc;
		
		if(nCousin == 0){
			while(nRemoved > 2){
				cout << "great ";
				nRemoved --;
			}
			if(nRemoved > 1){
				cout << "grand ";
			}
			cout << (tree[i1->second].nPos == n1 ? "parent" : "child") << endl;
		}
		
		else if(nCousin == 1 && nRemoved == 0){
			cout << "sibling" << endl;
		}
		
		else{
			cout << nCousin - 1 << " cousin";
			if(nRemoved > 0){
				cout << " removed " << nRemoved;
			}
			cout << endl;
		}
	}
}

void solve(){
	input();
	build();
	query();
}

int main(){
	solve();
	return 0;
}