#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, q;
int g[2][N];
unordered_set<int> cols;

void update(int col)
{
  // for(int i = 0 ; i < 2 ; i++){
  //   for(int j = 0 ; j < n ; j++)
  //     cout << g[i][j];
  //   cout << endl;
  // }
  // for(auto x : cols)  
  //   cout << x << " ";
  // cout << endl;
  if(col < 0)
    return;
  if(g[0][col] && g[1][col]){
    cols.insert(col);
  }else{
    if(col + 1 >= n){
      cols.erase(col);
    }else{
      bool good = false;
      for(int r = 0 ; r < 2 && !good ; r++){
        if(!g[r][col] && !g[r][col + 1]){
          cols.erase(col);
          good = true;
        }
      }
      if(!good)
        cols.insert(col);
    }
  }
}

void flip(int r, int c)
{
  g[r][c] ^= 1;
  update(c - 1);
  update(c);
}

int main()
{
  scanf("%d%d", &n, &q);
  while(q--){
    int r, c;
    scanf("%d%d", &r, &c);
    flip(--r, --c);
    printf("%s\n", sz(cols) ? "No" : "Yes");
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity