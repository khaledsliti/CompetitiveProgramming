#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  const int N = 20;
  vector<int> collection(N, 1);
  adjacent_difference(begin(collection), end(collection) - 1, begin(collection) + 1, plus<int>());
  // adjacent_difference(begin(collection), end(collection) - 1, begin(collection) + 1, plus<int>());
  for_each(all(collection), [](const auto& x){ cout << x << endl; });
  return 0;
}
