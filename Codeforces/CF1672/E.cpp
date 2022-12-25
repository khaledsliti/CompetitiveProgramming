// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2007;
const int MAX = 2000 * 2000 * 2;

int n;

int ask(int w) {
  cout << "? " << w << endl;
  int r; cin >> r;
  return r;
}

void answer(long long ans) {
  cout << "! " << ans << endl;
}

int getNext(int w, int h) {
  int low = w, high = MAX;
  int last = -1;
  while(low <= high) {
    int mid = (low + high) >> 1;
    int tmp_h = ask(mid);
    if(tmp_h == h) {
      low = mid + 1;
      last = mid;
    } else {
      high = mid - 1;
    }
  }
  assert(last != -1);
  return last + 1;
}

int main()
{
  cin >> n;

  int cur_w = 1;
  long long ans = LLONG_MAX;
  while(true) {
    int cur_h = ask(cur_w);
    if (cur_h > 0) {
      ans = min(ans, 1LL * cur_h * cur_w);
    }
    if(cur_h == 1) {
      break;
    }
    cur_w = getNext(cur_w, cur_h);
  }
  answer(ans);
  return 0;
}
