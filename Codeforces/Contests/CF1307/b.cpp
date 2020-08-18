#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, x;
int arr[N];

int solve(int d)
{
  if(d > x)
    return 2;
  if(d == x)
    return 1;
  return (x + d - 1) / d;
}

int main()
{
  int t;
  cin >> t;
  while(t--){
    cin >> n >> x;
    bool found = false;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
      if(arr[i] == x)
        found = true;
    }
    int best = 2e9;
    for(int i = 0 ; i < n ; i++){
      best = min(best, solve(arr[i]));
    }
    cout << best << endl;
  }
  return 0;
}
