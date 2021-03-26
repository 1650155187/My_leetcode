#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

class Point {
public:
	int x, y;
	Point(const int &x, const int &y) {
		this->x = x;
		this->y = y;
	}
};

bool cmp_x(const Point &p, const Point &q) {
	return (p.x < q.x) || ((p.x == q.x) && (p.y < q.y));
}

bool cmp_y(const Point &p, const Point &q) {
	return (p.y < q.y) || ((p.y == q.y) && (p.x < q.x));
}

class Solution {
	vector<Point> ironp;
public:
	vector<vector<int> > ExperimentBox(int rowCount, int colCount,
	 const vector<int>& obstacle, const vector<vector<int> > &irons, string directions) {
	 	int size = irons.size();
	 	ironp.clear();
	 	for (int i = 0; i < size; i ++) {
	 		ironp.push_back(Point(irons[i][0],irons[i][1]));
	 	}
	 	int dirsize = directions.size();
	 	for (int t = 0; t < dirsize; t ++) {
	 		char dir = directions[t];
	 		if (dir == 'U' || dir == 'D') {
	 			sort(ironp.begin(), ironp.end(), cmp_y);
	 			int k = 0;
	 			for (int j = 0; j < size; j ++) {
	 				if ((j == size - 1) || (ironp[j].y != ironp[j + 1].y)) {
	 					int y = ironp[j].y;
	 					bool covered = (y >= obstacle[1] && y <= obstacle[3]);
	 					int up = 0;
	 					int down = 0;
	 					for (int i = k; i <= j; i ++) {
	 						if (covered) {
		 						if (ironp[i].x < obstacle[0]) {
		 							up ++;
		 							if (dir == 'U')
		 								ironp[i].x = up - 1;
		 							else
		 								ironp[i].x = obstacle[0] - up;
		 						} else {
		 							down ++;
		 							if (dir == 'U')
		 								ironp[i].x = obstacle[2] + down;
		 							else
		 								ironp[i].x = rowCount - down;
		 						}
		 					} else {
		 						up ++;
		 						if (dir == 'U')
	 								ironp[i].x = up - 1;
	 							else
	 								ironp[i].x = rowCount - up;
		 					}
	 					}
	 					k = j + 1;
	 				}
	 			}
	 		} else if (dir == 'L' || dir == 'R') {
	 			sort(ironp.begin(), ironp.end(), cmp_x);
	 			int k = 0;
	 			for (int j = 0; j < size; j ++) {
	 				if ((j == size - 1) || (ironp[j].x != ironp[j + 1].x)) {
	 					int x = ironp[j].x;
	 					bool covered = (x >= obstacle[0] && x <= obstacle[2]);
	 					int left = 0;
	 					int right = 0;
	 					for (int i = k; i <= j; i ++) {
	 						if (covered) {
		 						if (ironp[i].y < obstacle[1]) {
		 							left ++;
		 							if (dir == 'L')
		 								ironp[i].y = left - 1;
		 							else
		 								ironp[i].y = obstacle[1] - left;
		 						} else {
		 							right ++;
		 							if (dir == 'L')
		 								ironp[i].y = obstacle[3] + right;
		 							else
		 								ironp[i].y = colCount - right;
		 						}
		 					} else {
		 						left ++;
		 						if (dir == 'L')
	 								ironp[i].y = left - 1;
	 							else
	 								ironp[i].y = colCount - left;
		 					}
	 					}
	 					k = j + 1;
	 				}
	 			}
	 		}
	 	}
	 	sort(ironp.begin(), ironp.end(), cmp_x);
	 	vector<vector<int> > ret;
	 	for (int i = 0; i < size; i ++) {
	 		vector<int> retp;
	 		retp.push_back(ironp[i].x);
	 		retp.push_back(ironp[i].y);
	 		ret.push_back(retp);
	 	}
	 	return ret;
	}

};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;

	cin >> r >> c;
	vector<int> obs;
	for (int i = 0 ; i < 4; i ++) {
		int t;
		cin >> t;
		obs.push_back(t);
	}
	int ironsize;
	cin >> ironsize;
	vector<vector<int> > irons;
 	for (int i = 0; i < ironsize; i ++) {
 		int x, y;
 		cin >> x >> y;
 		vector<int> retp;
 		retp.push_back(x);
 		retp.push_back(y);
 		irons.push_back(retp);
 	}
 	string dir;
 	cin >> dir;

	Solution s;
	vector<vector<int> > ret;
	ret = s.ExperimentBox(r, c, obs, irons, dir);

	int retsize = ret.size();
	for (int i = 0; i < retsize; i ++) {
		cout << ret[i][0] << ' ' << ret[i][1] << endl;
	}
	return 0;
}
