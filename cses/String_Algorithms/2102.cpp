// RedStone
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

const int A = 26;
const int N = 5e5 + 1;

int n;
char s[N];
int suff[N], rnk[N], t_rnk[N];

struct Comparator {
  int len;
  Comparator(int len) : len(len) {}
  bool operator()(const int& i, const int& j) const {
    return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + len] < rnk[j + len]);
  }
};

void BuildSuffArray() {
  int len;
  for (len = 0; !len || s[len - 1]; len++) {
    rnk[len] = s[len];
    suff[len] = len;
  }
  t_rnk[0] = 0;
  for (int width = 1; t_rnk[len - 1] != len - 1; width <<= 1) {
    Comparator isSmaller(width);
    sort(suff, suff + len, isSmaller);
    for (int i = 1; i < len; i++) {
      t_rnk[i] = t_rnk[i - 1] + isSmaller(suff[i - 1], suff[i]);
    }
    for (int i = 0; i < len; i++) {
      rnk[suff[i]] = t_rnk[i];
    }
  }
}

int Count(const string& t) {
  int start = 1, end = n, level = 0;
  for (char c : t) {
    int low = start, high = end, newStart = -1;
    while (low <= high) {
      int mid = low + high >> 1;
      if (s[suff[mid] + level] >= c) {
        newStart = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if (newStart == -1 || s[suff[newStart] + level] != c) {
      return 0;
    }
    low = newStart, high = end;
    int newEnd = newStart;
    while (low <= high) {
      int mid = low + high >> 1;
      if (s[suff[mid] + level] == c) {
        newEnd = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    start = newStart;
    end = newEnd;
    level++;
  }
  return end - start + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  n = strlen(s);
  BuildSuffArray();

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string t;
    cin >> t;
    cout << (Count(t) ? "YES" : "NO") << endl;
  }

  return 0;
}
