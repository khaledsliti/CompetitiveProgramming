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

string val[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

string dic[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

int calc(int n) {
  if(n == 1000) return string("onethousand").size();
  int ans = 0;
  int r = n % 100;
  if(r > 0) {
    if(r < 20) ans += sz(val[r]);
    else ans += sz(dic[r / 10]) + (r % 10 ? sz(val[r % 10]) : 0);
  }
  if(n >= 100) ans += sz(val[n / 100]) + string("hundred").size();
  if(n >= 100 && r > 0) ans += 3; // and
  return ans;
}

int main()
{
  int tot = 0;
  for(int i = 1; i <= 1000; i++)
    tot += calc(i);
  cout << tot << endl;
  return 0;
}
