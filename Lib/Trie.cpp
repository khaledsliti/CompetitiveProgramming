#include <vector>
#include <unordered_map>
using namespace std;

const int UNIT_SIZE_BITS = 8;

struct Hash{
  int operator()(const pair<int, int>& p) const {
    return (p.first << UNIT_SIZE_BITS) + p.second;
  }
};

class trie{
  vector<bool> leaf;
  vector<vector<int>> children;
  unordered_map<pair<int, int>, int, Hash> edges;

  void get(int cur, string& tmp, vector<string>& words)
  {
    for(int i = 0 ; i < leaf[cur] ; i++)
      words.emplace_back(tmp);
    for(auto c : children[cur]){
      int nxt = edges[{cur, c}];
      tmp += char(c);
      get(nxt, tmp, words);
      tmp.pop_back();
    }
  }
public:
  trie()
  {
    leaf.emplace_back(0);
    children.emplace_back(vector<int>());
  }
  void insert(char* s)
  {
    int cur = 0;
    for(; *s ; s++){
      int c = *s;
      int& nxt = edges.insert({{cur, c}, -1}).first->second;
      if(nxt == -1){
        children[cur].emplace_back(c);
        nxt = leaf.size();
        leaf.emplace_back(false);
        children.emplace_back(vector<int>());
      }
      cur = nxt;
    }
    leaf[cur] = 1;
  }
  vector<string> get(int root)
  {
    vector<string> words;
    string tmp = "";
    get(root, tmp, words);
    return words;
  }
};
