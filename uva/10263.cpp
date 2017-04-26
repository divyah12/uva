#include<iostream>
#include<vector>
#include <math.h>       /* sqrt */
#include <iomanip>      // std::setprecision

#define EPS 1e-9
#define INF 1e9
#define endl '\n'

using namespace std;

struct point {
	double x, y;
	// only used if more precision is needed
	point() { x = y = 0.0; }
	// default constructor
	point(double _x, double _y) : x(_x), y(_y) {}
}; // user-defined

struct line {
	double a, b, c;
	// a way to represent a line
};

double dist(point p1, point p2) {
	// Euclidean distance
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	//return hypot(p1.x - p2.x, p1.y - p2.y);
	return sqrt(((p1.x - p2.x)*(p1.x - p2.x))+((p1.y - p2.y)*(p1.y - p2.y)));
} // return double

struct vec {
	double x, y;
	// name: ‘vec’ is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
	return vec(v.x * s, v.y * s);
} // shorter.same.longer

point translate(point p, vec v) { // translate p according to v
	return point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u)); // translate a to c
	return dist(p, c);
} // Euclidean distance between p and c

  // returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y); // closer to a
		return dist(p, a);
	} // Euclidean distance between p and a
	if (u > 1.0) {
		c = point(b.x, b.y); // closer to b
		return dist(p, b);
	} // Euclidean distance between p and b
	return distToLine(p, a, b, c);
} // run distToLine as above

int main() {
	int N;
	point m, previousresult;
	//cin >> x_m;	
	while (cin >> m.x) {//reading point M
		cin >> m.y;
		cin >> N;
		vector<point> vertex;
		for (int i = 0; i < (2 * N + 2) / 2; i++)
		{//reading the x and y cordinates as points to the vector(vertex)
			double x, y;
			cin >> x;
			cin >> y;
			vertex.push_back(point(x, y));
		}
		point p;
		if (N == 0) {
			//when N==0 implies no line
			//should output the previous result
			p = previousresult;
		}
		else
		{
			double max = INF;//maximum value
			for (int i = 0; i < N; i++)
			{
				point temp;
				//cout << vertex[i].x << "," << vertex[i].y << endl;
				double dist_lineseg = distToLineSegment(m, vertex[i], vertex[i + 1], temp);
				//finding the min disatnce from temp point
				if (dist_lineseg < max) {
					max = dist_lineseg;
					p = temp;
				}
			}previousresult = p;//previous (x,y) is strored for special condition
		}//fixed 4 decimal point
		cout.precision(4);
		cout << fixed;
		cout << p.x << endl;
		cout << p.y << endl;
	}
	return 0;
}