class Node {
public:
  int val;
  vector<Node*> neighbors;

  Node() {}

  Node(int _val, vector<Node*> _neighbors) {
  val = _val;
  neighbors = _neighbors;
  }
};

class Solution {
  unordered_map<Node*, Node*> cloned;
  unordered_set<Node*> vis;

  Node* getClonedNode(Node* node){
    if(!cloned.count(node))
      cloned[node] = new Node(node->val, vector<Node*>());
    return cloned[node]; 
  }

public:
  Node* cloneGraph(Node* node) {
    if(node == NULL)
      return node;
    queue<Node*> q;
    q.push(node);
    vis.insert(node);
    while(!q.empty()){
      Node* u = q.front();
      q.pop();
      for(int i = 0 ; i < (int)u->neighbors.size() ; i++){
        Node* v = u->neighbors[i];
        Node* a = getClonedNode(u);
        Node* b = getClonedNode(v);
        a->neighbors.push_back(b);
        if(vis.find(v) == vis.end()){
          vis.insert(v);
          q.push(v);
        }
      }
    }
    return getClonedNode(node);
  }
};