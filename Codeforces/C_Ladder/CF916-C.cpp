// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6;

int n, m;
int isp[N];
vector<array<int, 3>> sol;

int main()
{
  cin >> n >> m;
  for(int i = 2 ; i < N ; i++)
    isp[i] = 1;
  for(int i = 2 ; i * i < N ; i++) {
    if(isp[i])
      for(int j = i * 2 ; j < N ; j += i)
        isp[j] = 0;
  }
  int pr;
  for(int i = n ; ; i++)
    if(isp[i]) {
      pr = i;
      break;
    }
  sol.pb({1, n, 2});
  for(int i = 3 ; i < n ; i++)
    sol.pb({1, i, 1});
  if(n > 2)
    sol.pb({1, 2, pr - n + 1});
  for(int i = 2 ; i <= n && sz(sol) < m ; i++) {
    for(int j = i + 1 ; j <= n && sz(sol) < m ; j++) {
      sol.pb({i, j, pr});
    }
  }
  cout << 2 << " " << pr << endl;
  for(auto& e : sol)
    cout << e[0] << " " << e[1] << " " << e[2] << endl;
  return 0;
}
