/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3803

  Idea:
    Let's suppose that we want to build a word abcde.
    This word can be formed by prefix "ab" and suffix "cde". Or maybe with "abc" and "de".
    So, we have to count the number of all combinations of prefixes and suffixes,
    than substruct all redundent words.
    The word "abcde" is redundant if and only if we can form it with a smaller prefix (like "abc|de" and "ab|cde").
    So, for each prefix we substruct all suffixes with size greater than of equal to 2 and starting with the last letter of this prefix.
    To get distinct prefixes and suffixes we can use two tries.

  Compexity: N = sum of letters in all prefixes, M = sum of letters in all suffixes.
    Time: O(N)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

const int A = 26;
int n, m;

struct TrieNode
{
  int nxt[A];
  TrieNode()
  {
    memset(nxt, -1, sizeof nxt);
  }
};

vector<TrieNode> prefTrie, suffixTrie;
int startFrom[A];

void init()
{
  prefTrie.clear();
  suffixTrie.clear();
  prefTrie.push_back(TrieNode());
  suffixTrie.push_back(TrieNode());
}

void add(vector<TrieNode>& trie, string& s)
{
  int cur = 0;
  for(int i = 0 ; i < sz(s) ; i++){
    int c = s[i] - 'a';
    if(trie[cur].nxt[c] == -1){
      trie[cur].nxt[c] = sz(trie);
      trie.push_back(TrieNode());
    }
    cur = trie[cur].nxt[c];
  }
}

void bfs(vector<TrieNode>& trie)
{
  memset(startFrom, 0, sizeof startFrom);
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int c = 0 ; c < A ; c++){
      if(trie[cur].nxt[c] != -1){
        q.push(trie[cur].nxt[c]);
        if(cur > 0)
          startFrom[c]++;
      }
    }
  }
}

long long solve()
{
  long long ans = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int c = 0 ; c < A ; c++){
      if(prefTrie[cur].nxt[c] != -1){
        ans += sz(suffixTrie) - 1;
        q.push(prefTrie[cur].nxt[c]);
        if(cur > 0)
          ans -= startFrom[c];
      }
    }
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  while(cin >> n >> m && (n | m)){
    init();
    for(int i = 0 ; i < n ; i++){
      string s;
      cin >> s;
      add(prefTrie, s);
    }
    for(int i = 0 ; i < m ; i++){
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      add(suffixTrie, s);
    }
    bfs(suffixTrie);
    cout << solve() << endl;
  }
  return 0;
}