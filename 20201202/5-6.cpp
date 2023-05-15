#include <iostream>
using namespace std;
class ListNode
{
public:
	ListNode(int a, int b) { coef = a; exp = b; link = 0; }
private:
	int coef;
	int exp;
	ListNode *link;
	friend class PolyList;
};
class PolyList
{
public:
	void InsertLast(int, int);
	void PrintList();
	void Add(PolyList&);
private:
	ListNode *first = 0;
	ListNode *last = 0;
};
void PolyList::InsertLast(int x, int y)
{
	ListNode *newNode = new ListNode(x, y);
	if (last == 0)
		first = newNode;
	else
		last->link = newNode;
	last = newNode;
}
void PolyList::Add(PolyList& b)
{
	ListNode *pa = 0;
	ListNode *pb = 0;
	ListNode *na = first;
	ListNode *nb = b.first;
	while (na != last->link && nb != last->link)
	{
		if (na->exp < nb->exp)
		{
			ListNode *newNode = new ListNode(nb->coef, nb->exp);
			if (pa == 0)
				first = newNode;
			else
				pa->link = newNode;
			newNode->link = na;
			pa = newNode;
			pb = nb;
			nb = nb->link;
		}
		else if (na->exp == nb->exp)
		{
			na->coef += nb->coef;
			if (na->coef == 0)
			{
				if (pa == last->link)
				{
					first = na->link;
					pa = na;
					na = na->link;
					pa = 0;
				}
				else
				{
					pa->link = na->link;
					na = pa;
				}
			}
			if (pa != last->link)
			{
				pa = na;
				na = na->link;
			}
			pb = nb;
			nb = nb->link;
		}
		else if (na->exp > nb->exp)
		{
			pa = na;
			na = na->link;
		}
	}
	while (nb != last->link)
	{
		InsertLast(nb->coef, nb->exp);
		nb = nb->link;
	}
}
void PolyList::PrintList()
{
	ListNode *current = first;
	while (current != last->link)
	{
		cout << current->coef << "x^" << current->exp << " ";
		current = current->link;
	}
}
int main(int argc, char *argv[])
{
	PolyList A, B;
	int times, input, input2;
	for (cin >> times, times /= 2; times > 0; times--) { cin >> input >> input2; A.InsertLast(input, input2); }
	for (cin >> times, times /= 2; times > 0; times--) { cin >> input >> input2; B.InsertLast(input, input2); }
	A.Add(B);
	A.PrintList();
}
