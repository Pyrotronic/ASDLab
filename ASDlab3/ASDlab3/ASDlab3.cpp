#include<iostream>
#include<Windows.h>

using namespace std;
const int N = 100;

struct Queue
{
	int data[N];
	int last;
};

void Creation(Queue* Q)
{
	Q->last = 0;
}

bool Full(Queue* Q)
{
	if (Q->last == 0) return true;
	else return false;
}

void Add(Queue* Q)
{
	if (Q->last == N)
	{
		cout << "\nОчередь заполнена\n\n";
		return;
	}
	int value;
	cout << "\nЗначение: ";
	cin >> value;
	Q->data[Q->last++] = value;
}

void Add(Queue* Q, int value)
{
	if (Q->last == N)
	{
		cout << "\nОчередь заполнена\n\n";
		return;
	}

	Q->data[Q->last++] = value;
}

void Delete(Queue* Q)
{
	for (int i = 0; i < Q->last && i < N; i++)
		Q->data[i] = Q->data[i + 1];
	Q->last--;
}

int Top(Queue* Q)
{
	return Q->data[0];
}

int Size(Queue* Q)
{
	return Q->last;
}

bool Comparison(Queue q1, Queue q2, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (Top(&q1) == Top(&q2))
		{
			count++;
			Delete(&q1);
			Delete(&q2);
		}
	}

	if (count == size) return 1;
	else return 0;
}

void main()
{
	setlocale(0, "rus");

	printf("Введите количество очередей, которые хотите ввести:\n");
	int quantity_queue;
	cin >> quantity_queue;

	Queue* q = new Queue [quantity_queue];

	for (int i = 0; i < quantity_queue; i++)
	{
		Creation(&q[i]);
		printf("Введите количество элементов (не более 100), которые хотите ввести %d-ую в очередь:\n", i + 1);
		int quantity_elem;
		cin >> quantity_elem;

		for (int j = 0; j < quantity_elem; j++)
		{
			printf("Введите %d-ый элемент в очередь: ", j + 1);
			int elem;
			cin >> elem;
			Add(&q[i], elem);
		}

		cout << endl;
	}

	cout << "Нужные строки:\n";

	for (int i = 1; i < quantity_queue; i++)
	{
		int count = 0;
		for (int j = 0; j < quantity_queue; j++)
		{
			if (i == j) continue;


			if (Size(&q[i]) != Size(&q[j])) continue;
			else
			{
				if (Comparison(q[i], q[j], Size(&q[i])))
					count++;
			}
		}

		if (count == 1)
		{
			int size = Size(&q[i]);
			for (int j = 0; j < size; j++)
			{
				cout << Top(&q[i]) << " ";
				Delete(&q[i]);
			}
			cout << endl;
		}
	}

}