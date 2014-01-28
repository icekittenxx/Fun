#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int countryMax = 25;
const int nodeMax = 105;
const double eps = 1e-6;

class Point{
public:
	double x, y;
};

class Polygon{
public:
	Point point[nodeMax], start;
	double area;
	int n;
};

class segment{
public:
	Point a, b;
};

Polygon king[countryMax];
Point grahamPoint[nodeMax], grahamStk[nodeMax];
int grahamStkTop;

// x > y
bool xGy(double x, double y){
	return x > y + eps;
}

// x < y 
bool xSy(double x, double y){
	return x < y - eps;
}

// x >= y 
bool xGEy(double x, double y){
	return x > y - eps;
}

// x <= y
bool xSEy(double x, double y){
	return x < y + eps;
}

// x == y
bool xEy(double x, double y){
	return fabs( x - y ) < eps;
}

//ac ab
double crossProduct(Point a, Point b, Point c){
	return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}

double disPointToPoint(Point a,Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double areaPolygon(Point p[], int n){
	double s = 0.0;
	for(int i = 0; i < n; i ++)
		s += p[(i + 1) % n].y * p[i].x - p[(i + 1)%n].x * p[i].y;
	return fabs(s) / 2.0;
}

bool cmp(Point a, Point b){
	double len = crossProduct(grahamPoint[0], a, b);
	if(xEy(len, 0.0)){
		return xSy(disPointToPoint(grahamPoint[0], a), disPointToPoint(grahamPoint[0], b));
	}
	return xSy(len, 0.0);
}

bool onSegment(Point a, Point b, Point c){
	double maxx = max(a.x, b.x);
	double maxy = max(a.y, b.y);
	double minx = min(a.x, b.x);
	double miny = min(a.y, b.y);
	if(xEy(crossProduct(a, b, c), 0.0)
		&& xGEy(c.x, minx) && xSEy(c.x, maxx) && xGEy(c.y, miny) && xSEy(c.y, maxy))
		return true;
	return false;
}

bool segIntersect(Point p1, Point p2, Point p3, Point p4){
	double d1 = crossProduct(p3, p4, p1);
	double d2 = crossProduct(p3, p4, p2);
	double d3 = crossProduct(p1, p2, p3);
	double d4 = crossProduct(p1, p2, p4);
	if(xSy(d1 * d2, 0.0) && xSy(d3 * d4, 0.0))
		return true;
	if(xEy(d1, 0.0) && onSegment(p3, p4, p1))
		return true;
	if(xEy(d2, 0.0) && onSegment(p3, p4, p2))
		return true;
	if(xEy(d3, 0.0) && onSegment(p1, p2, p3))
		return true;
	if(xEy(d4, 0.0) && onSegment(p1, p2, p4))
		return true;
	return false;
}

bool pointInPolygon(Point pot, Point p[], int n){
	int count = 0;
	segment l;
	l.a = pot;
	l.b.x = 1e10 * 1.0;
	l.b.y = pot.y;
	p[n] = p[0];
	for(int i = 0; i < n; i ++){
		if(onSegment(p[i], p[i + 1], pot))
			return true;
		if(!xEy(p[i].y, p[i + 1].y)){
			int tmp = -1;
			if(onSegment(l.a, l.b, p[i])){
				tmp = i;
			}
			else{
				if(onSegment(l.a, l.b, p[i + 1])){
					tmp = i + 1;
				}
			}

			if(tmp != -1 && xEy(p[tmp].y, max(p[i].y, p[i + 1].y))){
				count ++;
			}
			else{
				if(tmp == -1 && segIntersect(p[i], p[i + 1], l.a, l.b)){
					count ++;
				}
			}
		}
	}
	if(count % 2 == 1){
		return true;
	}
	return false;
}

double graham(int n){
	int tmp = 0;  
	for(int i = 1; i < n; i ++){
		if(xSy(grahamPoint[i].x, grahamPoint[tmp].x)
			|| xEy(grahamPoint[i].x, grahamPoint[tmp].x)
			&& xSy(grahamPoint[i].y, grahamPoint[tmp].y)){
			tmp = i;
		}
	}
	swap(grahamPoint[0], grahamPoint[tmp]);
	sort(grahamPoint + 1, grahamPoint + n, cmp);
	grahamStk[0] = grahamPoint[0];
	grahamStk[1] = grahamPoint[1];
	grahamStkTop = 1;
	for(int i = 2; i < n; i ++){
		while(xSEy(crossProduct(grahamStk[grahamStkTop], grahamStk[grahamStkTop - 1], grahamPoint[i]), 0.0)
			&& grahamStkTop >= 1){
			grahamStkTop --;
		}
		grahamStk[++ grahamStkTop] = grahamPoint[i];
	}
	return areaPolygon(grahamStk, grahamStkTop + 1);
}

void solve(){
	int n;
	int i = 0;
	while(~scanf("%d",&n) && n != -1){
		king[i].n = n;
		for(int k = 0; k < n; k ++)
			scanf("%lf %lf", &king[i].point[k].x, &king[i].point[k].y);
		king[i].start = king[i].point[0];
		i ++;
	}

	double sum = 0.0;
	for(int k = 0; k < i; k ++){
		memcpy(grahamPoint, king[k].point, sizeof king[k].point);
		king[k].area = graham(king[k].n);
		memcpy(king[k].point, grahamStk, sizeof grahamStk);
		king[k].n = grahamStkTop + 1;
	}

	Point pot;
	bool die[countryMax];
	memset(die, false, sizeof die);
	while(~scanf("%lf %lf", &pot.x, &pot.y)){
		for(int k = 0; k < i; k ++){
			if(pointInPolygon(pot, king[k].point, king[k].n) && !die[k]){
				die[k] = true;
				sum += king[k].area;
			}
		}
	}

	printf("%.2lf\n", sum);
}

int main(){
	solve();
	return 0;
}
