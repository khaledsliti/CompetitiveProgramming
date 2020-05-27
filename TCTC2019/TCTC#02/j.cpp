#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e3 + 4;

int n;
int x[N], y[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> x[i] >> y[i];
  for(int i = 0 ; i < n ; i++){
    int dist = 2e9;
    int cnt = 0;
    for(int j = 0 ; j < n ; j++){
      if(i == j)
        continue;
      int cur = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      if(cur < dist){
        dist = cur;
        cnt = 1;
      }else if(cur == dist)
        cnt++;
    }
    cout << dist << " " << cnt << endl;
  }
  return 0;
}
