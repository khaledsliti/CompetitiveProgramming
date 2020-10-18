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

// Region Debug
string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0)
      res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

const int N = 5e5 + 5;
const int L = 20;

int n;
char s[N];
int arr[N];
int dp[N][L], lg[N];

int getMax(int l, int r) {
  int i = lg[r - l + 1];
  return max(dp[l][i], dp[r - (1 << i) + 1][i]);
}

int bf() {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int mx = 0, cur = 0;
    for(int j = i; j < n; j++) {
      if(s[j] == '1') cur++;
      else cur = 0;
      mx = max(mx, cur);
      ans += mx;
    }
  }
  return ans;
}

int main()
{
  lg[1] = 0;
  for(int i = 2; i < N; i++) {
    lg[i] = 1 + lg[i >> 1];
  }

  scanf("%d%s", &n, s);
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') {
      int j = i;
      while(j < n && s[j] == '1') {
        j++;
      }
      arr[i] = j - i;
      i = j - 1;
    }
  }

  for(int i = 0; i < n; i++) {
    dp[i][0] = arr[i];
  }
  for(int j = 1; (1 << j) <= n; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] == 0) continue;

    for(int j = 1; j < arr[i]; j++) {
      ans += 1LL * (arr[i] + 1 - j) * j;
    }

    int left = -1, lo = 0, hi = i - 1;
    while(lo <= hi) {
      int mid = (lo + hi) / 2;
      if(getMax(mid, i - 1) >= arr[i]) {
        left = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if(left >= 0) {
      left = left + arr[left] - arr[i];
    }
    left++;

    int right = n; lo = i + arr[i], hi = n - 1;
    while(lo <= hi) {
      int mid = (lo + hi) / 2;
      if(getMax(i + arr[i], mid) > arr[i]) {
        right = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if(right < n) {
      right += arr[i];
    }
    right--;

    ans += 1LL * (i - left + 1) * (right - i - arr[i] + 2) * arr[i];

    for(int take = 1; take < arr[i]; take++) {
      int right = n, lo = arr[i] + i, hi = n - 1;
      while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(getMax(arr[i] + i, mid) > take) {
          right = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      if(right < n) {
        right += take;
      }
      right--;

      ans += 1LL * take * (right - i - arr[i] + 1);

      int left = -1; lo = 0, hi = i - 1;
      while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(getMax(mid, i - 1) >= take) {
          left = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      if(left > -1) {
        left += arr[left] - take;
      }
      left++;

      ans += 1LL * take * (i - 1 - left + 1);

    }
  }

  cout << ans << endl;
  return 0;
}
