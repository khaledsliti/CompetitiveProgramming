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

int n;
int arr[N];
int cnt[20];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 20; j++) {
      int cur = arr[i] & 1;
      if(cur) cnt[j]++;
      arr[i] >>= 1;
    }
  }
  ll sum = 0;
  while(true) {
    int a = 0;
    for(int i = 0; i < 20; i++) {
      if(cnt[i] > 0) {
        cnt[i]--;
        a |= (1 << i);
      }
    }
    if(!a) break;
    sum += 1LL * a * a;
  }
  cout << sum << endl;
  return 0;
}
