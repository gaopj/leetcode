#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>nodeMap;
		queue<UndirectedGraphNode *> visit;
		visit.push(node);
		UndirectedGraphNode * nodeCopy = new UndirectedGraphNode(node->label);
		nodeMap[node] = nodeCopy;
		while (visit.size()>0){
			UndirectedGraphNode * cur = visit.front();
			visit.pop();
			for (int i = 0; i<cur->neighbors.size(); i++){
				UndirectedGraphNode *neighb = cur->neighbors[i];
				if (nodeMap.find(neighb) == nodeMap.end()){
					UndirectedGraphNode *neighCopy = new UndirectedGraphNode(neighb->label);
					nodeMap[cur]->neighbors.push_back(neighCopy);
					nodeMap[neighb] = neighCopy;
					visit.push(neighb);
				}
				else{
					nodeMap[cur]->neighbors.push_back(nodeMap[neighb]);
				}
			}

		}
		return nodeCopy;
	}
};