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
	int Delete()
	{
		arr[1] = arr[tail - 1];//覆蓋第一個節點
		arr[tail-1] = 0;//最後一個節點刪除
		tail--;
		int reverse;
		int count = 1;
		while (count < tail)
		{
			if (arr[count] < arr[count * 2] && arr[count * 2]>arr[(count * 2) + 1])
			{
				reverse = arr[count];
				arr[count] = arr[count * 2];
				arr[count * 2] = reverse;
				count *= 2;
				//Insert(arr[tail /2]);
			}
			else if (arr[count] < arr[(count * 2) + 1] && arr[(count * 2) + 1]>arr[count * 2])
			{
				reverse = arr[count];
				arr[count] = arr[(count * 2) + 1];
				arr[(count * 2) + 1] = reverse;
				count = (count * 2) + 1;
				//Insert(arr[(tail -1) / 2]);
			}
			else
			{
				break;
			}
		}
		return 0;
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
	for (cin >> times; times > 0; times--) { cin >> input; tree1.Insert(input); }
	for (cin >> times; times > 0; times--) { tree1.Delete(); }
	tree1.Print();
}
