#include <iostream>
using namespace std;
class ListNode
{
public:
	ListNode(int a) { data = a; link = 0; }
private:
	int data;
	ListNode *link;
	friend class LinkedList;
};
class LinkedList
{
private:
	ListNode *first=0;
	ListNode *last=0;
public:
	void InsertFirst(int x)
	{
		ListNode* newNode = new ListNode(x);
		newNode->link = first;
		first = newNode;
		if (last == 0)
			last = newNode;
	}
	int DeleteFirst()
	{
		if (first == last)
		{
			first->data = 0;
			return 0;
		}
		first = first->link;
		return first->data;
	}
	void InsertLast(int x)
	{
		ListNode* newNode = new ListNode(x);
		if (last == 0)
		{
			first = newNode;
			last = newNode;
			return;
		}
		last->link = newNode;
		last = newNode;
	}
	int DeleteLast()
	{
		ListNode* current = first;
		if (current== last)
		{
			last->data = 0;
			return 0;
		}
		while (current->link!= last)
		{
			current = current->link;
		}
		last = current;
		return last->data;
	}
	void Reverse()
	{
		ListNode *previous = 0,
			*current = first,
			*preceding = first->link;

		while (preceding != last->link) {
			current->link = previous;      // 把current->next轉向
			previous = current;            // previous往後挪
			current = preceding;           // current往後挪
			preceding = preceding->link;   // preceding往後挪
		}                                  // preceding更新成NULL即跳出while loop

		current->link = previous;          // 此時current位於最後一個node, 將current->next轉向
		last = first;
		first = current;
	}
	void PrintList()
	{
		ListNode* current = first;
		while (current != last->link)
		{
			if(current->data!=0)
				cout << current->data << " ";
			current = current->link;
		}
		cout << endl;
	}
};
class Stack : public LinkedList
{
private:

public:
	void Push(int x)
	{
		InsertLast(x);
	}
	int Pop()
	{
		return DeleteLast();
	}
	void PrintStack()
	{
		PrintList();
	}
};
int main(int argc, char *argv[])
{
	Stack stack;
	int times, input;
	for (cin >> times; times > 0; times--) { cin >> input; stack.Push(input); }
	for (cin >> times; times > 0; times--) stack.Pop();
	stack.PrintStack();
}
