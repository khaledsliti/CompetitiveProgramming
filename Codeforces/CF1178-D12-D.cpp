#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e3 + 5;

int n;
int isp[N];

int main()
{
  for(int i = 2 ; i < N; i++)
    isp[i] = 1;
  for(int i = 2 ; i * i < N; i++){
    if(isp[i]){
      for(int j = i * i ; j < N ; j += i)
        isp[j] = 0;
    }
  }
  cin >> n;
  vector<pair<int, int>> sol;
  for(int i = 0 ; i < n ; i++){
    sol.push_back({i + 1, (i + 1) % n + 1});
  }
  int cur = 0;
  while(!isp[sz(sol)]){
    sol.push_back({cur + 1, cur + n / 2 + 1});
    cur++;
  }
  cout << sz(sol) << endl;
  for(int i = 0 ; i < sz(sol) ; i++)
    cout << sol[i].first << " " << sol[i].second << endl;
  return 0;
}
