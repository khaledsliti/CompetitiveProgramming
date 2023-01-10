// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

namespace IO {
  const int BUFFER_SIZE = 1 << 15;
  char input_buffer[BUFFER_SIZE];
  int input_pos = 0, input_len = 0;
  
  char output_buffer[BUFFER_SIZE];
  int output_pos = 0;
  
  uint8_t lookup[100];
  
  void _update_input_buffer() {
    input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
    input_pos = 0;
  }
  
  inline char next_char(bool advance = true) {
    if (input_pos >= input_len)
      _update_input_buffer();
    return input_buffer[advance ? input_pos++ : input_pos];
  }
  
  inline bool isspace(char c) {
    return (unsigned char) (c - '\t') < 5 || c == ' ';
  }
  
  template<typename T>
  inline void read_int(T &number) {
    while (isspace(next_char(false)))
      next_char();
    bool negative = next_char(false) == '-';
    if (negative)
      next_char();
    number = 0;
    while (isdigit(next_char(false)))
      number = 10 * number + (next_char() - '0');
    if (negative)
      number = -number;
  }

  inline void read_char(char& ch, bool ignore_space = true) {
    if(ignore_space)
      while (isspace(next_char(false)))
        next_char();
    ch = next_char();
  }
  
  void _flush_output() {
    fwrite(output_buffer, sizeof(char), output_pos, stdout);
    output_pos = 0;
  }
  
  inline void write_char(char c) {
    if (output_pos == BUFFER_SIZE)
      _flush_output();
    output_buffer[output_pos++] = c;
  }
  
  template<typename T>
  inline void write_int(T number, char after = 0) {
    if (number < 0) {
      write_char('-');
      number = -number;
    }
    static char number_buffer[100];
    int length = 0;
    do {
      if (number < 10) {
        number_buffer[length++] = number + '0';
        number = 0;
      } else {
        uint8_t lookup_value = lookup[number % 100];
        number /= 100;
        number_buffer[length++] = (lookup_value & 15) + '0';
        number_buffer[length++] = (lookup_value >> 4) + '0';
      }
    } while (number != 0);
    for (int i = length - 1; i >= 0; i--)
      write_char(number_buffer[i]);
    if (after)
      write_char(after);
  }

  inline void write_string(string& str, char after = 0) {
    for(auto& c : str)
      write_char(c);
    if (after)
      write_char(after);
  }

  inline void write_string(string&& str, char after = 0) {
    for(auto& c : str)
      write_char(c);
    if (after)
      write_char(after);
  }
  
  void init() {
    // Make sure _flush_output() is called at the end of the program.
    bool exit_success = atexit(_flush_output) == 0;
    assert(exit_success);
    for (int i = 0; i < 100; i++)
      lookup[i] = (i / 10 << 4) + i % 10;
  }
}

const int N = 200003;
const int L = 19;
const int V = 1000003;
const int Mod = 1e9 + 7;

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow-1);
  int seg = (x < hpow) ? (
    (y < hpow) ? 0 : 3
  ) : (
    (y < hpow) ? 1 : 2
  );
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int64_t subSquareSize = int64_t(1) << (2*pow - 2);
  int64_t ans = seg * subSquareSize;
  int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}

struct query {
  int u, v, lca;
  int l, r, idx;
  int64_t ord;

  void calc() {
    ord = hilbertOrder(l, r, 21, 0);
  }
};

inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}

int n, q;
int inv[V], smf[V];
vector<pair<int, int>> fact[V];
vector<int> g[N];
int val[N];
int anc[N][L], lev[N];
int cur_id, id[N], st[N], en[N];
query qr[N];
int ans[N];
int cur_ans;
bool in[N];
int cnt[V];

void dfs1(int u, int p) {
  st[u] = cur_id;
  id[cur_id++] = u;
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs1(v, u);
    }
  }
  en[u] = cur_id;
  id[cur_id++] = u;
}

int get_lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a,b);
  int lg = 0;
  for(; (1 << lg) <= lev[a] ; lg++);
  lg--;
  for(int i = lg ; i >= 0 ; i--)
    if(lev[a] - (1 << i) >= lev[b])
      a = anc[a][i];
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(anc[a][i] != anc[b][i])
      a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

void update(int idx) {
  for(int i = 0 ; i < sz(fact[val[idx]]) ; i++) {
    int p = fact[val[idx]][i].first;
    int c = fact[val[idx]][i].second;
    cur_ans = (1LL * cur_ans * inv[1 + cnt[p]]) % Mod;
    if(in[idx]) cnt[p] -= c;
    else cnt[p] += c;
    cur_ans = (1LL * cur_ans * (1 + cnt[p])) % Mod;
  }
  in[idx] ^= 1;
}

void compute() {
  int cur_l = 0, cur_r = 0;
  cur_ans = 1;
  for(int i = 0 ; i < q ; i++) {
    int l = qr[i].l;
    int r = qr[i].r;
    while(cur_l < l) update(id[cur_l++]);
    while(cur_l > l) update(id[--cur_l]);
    while(cur_r < r) update(id[cur_r++]);
    while(cur_r > r) update(id[--cur_r]);
    if(qr[i].lca != qr[i].u) update(qr[i].lca);
    ans[qr[i].idx] = cur_ans;
    if(qr[i].lca != qr[i].u) update(qr[i].lca);
  }
  while(cur_l < cur_r)
    update(id[cur_l++]);
}

void solve() {
  IO::read_int(n);
  for(int i = 0 ; i < n ; i++)
    g[i].clear();
  for(int i = 0 ; i < n - 1 ; i ++) {
    int a, b;
    IO::read_int(a), IO::read_int(b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  for(int i = 0 ; i < n ; i++)
    IO::read_int(val[i]);
  cur_id = 0;
  dfs1(0, -1);
  IO::read_int(q);
  for(int i = 0 ; i < q ; i++) {
    int u, v;
    IO::read_int(u);
    IO::read_int(v);
    --u, --v;
    int lca = get_lca(u, v);
    if(st[u] > st[v]) swap(u, v);
    qr[i].idx = i;
    qr[i].u = u;
    qr[i].v = v;
    qr[i].lca = lca;
    if(u == v) qr[i].l = st[u], qr[i].r = st[u] + 1;
    if(lca == u) qr[i].l = st[u], qr[i].r = st[v] + 1;
    else qr[i].l = en[u], qr[i].r = st[v] + 1;
    qr[i].calc();
  }
  sort(qr, qr + q);
  compute();
  for(int i = 0 ; i < q ; i++)
    IO::write_int(ans[i], '\n');
}

void init() {
  inv[1] = 1;
  for(int i = 2 ; i < V ; i++)
    inv[i] = Mod - Mod / i * 1LL * inv[Mod % i] % Mod;
  for(int i = 1 ; i < V ; i++)
    smf[i] = i;
  for(int i = 2 ; i * i < V ; i++)
    if(smf[i] == i)
      for(int j = i * i ;  j < V ; j += i)
        smf[j] = min(smf[j], i);
  for(int i = 2 ; i < V ; i++) {
    int p = smf[i];
    for(auto f : fact[i / p])
      fact[i].push_back(f);
    if(fact[i].size() && fact[i].back().first == p)
      fact[i].back().second++;
    else
      fact[i].push_back({p, 1});
  }
}

int main()
{
  IO::init();
  init();
  int t;
  IO::read_int(t);
  while(t--) {
    solve();
  }
  return 0;
}