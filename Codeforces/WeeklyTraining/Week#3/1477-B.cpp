#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct Node {
	int sum;
	int lazy;
};

int n, q;
string source, target;
pair<int, int> query[N];
Node st[N << 2];

inline int left(int cur) { return 2 * cur + 1; }
inline int right(int cur) { return 2 * cur + 2; }
inline int getMid(int s, int e) { return (s + e) / 2; }


Node merge(const Node& a, const Node& b) {
	return { a.sum + b.sum, -1 };
}

void build(int cur, int s, int e) {
	if(s == e) {
		st[cur] = { target[s] == '1', -1 };
		return;
	}
	int mid = getMid(s, e);
	build(left(cur), s, mid);
	build(right(cur), mid + 1, e);
	st[cur] = merge(st[left(cur)], st[right(cur)]);
}

void push_down(int cur, int s, int e) {
	if(st[cur].lazy != -1) {
		st[cur].sum = (e - s + 1) * st[cur].lazy;
		if (s != e) {
			st[left(cur)].lazy = st[right(cur)].lazy = st[cur].lazy;
		}
		st[cur].lazy = -1;
	}
}

void update(int cur, int s, int e, int i, int j, int new_value) {
	push_down(cur, s, e);
	if(s > j || e < i) return;
	if(s >= i && e <= j) {
		st[cur].lazy = new_value;
    push_down(cur, s, e);
		return;
	}
	int mid = getMid(s, e);
	int l = left(cur), r = right(cur);
	update(l, s, mid, i, j, new_value);
	update(r, mid + 1, e, i, j, new_value);
	st[cur] = merge(st[l], st[r]);
}

Node get(int cur, int s, int e, int i, int j) {
	push_down(cur, s, e);
	if(s > j || e < i) return { 0, -1 };
	if(s >= i && e <= j) return st[cur];
	int l = left(cur), r = right(cur), mid = getMid(s, e);
	return merge(get(l, s, mid, i, j), get(r, mid + 1, e, i, j));
}

void print(int cur, int s, int e) {
  printf("[%d, %d] %d (%d)\n", s + 1, e + 1, st[cur].sum, st[cur].lazy);
  if(s != e) {
    int l = left(cur), r = right(cur), mid = getMid(s, e);
    print(l, s, mid);
    print(r, mid + 1, e);
  }
}

bool update_queries() {
	for(int i = q - 1; i >= 0; i--) {
		int l = query[i].first, r = query[i].second;
		int ones = get(0, 0, n - 1, l, r).sum;
		int len = r - l + 1;
		int zeros = len - ones;
		if(ones * 2 < len) {
			update(0, 0, n - 1, l, r, 0);
		} else if(zeros * 2 < len) {
			update(0, 0, n - 1, l, r, 1);
		} else {
			return false;
		}
    print(0, 0, n - 1);
    cout << endl;
	}
	return true;
}

bool check_with_source() {
	for(int i = 0; i < n; i++) {
		int expected = get(0, 0, n - 1, i, i).sum;
		if(expected != source[i] - '0') return false;
	}
	return true;
}

void solve() {
	cin >> n >> q >> source >> target;
	build(0, 0, n - 1);
	for(int i = 0; i < q; i++) {
		cin >> query[i].first >> query[i].second;
		query[i].first--;
		query[i].second--;
	}
	if(!update_queries() || !check_with_source()) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tests;
	cin >> tests;
	while(tests--)
		solve();
	return 0;
}
