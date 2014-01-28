#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

void indent(int n){
	for(int i = 0; i < n; i ++)
		printf("  ");
}

void make_prog(int cur, int n, const vector<int> &seq){
	if(cur == n){
		indent(n);
		printf("writeln(");
		for(int i = 0; i < n; i ++){
			if(i > 0){
				printf(",");
			}
			printf("%c", 'a' + seq[i]);
		}
		printf(")\n");
	}
	else{
		for(int i = cur; i >= 0; i --){
			indent(cur);
			if(i < cur){
				printf("else ");
			}
			if(i > 0){
				printf("if %c < %c then", seq[i - 1] + 'a', cur + 'a');
			}
			printf("\n");
			vector<int> new_seq = seq;
			new_seq.insert(new_seq.begin() + i, cur);
			make_prog(cur + 1, n, new_seq);
		}
	}
}

void solve(int casen){
	int n;
	scanf("%d", &n);
	printf("program sort(input,output);\nvar\n");
	printf("a");
	for(int i = 1; i < n; i ++){
		printf(",%c", 'a' + i);
	}
	printf(" : integer;\nbegin\n  readln(a");
	for(int i = 1; i < n; i ++){
		printf(",%c",'a' + i);
	}
	printf(");\n");
	vector<int> seq;
	seq.push_back(0);
	make_prog(1, n, seq);
	printf("end.\n");
	if(casen){
		printf("\n");
	}
}

int main(){
	int casen;
	scanf("%d", &casen);
	while(casen --){
		solve(casen);	
	}
	return 0;
}