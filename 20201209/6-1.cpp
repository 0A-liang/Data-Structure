#include <iostream>
using namespace std;
class BinTree
{
private:
    int arr[100];
    int tail;
public:
    void BuildTree(int data[], int n)
    {
        for (int i = 0; i < 100; i++)
        {
            arr[i] = 0;
        }
        arr[1] = data[0];
        int count=n;
        for (int i = 1; i < n; i++)
        {
            int node = 1;
            while (arr[node] != 0)
            {
                if (data[i] > arr[node])
                {
                    node = node * 2 + 1;
                }
                else
                {
                    node = node * 2;
                }
                if (count<node)
                {
                    count = node;
                    tail = count;
                }
            }
            arr[node] = data[i];
        }
    }
    void Print()
    {
        for (int i = 1;i<=tail; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main(int argc, char* argv[])
{
    BinTree tree1;
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Print();
}
