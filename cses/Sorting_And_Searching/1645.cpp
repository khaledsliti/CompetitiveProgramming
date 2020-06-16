// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int x[N];

int main()
{
  cin >> n;
  stack<pair<int, int>> st;
  st.push({-1, -1});
  for(int i = 0; i < n; i++) {
    cin >> x[i];
    while(st.top().first >= x[i]) st.pop();
    cout << st.top().second + 1 << " ";
    st.push({x[i], i});
  }
  cout << endl;
  return 0;
}
