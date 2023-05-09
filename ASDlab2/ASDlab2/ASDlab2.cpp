#include <iostream>
#include<Windows.h>
#include<stack>
using namespace std;

const int n = 100;
struct Stack
{
    int A[n];
    int count;
};
void Creation(Stack* p)
{
    p->count = 0;
}
int Full(Stack* p)
{
    if (p->count == 0) return 1;
    else if (p->count == n) return -1;
    else return 0;

}
void Add(Stack* p)
{
    int value;
    cout << "Введите элемент > "; cin >> value;
    p->A[p->count] = value;
    p->count++;

}

void Add(Stack* p, int value)
{
    p->A[p->count] = value;
    p->count++;

}

void Delete(Stack* p)
{
    p->count--;
}
int Top(Stack* p)
{
    return p->A[p->count - 1];
}
int Size(Stack* p)
{
    return p->count;
}




int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "1 - реализация стека с помощью пользовательской структуры.\n";
    cout << "2 - реализация стека с помощью стандартной библиотеки.\n";
    cout << "Введите способ реализации задачи:\n";
    int num;
    cin >> num;

    switch (num)
    {
    case 1:
    {
        Stack main;
        Creation(&main);

        cout << "Введите количество элементов (меньше 100), которые хотите добавить в символьный стек:\n";
        int size_stack;
        cin >> size_stack;
        cout << "Добавление элементов:\n";

        for (int i = 0; i < size_stack; i++) Add(&main);

        int* mass = new int[size_stack];
        int max = Top(&main) - 1, index = size_stack - 1, maxindex = size_stack - 1;
        while (!Full(&main))
        {
            if (Top(&main) > max)
            {
                max = Top(&main);
                mass[index] = Top(&main);
                Delete(&main);
                maxindex = index;
                index--;
            }
            else
            {
                mass[index] = Top(&main);
                Delete(&main);
                index--;
            }
        }

        if (size_stack / 2 > maxindex)
        {
            for (int i = maxindex; i < size_stack / 2; i++)
            {
                mass[i] = mass[i + 1];
            }
            if (size_stack % 2 == 0)
                mass[size_stack / 2 - 1] = max;
            else
                mass[size_stack / 2] = max;

        }
        else if (size_stack / 2 < maxindex)
        {
            for (int i = maxindex; i > size_stack / 2; i--)
            {
                mass[i] = mass[i - 1];
            }
            mass[size_stack / 2] = max;
        }

        for (int i = size_stack; i > 0; i--)
        {
            Add(&main, mass[i - 1]);
        }

        while (!Full(&main))
        {
            cout << Top(&main) << " ";
            Delete(&main);
        }

        break;
    }

    case 2:
    {
        stack<int> main;
        cout << "Введите количество элементов, которые хотите добавить в стек:\n";
        int size_stack;
        cin >> size_stack;
        cout << "Добавление элементов:\n";

        for (int i = 0; i < size_stack; i++)
        {
            int value;
            cout << "Введите элемент > "; cin >> value;
            main.push(value);
        };

        int* mass = new int[size_stack];
        int max = main.top() - 1, index = size_stack - 1, maxindex = size_stack - 1;
        while (!main.empty())
        {
            if (main.top() > max)
            {
                max = main.top();
                mass[index] = main.top();
                main.pop();
                maxindex = index;
                index--;
            }
            else
            {
                mass[index] = main.top();
                main.pop();
                index--;
            }
        }

        if (size_stack / 2 > maxindex)
        {
            for (int i = maxindex; i < size_stack / 2; i++)
            {
                mass[i] = mass[i + 1];
            }
            if (size_stack % 2 == 0)
                mass[size_stack / 2 - 1] = max;
            else
                mass[size_stack / 2] = max;

        }
        else if (size_stack / 2 < maxindex)
        {
            for (int i = maxindex; i > size_stack / 2; i--)
            {
                mass[i] = mass[i - 1];
            }
            mass[size_stack / 2] = max;
        }

        for (int i = size_stack; i > 0; i--)
        {
            main.push(mass[i - 1]);
        }

        while (!main.empty())
        {
            cout << main.top() << " ";
            main.pop();
        }

        break;
    }

    default:
        cout << "Ошибка!";
        break;
    }
}

