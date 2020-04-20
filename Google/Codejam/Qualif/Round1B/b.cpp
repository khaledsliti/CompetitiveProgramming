// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int R;

string ask(int x, int y) {
  cout << x << " " << y << endl;
  cout.flush();
  string s;
  cin >> s;
  return s;
}

int main()
{
  int T, tc = 1;
  cin >> T >> R >> R;
  while(T--) {
    int X, Y;
    int l = 0, r = 1e9, right = 0;
    int left = 0, up = 0, down = 0;
    bool found = false;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      string res = ask(mid, 0);
      if(res == "CENTER") {
        found = true;
        break;
      } else if(res == "HIT") {
        right = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    l = -1e9, r = 0;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      string res = ask(mid, 0);
      if(res == "CENTER") {
        found = true;
        break;
      } else if(res == "HIT") {
        left = mid;
        r = mid - 1;
      } else {
        l = mid  + 1;
      }
    }
    l = 0, r = 1e9;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      string res = ask(0, mid);
      if(res == "CENTER") {
        found = true;
        break;
      } else if(res == "HIT") {
        up = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    l = -1e9, r = 0;
    while(l <= r) {
      int mid = l + (r - l) / 2;
      string res = ask(0, mid);
      if(res == "CENTER") {
        found = true;
        break;
      } else if(res == "HIT") {
        down = mid;
        r = mid - 1;
      } else {
        l = mid  + 1;
      }
    }
    if(!found) {
      X = left + (right - left) / 2;
      Y = down + (up - down) / 2;
      string res = ask(X, Y);
      assert(res == "CENTER");
    }
  }
  return 0;
}
