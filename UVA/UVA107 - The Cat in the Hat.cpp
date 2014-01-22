#include <iostream>
#include <cmath>

using namespace std;

int catHeight, catWork;

void solve(){
	if(catHeight == catWork && catWork == 1){
        cout << "0 1\n";
        return ;
    }
    int numCat = 1, totalHeight = catHeight + catWork;
	int stages;
    for(stages = 1; catHeight != int(pow(1. + pow(catWork, 1. / stages), stages) + 0.1); stages ++);

    int hats = int(pow(catWork, 1. / stages) + 0.1);
    for(int i = 1; i < stages; i ++){
        numCat += int(pow(hats * 1., i));
        totalHeight += int(pow(hats * 1., i) / pow(hats + 1., i) * catHeight + 0.1);
    }
    cout << numCat << " " << totalHeight << endl;
    return;
}

int main(){
	while(cin >> catHeight >> catWork && catHeight && catWork){
		solve();
	}
	return 0;
}