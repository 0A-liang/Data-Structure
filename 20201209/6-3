#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

class TreeNode
{
public:
	friend class BinTree;
	TreeNode(int a) {data = a; leftChild = rightChild = 0;};
private:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;
};
class BinTree
{
public:
	TreeNode *root=0;
	void Inorder(TreeNode* current)
	{
		if(current!=0)
		{
			Inorder(current->leftChild);
			cout<<current->data<<" ";
			Inorder(current->rightChild);
		}
	}
	void Preorder(TreeNode* current)
	{
		if(current!=0)
		{	
			cout<<current->data<<" ";
			Preorder(current->leftChild);
			Preorder(current->rightChild);
		}
	}
	void Postorder(TreeNode* current)
	{
		if(current!=0)
		{	
			Postorder(current->leftChild);
			Postorder(current->rightChild);
			cout<<current->data<<" ";
		}
	}
	void BuildTree(int data[],int n)
	{
		TreeNode* newNode = new TreeNode(data[0]);
		root = newNode;
		for (int i = 1; i < n; i++)
		{	
			TreeNode* current = root;
			while (true)
			{	
				if (data[i]>(current->data))
				{
					TreeNode* newNode = new TreeNode(data[i]);   // 配置新的記憶體
					if(current->rightChild==0)
					{
						current->rightChild = newNode;
						break;	
					}
					current=current->rightChild;
				}
				else
				{
					TreeNode* newNode = new TreeNode(data[i]);   // 配置新的記憶體
					if(current->leftChild==0)
					{	
						current->leftChild = newNode;
						break;
					}
					current=current->leftChild;
				}
			}
		}
	}
};
int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Inorder(tree1.root);
    cout<<endl;
    tree1.Preorder(tree1.root);
    cout<<endl;
    tree1.Postorder(tree1.root);
}
