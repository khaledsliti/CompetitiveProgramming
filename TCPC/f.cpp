#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n, d, k;
pair<int, int> s[N];


int main()
{
  scanf("%d%d%d", &n, &d, &k);
  for(int i = 0 ; i < n ; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    s[i] = {d - x, y};
  }
  sort(s, s + n);
  
  return 0;
}
