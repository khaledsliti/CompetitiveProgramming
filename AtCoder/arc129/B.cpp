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

const int N = 2e5 + 4;
const int INF = 2e9;

int n;
int L[N], R[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i= 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }

  int maxL = INT_MIN, minR = INT_MAX;
  for(int i = 0; i < n; i++) {
    maxL = max(maxL, L[i]);
    minR = min(minR, R[i]);
    if(maxL <= minR) cout << 0 << endl;
    else {
      int mid = (maxL + minR) >> 1;
      cout << max(mid - minR, maxL - mid) << endl;
    }
  }
  return 0;
}
