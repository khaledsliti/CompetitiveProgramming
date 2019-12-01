#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int A = 26;
const int N = 1e6 + 5;

struct Node{
  vector<int> nxt;
  int cnt;
  Node(){
    nxt.resize(A, -1);
    cnt = 0;
  }
};

vector<Node> tr;
char s[N];

void init()
{
  tr.clear();
  tr.push_back(Node());
}

void insert(char* s) // O(len(s))
{
  int cur = 0;
  tr[0].cnt++;
  for(int i = 0 ; s[i] ; i++){
    int c = s[i] - 'a';
    if(tr[cur].nxt[c] == -1){
      tr[cur].nxt[c] = sz(tr);
      tr.push_back(Node());
    }
    cur = tr[cur].nxt[c];
    tr[cur].cnt++;
  }
}

// O(sz(tr))
string str;
void dfs_1(int cur)
{
  int children_count = 0;
  for(int i = 0 ; i < A ; i++){
    if(tr[cur].nxt[i] != -1){
      children_count += tr[tr[cur].nxt[i]].cnt;
      str.push_back(char('a' + i));
      dfs_1(tr[cur].nxt[i]);
      str.pop_back();
    }
  }
  int need = tr[cur].cnt - children_count;
  while(need--)
    cout << str << endl;
}

int dfs(int cur, int lev)
{
  if(tr[cur].cnt == 1)
    return lev;
  int r = 0;
  for(int i = 0 ; i < A ; i++){
    if(tr[cur].nxt[i] != -1)
      r += dfs(tr[cur].nxt[i], lev + 1);
  }
  return r;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    init();
    while(n--){
      scanf("%s", s);
      insert(s);
    }
    tr[0].cnt++;
    printf("%d\n", dfs(0, 0));
  }
  return 0;
}
