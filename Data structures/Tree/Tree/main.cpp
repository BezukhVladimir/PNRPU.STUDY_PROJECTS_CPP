/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
*
* https://bezukh.wixsite.com/blog
* https://github.com/BezukhVladimir
*
* © Developed by Bezukh Vladimir. All right reserved.
*/

#include "tree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	TreeNode* root;
	TreeNode* addp;
	TreeNode* newtree;
	
	int n;
	cout << "Введите количество значений: "; cin >> n;

	root = new TreeNode;
	root = tree(n, root);

	print(root, n);
	cout << "\n\n";
	cout << "Максимальный элемент - " << findMax(root) << endl;

	search(root);
	newtree = nullptr;
	for (int i = 0; i < vec.size(); ++i)
		newtree = insert(newtree, vec[i]);

	cout << "\n\n";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << endl;
	print(newtree, n);

	double b;
	cout << "Введите элемент для удаления: "; cin >> b;
	deleteNode(newtree, b);

	cout << "\n\n";
	print(newtree, n);

	double a;
	cout << "Введите элемент для поиска: "; cin >> a;

	if (find(newtree, a) == 0)
		cout << "Элемент не найден" << endl;
	else
		cout << "Элемент найден - " << find(newtree, a) << endl;
}