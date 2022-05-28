// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n, m;
pair<int, int> A[N], B[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> A[i].first;
  }
  for(int i = 0; i < n; i++) {
    cin >> A[i].second;
  }
  for(int i = 0; i < m; i++) {
    cin >> B[i].first;
  }
  for(int i = 0; i < m; i++) {
    cin >> B[i].second;
  }
  sort(A, A + n);
  reverse(A, A + n);
  sort(B, B + m);
  reverse(B, B + m);

  int j = 0;
  multiset<int> st;
  for(int i = 0; i < n; i++) {
    while(j < m && B[j].first >= A[i].first) {
      st.insert(B[j].second);
      j++;
    }
    auto it = st.lower_bound(A[i].second);
    if(it == st.end()) {
      cout << "No" << endl;
      return 0;
    }
    st.erase(it);
  }
  cout << "Yes" << endl;
  return 0;
}
