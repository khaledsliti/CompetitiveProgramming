#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3505;

int n, m, k;
int arr[N];

int solve()
{
  int ch = min(k, m - 1);
  int rem = m - 1 - ch;
  int best = 0;
  // D(ch);
  // D(rem);
  for(int i = 0 ; i <= ch ; i++){
    int st = i, en = n - (ch - i) - 1;
    int cur = 2e9;
    for(int p = 0 ; p <= rem ; p++){
      cur = min(cur, max(arr[st + p], arr[en - (rem - p)]));
    }
    // D(i);
    // D(cur);
    best = max(best, cur);
  }
  return best;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
      cin >> arr[i];
    cout << solve() << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity