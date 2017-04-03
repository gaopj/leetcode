#include<vector>
#include<map>
using namespace std;

 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
	int mmax = 0;
	bool allsame = true;
	int maxPoints(vector<Point>& points) {
		if (points.empty())
			return 0;
		if (points.size() < 2)
			return 1;
		for (size_t i = 0; i <points.size(); i++)
		{
			map<float, int> k;
			map<float, int> kk;
			int samecount = 0;
			for (size_t j = 0; j < points.size(); j++)
			{
				if (i == j)
					continue;
				if (points[j].x == points[i].x&&points[j].y == points[i].y)
				{
					samecount++;
					continue;
				}
				allsame = false;
				int fenmu = points[j].x - points[i].x;
				int fenzi = points[j].y - points[i].y;
				if (fenmu == 0)
				{
					if (!kk.count(points[j].x))
						kk[points[j].x] = 2;
					else
						kk[points[j].x]++;
				}
				else
				{
					float k0 = (1.0f*fenzi / fenmu);
					if (!k.count(k0))
						k[k0] = 2;
					else
						k[k0]++;
				}
			}
			map<float, int>::iterator q = k.begin();
			int max = q->second;
			for (; q!=k.end(); q++)
			{
				if (q->second > max)
					max = q->second;
			}
			 q = kk.begin();
			for (; q != kk.end(); q++)
			{
				if (q->second > max)
					max = q->second;
			}
			if (mmax < max + samecount)
				mmax = max+samecount;
		}
		if (allsame)
			mmax++;
		return mmax;
	}
};

int main()
{
	Solution s;
	vector<Point> points;
	Point p1 = Point(0, 0);
	Point p2 = Point(0, 1);
	//Point p3 = Point(1, -1);
	points.push_back(p1);
	points.push_back(p2);
//	points.push_back(p3);
	s.maxPoints(points);
	return 0;
}