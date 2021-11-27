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

const int N = 2e7 + 5;

int n;
int a[N], mult[N];
long long dp[N];
int smf[N];

int main()
{
  for(int i = 1; i < N; i++) {
    smf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(smf[i] == i) {
      for(int j = i + i; j < N; j += i) {
        if(smf[j] > i) {
          smf[j] = i;
        }
      }
    }
  }
  
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    mult[a[i]]++;
  }
  for(int i = 1; i < N; i++) {
    for(int j = i + i; j < N; j += i) {
      mult[i] += mult[j];
    }
  }

  dp[1] = n;
  for(int i = 2; i < N; i++) {
    if(mult[i] == 0) continue;
    int a = i;
    while(a != 1) {
      int p = smf[a];
      int nxt = i / p;
      dp[i] = max(dp[i], dp[nxt] + 1LL * (i - nxt) * mult[i]);
      while(smf[a] == p) a /= p;
    }
  }
  cout << *max_element(dp + 1, dp + N - 1) << endl;
  return 0;
}
