#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n;
long long arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  vector<pair<int, pair<int, int>>> sol;
  sol.push_back({1, {n, 50000}});
  for(int i = 1 ; i <= n ; i++)
    sol.push_back({2, {i, arr[i - 1] + 50000 - i}});
  cout << sz(sol) << endl;
  for(int i = 0 ; i < sz(sol) ; i++)
    cout << sol[i].first << " " << sol[i].second.first << " " << sol[i].second.second << endl;
  return 0;
}
