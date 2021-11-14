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

const int N = 1e5 + 5;

struct Team {
  int index, score;
  bool operator<(const Team& rhs) const {
    if(score != rhs.score) {
      return score > rhs.score;
    }
    return index < rhs.index;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(all(arr));
  vector<Team> t;
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j < n && arr[i] == arr[j]) {
      j++;
    }
    t.push_back({arr[i], j - i});
    i = j - 1;
  }
  sort(all(t));
  cout << t.front().index << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("challenge.in", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
