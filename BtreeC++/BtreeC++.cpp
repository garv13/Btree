// BtreeC++.cpp : btree insertion and inorder traversal
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

void print(struct node *);
struct node
{
	int val;
	node *left;
	node *right;
};

int main()
{
	node root;
	int c = 1;
	int num;
	root.val = NULL;
	while (c)
	{
		cout << "enter number";
		cin >> num;
		node *check;
		check = &root;
		node *prev= NULL;
		if (root.val == NULL)
		{
			root.val = num;
			root.right = NULL;
			root.left = NULL;
		}
		else
		{
			node *ptr = new node();
			ptr->val = num;
			ptr->left = NULL;
			ptr->right = NULL;
			while (check != NULL)
			{
				if (check->val > num)
				{
					prev = check;
					check = check->left;
				}
				else
				{
					prev = check;
					check = check->right;
				}
			}
			if (prev->val > num)
			{
				prev->left = ptr;
			}
			else
			{
				prev->right = ptr;
			}
		}	
		cout << "enter choice";
		cin >> c;
	}
	print(&root);
	_getch();
    return 0;
}
void print(struct node *lol)
{
	if (lol != NULL)
	{
		print(lol->left);
		cout << lol->val << endl;
		print(lol->right);
	}
}