#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int oo = 1e9;

struct node{
  int st, en;
  int level;
  bool operator<(const node& rhs) const{
    return this->st < rhs.st;
  }
};

set<node> nodes;

void print()
{
  for(auto x : nodes)
    cout << x.st << " " << x.en << " " << x.level << endl;
  cout << endl;
}

int main()
{
  
  nodes.insert({-oo, oo, 1});
  int n;
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    int cur;
    scanf("%d", &cur);
    auto it = nodes.upper_bound({cur, 0, 0});
    it--;
    int st = it->st;
    int en = it->en;
    int lev = it->level;
    nodes.erase(it);
    printf("%d ", lev);
    nodes.insert({st, cur, ++lev});
    if(cur + 1 <= en)
      nodes.insert({cur + 1, en, lev});
    // print();
  }
  return 0;
}
