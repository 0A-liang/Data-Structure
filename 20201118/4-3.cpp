#include <iostream>
#define N 10
using namespace std;
class Queue
{
private:
	int arr[10], front = 0, rear = 0, Tag = 0;
public:
	void Enqueue(int i)
	{
		if (front == rear && Tag == 1)
		{

		}
		else
		{
			arr[rear] = i;
			rear = (rear + 1) % N;
			if (rear == front)
				Tag = 1;
		}
	}
	int Dequeue()
	{
		if (front == rear && Tag == 0)
		{

		}
		else
		{
			front = (front + 1) % N;
			return arr[front];
			if (rear == front)
				Tag = 0;
		}

	}
	void BackEnqueue(int i)
	{
		if (front == rear && Tag == 1)
		{

		}
		else
		{
			if (front == 0)
			{
				front = 10;
			}
			front = front - 1;
			arr[front] = i;
		}
	}
	int BackDequeue()
	{
		if (front == rear && Tag == 0)
		{

		}
		else
		{
			if (rear>9)
			{
				rear = 0;
			}
			rear = rear - 1;
			return arr[rear];
		}
	}
	void PrintQueue()
	{
		for (int i = front; i != rear; i = (i + 1) % N)
		{
			cout << arr[i] << " ";
			if (i == rear)
				break;
		}
		cout << "rear:" << rear << " ";
		cout << "front:" << front;
	}
};
int main(int argc, char *argv[])
{
	Queue queue;
	int times, input;
	cin >> times;
	for (int j = 0; j < times; j++) {
		cin >> input;
		queue.Enqueue(input);
	}
	cin >> times;
	for (int j = 0; j < times; j++) {
		queue.Dequeue();
	}
	cin >> times;
	for (int j = 0; j < times; j++) {
		cin >> input;
		queue.BackEnqueue(input);
	}
	cin >> times;
	for (int j = 0; j < times; j++) {
		queue.BackDequeue();
	}
	queue.PrintQueue();
}
