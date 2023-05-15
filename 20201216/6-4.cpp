#include <iostream>
using namespace std;
class MaxHeap
{
private:
	int arr[100] = {};
	int tail = 1;
public:
	void Insert(int x)
	{
		//tail++;	
		if (tail > 0)
		{
			arr[tail++] = x;
		}
		int reverse;
		int count = 2;
		while (count < tail)
		{
			if (arr[count] > arr[count / 2] && count % 2 == 0)
			{
				reverse = arr[count];
				arr[count] = arr[count / 2];
				arr[count / 2] = reverse;
				count = 2;
				continue;
				//Insert(arr[tail /2]);
			}
			else if (arr[count] > arr[(count - 1) / 2] && count % 2 != 0)
			{
				reverse = arr[count];
				arr[count] = arr[(count - 1) / 2];
				arr[(count - 1) / 2] = reverse;
				count = 2;
				continue;
				//Insert(arr[(tail -1) / 2]);
			}
			count++;
		}
	}
	void Print()
	{
		for (int i = 1; i < tail; i++)
		{
			cout << arr[i] << " ";
		}
	}
};
int main(int argc, char *argv[])
{   
    MaxHeap tree1;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; tree1.Insert(input);}
	tree1.Print();
}
