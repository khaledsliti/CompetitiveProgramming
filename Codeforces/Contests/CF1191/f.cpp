#include <bits/stdc++.h>
using namespace std;

template <class T>
class avl_tree{
  struct tree_node{
    T key;
    int height;
    int size;
    tree_node *left, *right;
    tree_node(int val) : key(val){
      height = 1;
      left = right = NULL;
      size = 1;
    }
  };

  tree_node* tree;

  int get_height(tree_node* root)
  {
    return root == NULL ? 0 : root->height;
  }
  
  int get_size(tree_node* root)
  {
    return root == NULL ? 0 : root->size;
  }
  
  void update_height(tree_node* root)
  {
    if(root == NULL)
      return;
    root->height = 1 + max(get_height(root->left), get_height(root->right));
  }
  
  void update_size(tree_node* root)
  {
    if(root == NULL)
      return;
    root->size = 1 + get_size(root->left) + get_size(root->right);
  }
  
  void UpdateHeightAndSize(tree_node* root)
  {
    update_height(root);
    update_size(root);
  }
  
  tree_node* rotate_right(tree_node* root)
  {
    if(root == NULL)
      return root;
    tree_node* left_root = root->left;
    if(left_root == NULL)
      return root;
    root->left = left_root->right;
    left_root->right = root;
    UpdateHeightAndSize(root);
    UpdateHeightAndSize(left_root);
    return left_root;
  }
  
  tree_node* rotate_left(tree_node* root)
  {
    if(root == NULL)
      return root;
    tree_node* right_root = root->right;
    if(right_root == NULL)
      return root;
    root->right = right_root->left;
    right_root->left = root;
    UpdateHeightAndSize(root);
    UpdateHeightAndSize(right_root);
    return right_root;
  }
  
  int get_balance(tree_node* root)
  {
    if(root == NULL)
      return 0;
    return get_height(root->right) - get_height(root->left);
  }
  
  
  tree_node* balance_subtree(tree_node* root)
  {
    if(root == NULL)
      return root;
  
    UpdateHeightAndSize(root);
    int root_balance = get_balance(root);
  
    if(root_balance > 1 && get_balance(root->right) >= 0)// Right right case
      return rotate_left(root);
    else if(root_balance > 1){ // Right left case
      root->right = rotate_right(root->right);
      return rotate_left(root);
    }
  
    if(root_balance < -1 && get_balance(root->left) <= 0)
      return rotate_right(root);
    else if(root_balance < -1){
      root->left = rotate_left(root->left);
      return rotate_right(root);
    }
  
    return root;
  }

  tree_node* insert(tree_node* root, T key)
  {
    if(root == NULL)
      return new tree_node(key);
    if(key < root->key)
      root->left = insert(root->left, key);
    else if(root->key < key)
      root->right = insert(root->right, key);
    return balance_subtree(root);
  }
 
  tree_node* erase(tree_node* root, T key)
  {
    if(root == NULL)
      return root;
    if(key < root->key)
      root->left = erase(root->left, key);
    else if(root->key < key)
      root->right = erase(root->right, key);
    else{
      if(root->right == NULL || root->left == NULL){
        tree_node* temp = root->left ? root->left : root->right;
        if(temp == NULL){
          free(root);
          root = NULL;
        }else{
          *root = *temp;
          free(temp);
        }
      }else{
        tree_node* min_node = root->right;
        while(min_node->left != NULL)
          min_node = min_node->left;
        root->key = min_node->key;
        root->right = erase(root->right, root->key);
      }
    }
    return balance_subtree(root);
  }
  
  int rank(tree_node* root, T key)
  {
    if(root == NULL)
      return 0;
    if(root->key == key)
      return get_size(root->left);
    if(root->key < key)
      return 1 + get_size(root->left) + rank(root->right, key);
    return rank(root->left, key);
  }

  int get_kth_Element(tree_node* root, int k){
    assert(root != NULL);
    int left_size = get_size(root->left);
    if(left_size == k)
      return root->key;
    if(left_size < k)
      return get_kth_Element(root->right, k - left_size - 1);
    return get_kth_Element(root->left, k);
  }

public:
  avl_tree() : tree(NULL) {}
  void insert(T value)
  {
    tree = insert(tree, value);
  }
  void erase(T value)
  {
    tree = erase(tree, value);
  }
  int rank(T value)
  {
    return rank(tree, value);
  }
  int get_kth_Element(int k)
  {
    return get_kth_Element(tree, k);
  }
  int get_between(T x, T y)
  {
    if(y < x)
      return 0;
    return rank(tree, y + 1) - rank(tree, x);
  }
};

const int N = 2e5 + 5;
 
int n;
pair<int, int> pt[N];
 
int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d%d", &pt[i].first, &pt[i].second);
  sort(pt, pt + n, [](const pair<int, int>& a,const pair<int, int>& b){
    if(a.second == b.second)
      return a.first < b.first;
    return a.second > b.second;
  });
  avl_tree<int> avl;
  long long ans = 0;
  int sum = 0;
  for(int i = 0 ; i < n ; i++){
    vector<int> v = {0};
    int j = i;
    while(j < n && pt[j].second == pt[i].second)
      v.push_back(pt[j++].first);
    i = j - 1;
    for(int i = 1 ; i < (int)v.size(); i++)
      avl.insert(v[i]);
    for(int i = 1 ; i < (int)v.size(); i++){
      int left = avl.get_between(v[i - 1] + 1, v[i]);
      int right = avl.get_between(v[i], 1e9);
      ans += 1LL * left * right;
    }
  }
  std::cout << ans << endl;
  return 0;
}
