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

const int N = 1003;

int n;
int arr[N], pos[N];
vector<pair<int, int>> vals;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    vals.pb({arr[i], i});
  }
  sort(all(vals));
  int cur = 0;
  for(int i = 0; i < n; i++) {
    arr[vals[i].second] = cur++;
  }
  for(int i = 0; i < n; i++)
    pos[arr[i]] = i;
  vector<pair<int, int>> sol;
  for(int i = n - 1; i >= 0; i--) {
    vector<pair<int, int>> cur;
    for(int j = arr[i] + 1; j < n; j++) {
      if(pos[j] < i) {
        cur.push_back({pos[j], i});
      }
    }
    for(int j = 0; j < sz(cur); j++) {
      int a = cur[j].first, b = cur[j].second;
      swap(pos[arr[a]], pos[arr[b]]);
      swap(arr[a], arr[b]);
      sol.push_back({a + 1, b + 1});
    }
  }
  printf("%d\n", sz(sol));
  for(int i = 0; i < sz(sol); i++)
    printf("%d %d\n", sol[i].first, sol[i].second);
  return 0;
}
