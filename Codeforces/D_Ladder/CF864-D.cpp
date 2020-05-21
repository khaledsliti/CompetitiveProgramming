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
int arr[N], cnt[N], ans[N], done[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    cnt[arr[i]]++;
  }
  vector<int> need;
  for(int i = 1; i <= n; i++) {
    if(cnt[i] == 0) {
      need.push_back(i);
    }
  }
  int idx = 0;
  for(int i = 0; i < n && idx < sz(need); i++) {
    if(cnt[arr[i]] == 1) {
      continue;
    }
    if(arr[i] > need[idx] || done[arr[i]]) {
      --cnt[arr[i]];
      arr[i] = need[idx];
      idx++;
    } else {
      done[arr[i]] = 1;
    }
  }
  printf("%d\n", sz(need));
  for(int i = 0; i < n; i++)
    printf("%d%c", arr[i], " \n"[i == n - 1]);
  return 0;
}
