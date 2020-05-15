// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3001;

int n;
int arr[N];

void solve() {
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  map<int, int> cnt;
  for(int i = 0 ; i < n ; i++) {
    int j = i;
    while(j < n && arr[i] == arr[j])
      j++;
    cnt[arr[i]] += (j - i + 1) / 2;
    i = j - 1;
  }
  int best = 0, At = -1;
  for(auto p : cnt) {
    if(p.second > best || p.second == best && At > p.first) {
      best = p.second;
      At = p.first;
    }
  }
  cout << At << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
