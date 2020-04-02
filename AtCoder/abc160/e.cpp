// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int x, y, a, b, c;
int A[N], B[N], C[N];
long long opt[N];
long long best = 0;

int main()
{
  cin >> x >> y >> a >> b >> c;
  for(int i = 0 ; i < a ; i++)
    cin >> A[i];
  for(int i = 0 ; i < b ; i++)
    cin >> B[i];
  for(int i = 0 ; i < c ; i++)
    cin >> C[i];
  sort(A, A + a); reverse(A, A + a);
  sort(B, B + b); reverse(B, B + b);
  sort(C, C + c); reverse(C, C + c);
  priority_queue<int, vector<int>, greater<int>> pq;
  long long sum = 0;
  for(int i = 0 ; i < y ; i++)
    pq.push(B[i]), sum += B[i];
  opt[c] = sum;
  for(int i = c - 1 ; i >= 0 ; i--) {
    sum += C[i];
    pq.push(C[i]);
    sum -= pq.top();
    pq.pop();
    opt[i] = sum;
  }
  while(!pq.empty()) pq.pop();
  sum = 0;
  for(int i = 0 ; i < x ; i++) {
    sum += A[i];
    pq.push(A[i]);
  }
  long long best = sum + opt[0];
  for(int i = 0 ; i < min(x, c) ; i++) {
    sum += C[i];
    pq.push(C[i]);
    sum -= pq.top();
    pq.pop();
    best = max(best, sum + opt[i + 1]);
  }
  cout << best << endl;
  return 0;
}
