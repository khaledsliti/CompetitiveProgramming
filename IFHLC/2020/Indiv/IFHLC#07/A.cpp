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

int main()
{
  int n, dm;
  scanf("%d%d", &n, &dm);
  vector<int> d(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  for(int i = 0; i < n; i++) {
    if(d[i] <= dm) {
      printf("It hadn't snowed this early in %d years!\n", i);
      return 0;
    }
  }
  printf("It had never snowed this early!\n");
  return 0;
}
