#include<hash_map>
#include<vector>
#include<list>
using namespace std;
struct CacheNode{
	int key;
	int value;
	CacheNode(int k, int v) : key(k), value(v){}
};
class LRUCache{
public:
	int size;
	list<CacheNode> duilie;
	hash_map<int, list<CacheNode>::iterator> res;
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (res.count(key))
		{
			auto it = res[key];		
			duilie.splice(duilie.begin(), duilie, it);
			return duilie.begin()->value;
		}
		else
		{
			return -1;
		}
	}

	void set(int key, int value) {
		if (res.count(key))
		{
			auto it = res[key];
			duilie.splice(duilie.begin(), duilie, it);
			res[key] = duilie.begin();
			duilie.begin()->value = value;
		}
		else
		{
			if (duilie.size() >= size)
			{
				res.erase(duilie.back().key);
				duilie.pop_back();
			}
			duilie.push_front(CacheNode(key, value));
			res[key] = duilie.begin();
			//duilie.insert(duilie.begin(), key);
		}
		//res[key] = value;

	}
};

int main()
{
	int a = 0;
	LRUCache s(2);
	s.set(2, 1);
	s.set(1, 1); 
	a=s.get(2);
	s.set(4, 1); 
	a=s.get(1);
	a=s.get(2);

	return 0;
}