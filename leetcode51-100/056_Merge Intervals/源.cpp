#include<vector>

using namespace std;

struct Interval {
    int start;
     int end;
    Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:

	bool canmergeAnum(vector<Interval>& intervals, Interval inte, vector<Interval>::iterator & pos)
	{
		pos = intervals.begin();
		for (;pos!=intervals.end(); pos++)
		{
			if ((pos->start <= inte.start&&pos->end >= inte.start) || (pos->start <= inte.end&&pos->end >= inte.end) || (pos->start <= inte.start&&pos->end >= inte.end) || (pos->start >= inte.start&&pos->end <= inte.end))
				return true;
		}
		return false;
	}

	void mergeAnum(vector<Interval>& intervals, Interval inte)
	{

		vector<Interval>::iterator mergep;
		if (canmergeAnum(intervals, inte, mergep))
		{
			Interval temp((inte.start<mergep->start ? inte.start : mergep->start), (inte.end>mergep->end ? inte.end : mergep->end));
			intervals.erase(mergep);
			mergeAnum(intervals, temp);
		}
		else
		{
			intervals.push_back(inte);
		}

	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		for (int i = 0; i < intervals.size(); i++)
		{
			mergeAnum(res, intervals[i]);
		}
		return res;
	}
};