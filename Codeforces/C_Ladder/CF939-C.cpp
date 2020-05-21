// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, s, f;
int arr[N];
int cnt[N];

void add(int l, int r, int val) {
  if(r <= 0)
    return void(add(l + n, r + n, val));
  if(l >= 1) {
    cnt[l] += val;
    cnt[r + 1] -= val;
  } else {
    cnt[0] += val;
    cnt[r + 1] -= val;
    cnt[l + n] += val;
  }
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  cin >> s >> f; f--;
  for(int i = 0 ; i < n ; i++) {
    add(s - i, f - i, arr[i]);
  }
  int best = 1;
  for(int i = 2 ; i <= n ; i++) {
    cnt[i] += cnt[i - 1];
    if(cnt[i] > cnt[best])
      best = i;
  }
  cout << best << endl;
  return 0;
}
