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



const int N = 2e5 + 5;

int n;
int L[N], R[N], C[N];

int getVal(int l, int r, int i) {
  int ans = C[l];
  if(r != l) ans += C[r];
  if(L[i] == L[l] && R[i] == R[r]) {
    ans = min(ans, C[i]);
  }
  return ans;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> L[i] >> R[i] >> C[i];
  }
  int leftIdx = 0, rightIdx = 0;
  int big = 0;
  cout << getVal(leftIdx, rightIdx, big) << endl;
  for(int i = 1; i < n; i++) {
    if(L[i] < L[leftIdx] || L[i] == L[leftIdx] && C[i] < C[leftIdx]) {
      leftIdx = i;
    }
    if(R[i] > R[rightIdx] || R[i] == R[rightIdx] && C[i] < C[rightIdx]) {
      rightIdx = i;
    }
    if(R[i] - L[i] > R[big] - L[big] ||
      R[i] - L[i] == R[big] - L[big] && C[i] < C[big]) {
      big = i;
    }
    cout << getVal(leftIdx, rightIdx, big) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
