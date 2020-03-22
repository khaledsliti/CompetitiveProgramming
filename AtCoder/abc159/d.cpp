// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int arr[N];
map<int, int> cnt;

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  long long ans = 0;
  for(auto p : cnt) {
    int cur = p.second;
    ans += 1LL * cur * (cur - 1) / 2;
  }
  for(int i = 0 ; i < n ; i++) {
    int cur = cnt[arr[i]];
    long long v = ans - cnt[arr[i]] + 1;
    cout << v << endl;
  }
  return 0;
}
