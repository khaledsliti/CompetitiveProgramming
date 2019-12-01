#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", 3 * (min(b, c / 2) + min(a, (b - min(b, c / 2)) / 2)));
  }
  return 0;
}
