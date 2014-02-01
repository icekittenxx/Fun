#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void solve(double n, double p){
	printf("%.0lf\n", pow(p, 1 / n));
}

int main(){
	double n, p;
	while(cin >> n >> p){
		solve(n, p)
	}
	return 0;
}