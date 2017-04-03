#include<vector>
using namespace std;

class Solution {
public:
	int res;
	int candy(vector<int>& ratings){
		int nowjia = 0;
		if (ratings.empty())
			return 0;
		int j = 1;
		res = 1;
		for (; j < ratings.size(); j++)
		{
			if (ratings[j] != ratings[j - 1])
				break;
			else
			{
				res++;
			}
		}
		if (ratings.size() ==j)
			return res;
		bool nowdone = false;

		int inccout = 1;
		int befordown = 0;
		int downlenth = 0;

		if (ratings[j] < ratings[j-1])
		{
			nowdone = true;
			befordown = 1;
			downlenth = 2;
			nowjia = 1;
		}
		else
		{
			nowjia = 2;
		}
		res +=2;
		for (size_t i = j+1; i < ratings.size(); i++)
		{
			if (ratings[i]>ratings[i - 1])
			{
				if (nowdone)
				{
					nowdone = false;
					nowjia = 2;
				}
				else
				{
					nowjia++;
				}
				res += nowjia;;
			}
			else if(ratings[i]<ratings[i - 1])
			{
				if (nowdone)
				{
					downlenth++;
					nowjia++;
					if (nowjia >= befordown)
						res++;
				}
				else
				{
					nowdone = true;
					befordown = nowjia;
					downlenth = 2;
					nowjia = 1;
				}
				res += downlenth-1;

			}
			else
			{
				res++;
				i++;
				for (; i < ratings.size(); i++)
				{
					if (ratings[i] != ratings[i - 1])
						break;
					else
					{
						res++;
					}
				}
				if (ratings.size() == i)
					return res;
				if (ratings[i] < ratings[i - 1])
				{
					nowdone = true;
					befordown = 1;
					downlenth = 2;
					nowjia = 1;
				}
				else
				{
					nowdone = false;
					nowjia = 2;
				}
				res += 2;
			}

		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> s0;
	s0.push_back(1);
	s0.push_back(3);
	s0.push_back(4);
	s0.push_back(3);
	s0.push_back(2);
	s0.push_back(1);

	int res= s.candy(s0);
	return 0;
}