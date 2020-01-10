#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

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

template <typename T>
class treap{
  struct node{
    T val;
    int prior, size, freq;
    node *l, *r;
  };
  typedef node* pnode;
  pnode root = nullptr;
  int sz(pnode t) { return !t ? 0 : t->size; }
  void update_size(pnode t){ if(t) t->size = sz(t->l) + t->freq + sz(t->r); }
  pnode init(const T val)
  {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior = rand();
    ret->size = 1;
    ret->freq = 1;
    ret->val = val;
    ret->l = ret->r = nullptr;
    return ret;
  }
  void split(pnode t, pnode &l, pnode &r, const T key)
  {
    if(!t) l = r = nullptr;
    else if(key < t->val) split(t->l, l, t->l, key), r = t;
    else split(t->r, t->r, r, key), l = t;
    update_size(t);
  }
  void merge(pnode &t, pnode l, pnode r)
  {
    if(!l || !r) t = (l ? l : r);
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update_size(t);
  }
  void insert(pnode &t, pnode it)
  {
    if(!t) t = it;
    else if(it->prior > t->prior) split(t, it->l, it->r, it->val), t = it;
    else if(it->val < t->val) insert(t->l, it);
    else insert(t->r, it);
    update_size(t);
  }
  void erase(pnode &t, T key, bool erase_all)
  {
    if(!t) return;
    else if(t->val == key){
      if(!--t->freq || erase_all) { pnode temp=t; merge(t, t->l, t->r); free(temp); }
    }else erase(t->val < key ? t->r : t->l, key, erase_all);
    update_size(t);
  }
  pnode find(pnode t, T key)
  {
    if(!t || t->val == key) return t;
    return find(key < t->val ? t->l : t->r, key);
  }
  T find_by_order(const pnode t, int order)
  {
    assert(order < sz(t));
    int left_tree_size = sz(t->l);
    if(order < left_tree_size) return find_by_order(t->l, order);
    else if(order < left_tree_size + t->freq) return t->val;
    else return find_by_order(t->r, order - left_tree_size - t->freq);
  }
  int rank(pnode t, T key){
    if(!t) return 0;
    if(t->val == key) return sz(t->l);
    else if(key < t->val) return rank(t->l, key);
    else return sz(t->l) + t->freq + rank(t->r, key);
  }
  void get_keys(pnode t, vector<T>& keys)
  {
    if(!t) return;
    get_keys(t->l, keys);
    keys.push_back(t->val);
    get_keys(t->r, keys);
  }
public:
  void insert(T key, bool increase_freq = false){
    pnode cur_node = find(root, key);
    if(increase_freq && cur_node) cur_node->freq++;
    else if(!cur_node) insert(root, init(key));
  }
  void erase(T key, bool erase_all = true){
    erase(root, key, erase_all);
  }
  T find_by_order(int order){
    return find_by_order(root, order);
  }
  int rank(T key){
    return rank(root, key);
  }
  vector<T> get_keys()
  {
    vector<T> keys;
    get_keys(root, keys);
    return keys;
  }
  int size()
  {
    return sz(root);
  }
};


#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  IO::init();
  int n;
  IO::read_int(n);
  treap<int> tr;
  while(n--){
    char c; IO::read_char(c);
    int x; IO::read_int(x);
    if(c == 'I') tr.insert(x);
    else if(c == 'D') tr.erase(x);
    else if(c == 'K') x <= tr.size() ? IO::write_int(tr.find_by_order(--x), '\n') : IO::write_string("invalid", '\n');
    else if(c == 'C') IO::write_int(tr.rank(x), '\n');
  }
  return 0;
}
