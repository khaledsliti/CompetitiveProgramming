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

namespace time_lib {
  std::chrono::system_clock::time_point start, last_time_cap;

  void init_time()
  {
    last_time_cap = start = std::chrono::high_resolution_clock::now();
  }

  void print_time(string name = "None")
  {
    chrono::system_clock::time_point now = std::chrono::high_resolution_clock::now();
    long long from_start = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    long long from_last = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_time_cap).count();
    cerr << name << " - from last = " << from_last << " ms, from start = " << from_start << " ms.\n";
    last_time_cap = now;
  }
}

const int N = 2e4 + 1;
int smf[N];

vector<int> fact(int n) {
  vector<int> f;
  for(int i = n; i > 1; i /= smf[i])
    f.push_back(smf[i]);
  return f;
}

int calc(int n) {
  vector<int> a = fact(n % 2 == 0 ? n / 2 : n);
  vector<int> b = fact(n % 2 == 0 ? n + 1 : (n + 1) / 2);
  a.insert(end(a), all(b));
  sort(all(a));
  int res = 1;
  for(int i = 0; i < sz(a); i++) {
    int j = i;
    while(j < sz(a) && a[i] == a[j])
      ++j;
    res *= j - i + 1;
    i = j - 1;
  }
  return res;
}

int main()
{
  time_lib::init_time();
  for(int i = 0; i < N; i++)
    smf[i] = i;
  for(int i = 2; i * i < N; i++)
    if(smf[i] == i) {
      for(int j = i * i; j < N; j += i)
        smf[j] = min(smf[j], i);
    }
  for(int i = 2 ; i < N; i++) {
    if(calc(i) > 500) {
      cout << 1LL * i * (i + 1) / 2 << endl;
      break;
    }
  }
  time_lib::print_time("end");
  return 0;
}
