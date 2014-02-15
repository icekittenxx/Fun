#include <iostream>
#include <algorithm>

using namespace std;

const double fSqrt3_2 = 0.8660254f;

int Skew(double x, double y){
	int nRows = (y >= 1) + (int)((y - 1) / fSqrt3_2);
	return (nRows * (int)x - (nRows / 2) * (x - (int)x < 0.5f));
}

void solve(double x, double y){
	int nGrid = (int)x * (int)y, nSkew = max(Skew(x, y), Skew(y, x));
	cout << max(nGrid, nSkew) << (nGrid >= nSkew ? " grid" : " skew") << endl;
}

int main(){
	double x, y;
	while(cin >> x >> y){
		solve(x, y);
	}
	return 0;
}