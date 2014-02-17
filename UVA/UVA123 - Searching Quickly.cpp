#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <cctype>

using namespace std;

const int kMaxn = 207;
const string kSign = "::";

void solve(){
	set<string> ignore;
	string temp;
	while(getline(cin, temp) && temp != kSign)
		ignore.insert(temp);
	multimap<string,string> r;
	while(getline(cin, temp)){
		for(int i = 0; i < temp.size(); i ++){
			temp[i] = tolower(temp[i]);
		}
		for(int i = 0; i < temp.size(); i ++){
			if(!isalpha(temp[i]))
				continue;
			int j = i;
			string temp2;
			while(j < temp.size() && isalpha(temp[j])){
				temp2 += temp[j];
				j ++;
			}
			if(!ignore.count(temp2)){
				for(int k = 0; k < temp2.size(); k ++)
					temp2[k] = toupper(temp2[k]);
				string temp3 = temp;
				temp3.replace(i, temp2.size(), temp2);
				r.insert(make_pair(temp2, temp3));
			}
			i = j;
		}
	}

	for(multimap<string, string>::iterator i = r.begin(); i != r.end(); i ++){
		cout << i->second << endl;
	}
}

int main(){
	solve();
	return 0;
}