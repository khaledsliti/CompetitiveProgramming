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

long long sum(long long a, long long b) {
  if (a > b) return 0;
  return (b - a + 1) * (a + b) / 2;
}

int main()
{
  long long n, a, b;
  cin >> n >> a >> b;

  long long lcm = a * b / __gcd(a, b);
  long long s = a * sum(1, n / a) + b * sum(1, n / b) - lcm * sum(1, n / lcm);
  cout << sum(1, n) - s << endl;
  return 0;
}
/*
3 6 9 -> 3
5 10 -> 2

3 5 6 9 10
*/