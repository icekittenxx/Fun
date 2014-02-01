#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 55;

class Point{
public:
	int x;
	int y;
};

class Bumper{
public:
	int nValue;
	int nCost;
};

Bumper pTable[maxn][maxn];
bool used[maxn][maxn];
Point ptSize, ptPos;
Point aDir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int nWCost;

int solve(int px, int py, int nDir, int nLife){
	px --;
	py --;

	int nValue;
	for(nValue = 0, nLife --; nLife > 0; nLife --){
		Point ptNew;
		ptNew.x = px + aDir[nDir].x;
		ptNew.y = py + aDir[nDir].y;
		
		if(ptNew.x == ptSize.x || ptNew.y == ptSize.y ||
			ptNew.x < 1 || ptNew.y < 1){
				nLife -= nWCost;
				nDir = (nDir + 3) % 4;
				continue;
		}
		if(used[ptNew.x][ptNew.y]){
			Bumper pBumper = pTable[ptNew.x][ptNew.y];
			nValue += pBumper.nValue;
			nLife -= pBumper.nCost;
			nDir = (nDir + 3) % 4;
			continue;
		}
		px = ptNew.x;
		py = ptNew.y;
	}
	cout << nValue << endl;
	return nValue;
}

int main(){
	int nTotal;
	cin >> ptSize.x >> ptSize.y >> nWCost >> nTotal;
	ptSize.x --;
	ptSize.y --;

	memset(used, false, sizeof used);
	for(int i = 0; i < nTotal; i ++){
		cin >> ptPos.x >> ptPos.y;
		Bumper pBumper;
		cin >> pBumper.nValue >> pBumper.nCost;
		pTable[ptPos.x - 1][ptPos.y - 1] = pBumper;
		used[ptPos.x - 1][ptPos.y - 1] = true;
	}
	int totalPoint = 0;
	int nDir, nLife;
	while(cin >> ptPos.x >> ptPos.y >> nDir >> nLife){
		int ans = solve(ptPos.x, ptPos.y, nDir, nLife);
		totalPoint += ans;
	}
	cout << totalPoint << endl;
	return 0;
}