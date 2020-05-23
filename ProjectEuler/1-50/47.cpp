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

const int N = 1000000;

int cnt[N], pr[N];

int main()
{
  for(int i = 2; i < N; i++) {
    pr[i] = 1;
  }
  for(int i = 2; i < N; i++) {
    if(pr[i]) {
      cnt[i] = 1;
      for(int j = 2 * i; j < N; j += i)
        pr[j] = 0, cnt[j]++;
    }
  }
  for(int i = 2; i + 3 < N; i++) {
    if(cnt[i] == 4 && cnt[i + 1] == 4 && cnt[i + 2] == 4 && cnt[i + 3] == 4){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
