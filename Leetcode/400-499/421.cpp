#include <bits/stdc++.h>
using namespace std;

const int C = 30;

struct TrieNode{
  TrieNode* child[2];
  TrieNode(){
    child[0] = child[1] = NULL;
  }
  void insert(int val, int index){
    if(index == -1)
      return;
    int current = (val >> index) & 1;
    if(child[current] == NULL)
      child[current] = new TrieNode();
    child[current]->insert(val, index - 1);
  }
  int getMax(int val, int index){
    if(index == -1)
      return 0;
    int need = (val >> index) & 1 ^ 1;
    int can = (1 << index);
    if(!child[need]){
      can = 0;
      need ^= 1;
    }
    return can + child[need]->getMax(val, index - 1);
  }
};

class Solution {
public:
  int findMaximumXOR(vector<int>& nums){
    TrieNode* trie = new TrieNode();
    int n = (int)nums.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      if(i)
        ans = max(ans, trie->getMax(nums[i], C));
      trie->insert(nums[i], C);
    }
    return ans;
  }
};

int main(){
  return 0;
}
