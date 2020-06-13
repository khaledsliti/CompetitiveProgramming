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

const int N = 20001;

int n, k;
int d[N], tp[N], isp[N];
bool g[N][N];

int bases[]={15591,2018,166,7429,8064,16045,10503,4399,1949,1295,2776,3620,560,3128,5212,
  2657,2300,2021,4652,1471,9336,4018,2398,20462,10277,8028,2213,6219,620,3763,4852,5012,3185,
  1333,6227,5298,1074,2391,5113,7061,803,1269,3875,422,751,580,4729,10239,746,2951,556,2206,
  3778,481,1522,3476,481,2487,3266,5633,488,3373,6441,3344,17,15105,1490,4154,2036,1882,1813,
  467,3307,14042,6371,658,1005,903,737,1887,7447,1888,2848,1784,7559,3400,951,13969,4304,177,41,
  19875,3110,13221,8726,571,7043,6943,1199,352,6435,165,1169,3315,978,233,3003,2562,2994,10587,
  10030,2377,1902,5354,4447,1555,263,27027,2283,305,669,1912,601,6186,429,1930,14873,1784,1661,
  524,3577,236,2360,6146,2850,55637,1753,4178,8466,222,2579,2743,2031,2226,2276,374,2132,813,
  23788,1610,4422,5159,1725,3597,3366,14336,579,165,1375,10018,12616,9816,1371,536,1867,10864,
  857,2206,5788,434,8085,17618,727,3639,1595,4944,2129,2029,8195,8344,6232,9183,8126,1870,3296,
  7455,8947,25017,541,19115,368,566,5674,411,522,1027,8215,2050,6544,10049,614,774,2333,3007,
  35201,4706,1152,1785,1028,1540,3743,493,4474,2521,26845,8354,864,18915,5465,2447,42,4511,
  1660,166,1249,6259,2553,304,272,7286,73,6554,899,2816,5197,13330,7054,2818,3199,811,922,350,
  7514,4452,3449,2663,4708,418,1621,1171,3471,88,11345,412,1559,194};

bool is_SPRP(int n, int a) {
  int d = n-1, s = 0;
  while ((d&1)==0) ++s, d>>=1;
  ll cur = 1, pw = d;
  while (pw) {
    if (pw & 1) cur = (cur*a) % n;
    a = ((ll)a*a) % n;
    pw >>= 1;
  }
  if (cur == 1) return true;
  for (int r=0; r<s; r++) {
    if (cur == n-1) return true;
    cur = (cur*cur) % n;
  }
  return false;
}


bool isPrime(int x) {
  if (x==2 || x==3 || x==5 || x==7) return true;
  if (x%2==0 || x%3==0 || x%5==0 || x%7==0) return false;
  if (x<121) return (x>1);
  ll h = x;
  h = ((h >> 16) ^ h) * 0x45d9f3b;
  h = ((h >> 16) ^ h) * 0x45d9f3b;
  h = ((h >> 16) ^ h) & 255;
  return is_SPRP(x, bases[h]);
}

bool check(int a, int b) {
  return isp[a] && isp[b] && isPrime(a * tp[d[b]] + b) && isPrime(b * tp[d[a]] + a);
}

vector<int> ans;
void solve(int cur, vector<int>& p) {
  if(sz(p) == k) {
    int sum = 0;
    for_each(all(p), [&sum](int a){ sum += a; });
    ans.push_back(sum);
    return;
  }
  if(cur >= n) return;
  if(isp[cur]) {
    bool good = true;
    for(int pr : p)
      good &= g[cur][pr];
    if(good) {
      p.push_back(cur);
      solve(cur + 1, p);
      p.pop_back();
    }
  }
  solve(cur + 1, p);
}

int main()
{
  for(int i = 0; i <= 9; i++)
    d[i] = 1;
  for(int i = 10; i < N; i++) {
    d[i] = 1 + d[i / 10];
  }
  tp[0] = 1;
  for(int i = 1; i < 8; i++)
    tp[i] = tp[i - 1] * 10;
  for(int i = 0; i < N; i++)
    isp[i] = isPrime(i);
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      g[i][j] = g[j][i] = check(i, j);
  vector<int> p;
  solve(2, p);
  sort(all(ans));
  ans.resize(unique(all(ans)) - begin(ans));
  for(int x : ans)
    cout << x << endl;
  return 0;
}

//1'999'919'999