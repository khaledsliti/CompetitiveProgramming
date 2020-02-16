#include <bits/stdc++.h>
using namespace std;

struct AVLTreeNode{
	int key;
	int height;
	int subtree_size;
	int dup;
	AVLTreeNode *left, *right;
	AVLTreeNode(int val) : key(val){
		height = 1;
		left = right = NULL;
		subtree_size = 1;
		dup = 1;
	}
};

int GetHeight(AVLTreeNode* root){
	return root == NULL ? 0 : root->height;
}

int GetSubtreeSize(AVLTreeNode* root){
	return root == NULL ? 0 : root->subtree_size;
}

void CalculateSubtreeSize(AVLTreeNode* root){
	root->subtree_size = GetSubtreeSize(root->left) + root->dup
		+ GetSubtreeSize(root->right);
}

void UpdateHeight(AVLTreeNode* root){
	if(root == NULL)
		return;
	root->height = 1 + max(GetHeight(root->left), GetHeight(root->right));
}

AVLTreeNode* RotateRight(AVLTreeNode* root){
	if(root == NULL)
		return root;
	AVLTreeNode* left_root = root->left;
	if(left_root == NULL)
		return root;
	root->left = left_root->right;
	CalculateSubtreeSize(root);
	left_root->right = root;
	CalculateSubtreeSize(left_root);
	UpdateHeight(root);
	UpdateHeight(left_root);
	return left_root;
}

AVLTreeNode* RotateLeft(AVLTreeNode* root){
	if(root == NULL)
		return root;
	AVLTreeNode* right_root = root->right;
	if(right_root == NULL)
		return root;
	root->right = right_root->left;
	CalculateSubtreeSize(root);
	right_root->left = root;
	CalculateSubtreeSize(right_root);
	UpdateHeight(root);
	UpdateHeight(right_root);
	return right_root;
}

int GetBalance(AVLTreeNode* root){
	if(root == NULL)
		return 0;
	return GetHeight(root->right) - GetHeight(root->left);
}

AVLTreeNode* Insert(AVLTreeNode* root, int value, int& result){
	if(root == NULL)
		return new AVLTreeNode(value);
	if(value < root->key)
		root->left = Insert(root->left, value, result);
	else if(value > root->key)
		root->right = Insert(root->right, value, result);
	else{
		root->dup++;
		CalculateSubtreeSize(root);
		return root;
	}
		
	root->height = 1 + max(GetHeight(root->left), GetHeight(root->right));
	int root_balance = GetBalance(root);
	// Right right case
	if(root_balance > 1 && value > root->key)
		return RotateLeft(root);
	// Left left case
	if(root_balance < -1 && value < root->key)
		return RotateRight(root);
	// Right left case
	if(root_balance > 1){
		root->right = RotateRight(root->right);
		return RotateLeft(root);
	}
	// Left right case
	if(root_balance < -1){
		root->left = RotateLeft(root->left);
		return RotateRight(root);
	}
	CalculateSubtreeSize(root);
	
	return root;
}

int Rank(AVLTreeNode* root, int key){
	if(root == NULL)
		return 0;
	if(key <= root->key)
		return Rank(root->left, key);
	return root->dup + GetSubtreeSize(root->left) + Rank(root->right, key);
}

void Print(AVLTreeNode* root){
	if(root == NULL)
		return;
	cout << root->key << " " << root->dup << " " << root->subtree_size << 
	endl;
	Print(root->left);
	Print(root->right);
}

class Solution{
public:
	vector<int> countSmaller(vector<int> nums){
		AVLTreeNode* avl_tree = NULL;
		int nums_size = (int) nums.size();
		vector<int> result;
		for(int i = nums_size - 1 ; i >= 0 ; i--){
			int cur = nums[i];
			int ans = 0;
			avl_tree = Insert(avl_tree, cur, ans);
			result.push_back(Rank(avl_tree, cur));
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main(){
	Solution solution = Solution();
	vector<int> input = { 5, 5, 4, 3, 2, 2, 1, 0 };
	vector<int> result = solution.countSmaller(input);
	for(int i = 0 ; i < (int)result.size() ; i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}