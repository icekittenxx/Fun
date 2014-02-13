#include <iostream>
#include <string>

using namespace std;

const int maxn = 1005;

class Person{
public:
	string name;
	int money;
};

bool solve(int num, bool flag){
	if(flag)
		cout << endl;

	Person person[maxn];
	for(int i = 0; i < num; i ++){
		cin >> person[i].name;
		person[i].money = 0;
	}

	string temp;
	for(int i = 0; i < num; i ++){
		cin >> temp;
		int a, b;
		cin >> a >> b;

		if(a == 0 && b == 0)
			continue;
		if(b == 0)
			continue;

		int c = a % b;
		if(a < b)
			c = a;
		for(int i = 0; i < num; i ++){
			if(temp == person[i].name){
				person[i].money -= (a - c);
				break;
			}
		}

		a /= b;
		for(int i = 0; i < b; i ++){
			cin >> temp;
			for(int j = 0; j < num; j ++){
				if(temp == person[j].name){
					person[j].money += a;
					break;
				}
			}
		}
	}

	for(int i = 0; i < num; i ++){
		cout << person[i].name << " " << person[i].money << endl;
	}

	flag = true;
	return flag;
}

int main(){
	int num;
	bool flag = false;
	while(cin >> num){
		flag = solve(num, flag);
	}
	return 0;
}