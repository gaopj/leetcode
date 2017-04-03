#include<string>
#include<queue>
#include <hash_set>
#include <unordered_set>
#include <unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	typedef unordered_set<string>::iterator HashIter;
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		queue<string> Q;
		Q.push(beginWord); Q.push("");
		bool hasFound = false;
		unordered_map<string, vector<string> >prePath;//ǰ��·��
		unordered_set<string> hashtable;//��֤bfsʱ������е�Ԫ�ز������ظ�
		while (Q.empty() == false)
		{
			string str = Q.front(), strCopy = str;
			Q.pop();
			if (str != "")
			{
				int strLen = str.length();
				for (int i = 0; i < strLen; i++)
				{
					char tmp = str[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (c == tmp)continue;
						str[i] = c;
						if (str == endWord)
						{
							hasFound = true;
							prePath[endWord].push_back(strCopy);
							//�ҵ���һ�����·������ǰ���ʵ�����ת����û��Ҫ
							goto END;
						}
						if (wordList.find(str) != wordList.end())
						{
							prePath[str].push_back(strCopy);
							//��֤bfsʱ������е�Ԫ�ز������ظ�
							if (hashtable.find(str) == hashtable.end())
							{
								Q.push(str); hashtable.insert(str);
							}
						}
					}
					str[i] = tmp;
				}
			}
			else if (Q.empty() == false)//����ǰ��Ľ�β���Ҳ������һ��Ľ�β
			{
				if (hasFound)break;
				//���������ѭ������bfs��һ�������е�Ԫ�ش��ֵ���ɾ��
				for (HashIter ite = hashtable.begin(); ite != hashtable.end(); ite++)
					wordList.erase(*ite);
				hashtable.clear();
				Q.push("");
			}
		END:;
		}
		vector<vector<string> > res;
		if (prePath.find(endWord) == prePath.end())return res;
		vector<string> tmpres;
		tmpres.push_back(endWord);
		ConstructResult(prePath, res, tmpres, beginWord, endWord);
		return res;
	}

private:
	//��ǰ��·���л��ݹ���path
	void ConstructResult(unordered_map<string, vector<string> > &prePath,
		vector<vector<string> > &res, vector<string> &tmpres,
		string &start, string &end)
	{
		if (start == end)
		{
			reverse(tmpres.begin(), tmpres.end());
			res.push_back(tmpres);
			reverse(tmpres.begin(), tmpres.end());
			return;
		}
		vector<string> &pre = prePath[end];
		for (int i = 0; i < pre.size(); i++)
		{
			tmpres.push_back(pre[i]);
			ConstructResult(prePath, res, tmpres, start, pre[i]);
			tmpres.pop_back();
		}

	}

};