#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	double data = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

TreeNode* newNode(const double& item)
{
	TreeNode* temp = new TreeNode;

	temp->data = item;
	temp->left = temp->right = nullptr;

	return temp;
}

TreeNode* tree(const int& n, TreeNode* tree_)
{
	TreeNode* t;
	int nleft, nright;

	if (n == 0) { tree_ = nullptr; return tree_; }

	nleft = n / 2;
	nright = n - nleft - 1;

	t = new TreeNode;
	cout << "Введите элемент: ";
	cin >> t->data;

	t->left = tree(nleft, t->left);
	t->right = tree(nright, t->right);
	tree_ = t;

	return tree_;
}

void print(TreeNode* p, int l)
{
	if (p)
	{
		print(p->left, l + 3);

		for (int i = 0; i < l; i++)
			cout << " ";

		cout << p->data << "\n";

		print(p->right, l + 3);
	}
}

TreeNode* insert(TreeNode* node, double key) {
	if (node == nullptr)
		return newNode(key);

	if (key < node->data)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}
double x = 0;

double findMax(TreeNode* p)
{
	if (p)
	{
		findMax(p->left);
		if (p->data > x)
		{
			x = p->data;
		}

		findMax(p->right);
		if (p->data > x)
		{
			x = p->data;
		}

		return x;
	}
}

double find(TreeNode* r, double d)
{
	if (r == nullptr)
	{
		cout << "Not found\n";
		return NULL;
	}

	if (r->data == d)
		return r->data;

	if (d <= r->data)
	{
		if (r->left != NULL)
			return find(r->left, d);
		else
			return NULL;
	}
	else
	{
		if (r->right)
			return find(r->right, d);
		else
			return NULL;
	}
}

vector<double> vec;
void search(TreeNode* p)
{
	vec.push_back(p->data);

	if (p->left)
		search(p->left);
	if (p->right)
		search(p->right);
}

TreeNode* minValueNode(TreeNode* node)
{
	TreeNode* current = node;

	while (current && current->left != nullptr)
		current = current->left;

	return current;
}

TreeNode* deleteNode(TreeNode* root, double key) {

	if (root == nullptr)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == nullptr)
		{
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}

		TreeNode* temp = minValueNode(root->right);

		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}