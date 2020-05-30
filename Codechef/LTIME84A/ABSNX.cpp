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

const int N = 3e5 + 5;
const int L = 19;
const int Inf = 2e9;

int n;
int arr[N];
int gte[N][L], lte[N][L];
int gt[N], lt[N];

void bf() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int mn = arr[i], mx = arr[i];
    for(int j = i; j < n; j++) {
      mx = max(mx, arr[j]);
      mn = min(mn, arr[j]);
      if(abs(arr[i] - arr[j]) == mx - mn)
        ans++;
    }
  }
  cout << ans << endl;
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  stack<pair<int, int>> st;

  st.push({Inf, n});
  for(int j = 0; (1 << j) < n; j++)
    gte[n][j] = n;
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first < arr[i])
      st.pop();
    gte[i][0] = st.top().second;
    st.push({arr[i], i});
  }
  while(!st.empty())
    st.pop();
  
  for(int j = 0; (1 << j) < n; j++)
    lte[n][j] = n;
  st.push({0, n});
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first > arr[i])
      st.pop();
    lte[i][0] = st.top().second;
    st.push({arr[i], i});
  }
  while(!st.empty())
    st.pop();
  
  st.push({Inf, n});
  gt[n] = n;
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first <= arr[i])
      st.pop();
    gt[i] = st.top().second;
    st.push({arr[i], i});
  }
  while(!st.empty())
    st.pop();

  lt[n] = n;
  st.push({0, n});
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first >= arr[i])
      st.pop();
    lt[i] = st.top().second;
    st.push({arr[i], i});
  }
  while(!st.empty())
    st.pop();

  // build sparse
  for(int i = n - 1; i >= 0; i--)  
    for(int j = 1; (1 << j) < n; j++) {
      gte[i][j] = gte[gte[i][j - 1]][j - 1];
      lte[i][j] = lte[lte[i][j - 1]][j - 1];
    }

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(lt[i] >= gt[i]) {
      int right = lt[i];
      // cnt number of steps to reach >= right using gte
      int steps = 0, cur = i;
      int j = 0;
      while((1 << j) < n) j++;
      for(j-- ; j >= 0; j--) {
        if(gte[cur][j] < right) {
          steps |= (1 << j);
          cur = gte[cur][j];
        }
      }
      ans += 1 + steps;
    } else {
      int right = gt[i];
      // cnt number of steps to reach >= right using lte
      int steps = 0, cur = i;
      int j = 0;
      while((1 << j) < n) j++;
      for(j--; j >= 0; j--) {
        if(lte[cur][j] < right) {
          steps |= (1 << j);
          cur = lte[cur][j];
        }
      }
      ans += 1 + steps;
    }
  }

  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
