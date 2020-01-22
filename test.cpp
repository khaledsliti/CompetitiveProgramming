#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 25;

long long fact[N];

long long P(long long n, long long r)
{
  return fact[n] / fact[n - r];
}

long long C(long long n, long long k)
{
  return fact[n] / fact[n - k] / fact[k];
}

int main()
{
  fact[0] = 1;
  for(int i = 1 ; i < N ; i++)
    fact[i] = fact[i - 1] * i;
  cout << P(15, 10) / fact[10] * P(20, 10) << endl;
  cout << C(15, 10) * fact[10] * C(20, 10) << endl;
  return 0;
}
