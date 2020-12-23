#include <iostream>
using namespace std;
class Queue
{
private:
	int arr[10], rear = -1, front = -1;
public:
	void Enqueue(int i)
	{
		arr[++rear] = i;
	}
	int Dequeue()
	{
		return arr[++front];
	}
	void PrintQueue()
	{
		for (int i = front+1; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
	}
};
int main(int argc, char *argv[])
{
	Queue queue;
	int times, input;
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> input;
		queue.Enqueue(input);
	}
	cin >> times;
	for (int i = 0; i < times; i++) {
		queue.Dequeue();
	}
	queue.PrintQueue();
}
