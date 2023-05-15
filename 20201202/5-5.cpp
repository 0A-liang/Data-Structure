#include <iostream>
using namespace std;
class ListNode
{
public:
	ListNode(int a) { data = a; link = 0; }
private:
	int data;
	ListNode* link;
	friend class CircularList;
};
class CircularList
{
public:
	//CircularList() {};
	void InsertFirst(int x);
	void InsertLast(int x);
	int DeleteFirst();
	int DeleteLast();
	void PrintList();
private:
	ListNode* last = 0;
};
void CircularList::InsertFirst(int x)
{
	ListNode* newNode = new ListNode(x); // 配置新的記憶體
	if (last == 0)
	{
		last = newNode;
		newNode->link = last;
		return;
	}
	newNode->link = last->link;
	last->link = newNode;
}
void CircularList::InsertLast(int x)
{
	ListNode* newNode = new ListNode(x);   // 配置新的記憶體
	newNode->link = last->link;
	last->link = newNode;
	last = newNode;
}
int CircularList::DeleteFirst()
{
	if (last->link == last)
	{
		last->data = 0;
	}
	else
	{
		last->link = last->link->link;
		return last->data;
	}
}
int CircularList::DeleteLast()
{
	ListNode *current = last->link;
	while (current->link != last)
	{
		current = current->link;
	}
	current->link = last->link;
	last = current;
	return last->data;
	//delete current;
}
void CircularList::PrintList()
{
	ListNode* current = last->link;             // 用pointer *current在list中移動
	while (current != last)
	{
		if (current->data != 0)
		{
			cout << current->data << " ";
		}
		//cout << current->data<<" ";
		current = current->link;
	}
	if (current->data!=0)
	{
		cout << last->data;
	}
	//cout << last->data;
	/*int x = 0;
	while (x != -1)//警示值迴圈         // Traversal
	{
		cout << current->data << " ";
		if (current == last)
			x = -1;
		current = current->link;
	}*/
	//cout << endl;
}
int main(int argc, char* argv[])
{
	CircularList list;
	int times, input;
	for (cin >> times; times > 0; times--) { cin >> input; list.InsertFirst(input); }
	for (cin >> times; times > 0; times--) list.DeleteFirst();
	for (cin >> times; times > 0; times--) { cin >> input; list.InsertLast(input); }
	for (cin >> times; times > 0; times--) list.DeleteLast();
	list.PrintList();
}
