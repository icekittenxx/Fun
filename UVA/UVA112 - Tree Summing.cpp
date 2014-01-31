#include <iostream>

using namespace std;

bool ok;

bool tree_sum(int n, int sum){
	int v;
	char ch;
	cin >> ch;
	if(!((cin >> v) == 0)){
		n += v;
		bool t = tree_sum(n, sum) | tree_sum(n, sum);
		if(!ok && !t){
			ok = (n == sum);
		}
		cin >> ch;
		return true;
	}
	else{
		cin.clear();
		cin >> ch;
		return false;
	}
}

void solve(int sum){
	ok = false;
	tree_sum(0, sum);
	if(ok){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}

int main(){
	int sum;
	while(cin >> sum){
		solve(sum);
	}
	return 0;
}