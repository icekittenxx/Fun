#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;

int result[maxn];

int getResult(long long num){
	if(num < maxn && result[num] != 0){
		return result[num];
	}
	
	if(num == 1){
		return result[num];
	}

	int tempResult;
	if(num % 2){
		tempResult = getResult(3 * num + 1);
	}
	else{
		tempResult = getResult(num / 2);
	}

	if(num < maxn)
		result[num] = tempResult + 1;
	return tempResult + 1;
}

void init(){
	memset(result, 0, sizeof result);
	result[1] = 1;
}

void solve(int left, int right){
	int maxStep = -1;
	
	int minNum = left, maxNum = right;

	if(minNum > maxNum){
		swap(minNum, maxNum);
	}

	for(int i = minNum; i <= maxNum; i ++){
		int tempResult = getResult(i);
		if(tempResult > maxStep){
			maxStep = tempResult;
		}
	}
	cout << left << " " << right << " " << maxStep << endl;
}

int main(){
	init();

	int i, j;
	while(cin >> i >> j){
		solve(i, j);
	}
	return 0;
}