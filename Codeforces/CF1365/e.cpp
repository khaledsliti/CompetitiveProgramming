// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 501;

int n;
ll arr[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  ll best = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++)
        best = max(best, arr[i] | arr[j] | arr[k]);
  cout << best << endl;
  return 0;
}
