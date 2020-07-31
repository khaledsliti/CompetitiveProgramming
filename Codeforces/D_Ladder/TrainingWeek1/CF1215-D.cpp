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
char s[N];

int main()
{
  scanf("%d%s", &n, s);
  int sum_l = 0, sum_r = 0;
  int left = 0, right = 0;
  for(int i = 0; i < n / 2; i++) {
    if(s[i] == '?') left++;
    else sum_l += s[i] - '0';
  }
  for(int i = n / 2; i < n; i++) {
    if(s[i] == '?') right++;
    else sum_r += s[i] - '0';
  }

  for(int i = left + right, t = 0; i > 0; i--, t ^= 1) {
    if(t == 0) {
      if(sum_l > sum_r) {
        if(left > 0) sum_l += 9, left--;
        else sum_r += 1, right--;
      } else if(sum_l < sum_r) {
        if(right > 0) sum_r += 9, right--;
        else sum_l += 1, left--;
      } else {
        if(left <= right && left > 0 || right == 0) sum_l += 1, left--;
        else sum_r += 1, right--;
      }
    } else {
      if(sum_l > sum_r) {
        if(right > 0) sum_r += min(9, sum_l - sum_r), right--;
        else sum_l += 1, left--;
      } else if(sum_l < sum_r) {
        if(left > 0) sum_l += min(9, sum_r - sum_l), left--;
        else sum_r += 1, right--;
      } else {
        if(left <= right) sum_r += 1, right--;
        else sum_l += 1, left--;
      }
    }
    // cout << sum_l << " " << left << " " << sum_r << " " << right << endl;
  }

  // cout << sum_l << " " << sum_r << endl;
  if(sum_l == sum_r) cout << "Bicarp" << endl;
  else cout << "Monocarp" << endl;

  return 0;
}
