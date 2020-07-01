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

const int N = 2e5 + 5;

int n, k;
int arr[N], tmp[N], acc[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  for(int it = 0; it < k; it++) {
    for(int i = 0; i < n; i++) {
      int l = max(0, i - arr[i]);
      int r = min(n - 1, i + arr[i]);
      acc[l]++;
      acc[r + 1]--;
    }
    for(int i = 1; i < n; i++) {
      acc[i] += acc[i - 1];
    }
    bool same = true;
    for(int i = 0; i < n; i++)
      same &= acc[i] == arr[i];
    if(same) break;
    for(int i = 0; i < n; i++) {
      arr[i] = acc[i];
      acc[i] = 0;
    }
  }
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
