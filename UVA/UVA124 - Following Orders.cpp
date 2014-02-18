#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 25;

void solve(string str){
	char szOrder[maxn];
	strcpy(szOrder, str.c_str());
	int nLen = remove(szOrder, &szOrder[str.size()], ' ') - szOrder;
	szOrder[nLen] = '\0';
	getline(cin, str);
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	bool aCompMat[26][26] = {0};
	for(string::iterator i = str.begin(); i != str.end(); i += 2){
		aCompMat[*i - 'a'][*(i + 1) - 'a'] = true;
	}

	sort(&szOrder[0], &szOrder[nLen]);

	for(bool bFlag = true; bFlag; bFlag = next_permutation(&szOrder[0], &szOrder[nLen])){
		for(int i = 0; i < nLen - 1 && bFlag; i ++){
			for(int j = i + 1; j < nLen && bFlag; j ++){
				bFlag &= !aCompMat[szOrder[j] - 'a'][szOrder[i] - 'a'];
			}
		}
		if(bFlag){
			cout << szOrder << endl;
		}
	}
}

int main(){
	bool bFirst = true;
	string str;
	while(getline(cin, str)){
		if(!bFirst){
			cout << endl;
		}
		solve(str);
		bFirst = false;
	}
	return 0;
}