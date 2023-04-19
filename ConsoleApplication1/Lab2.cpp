// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


#include <iostream>
#include "Enumerator.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Functions.h"
#include "SequenceTests.h"
#include "ArraySequenceTests.h"
#include "ListSequenceTests.h"

using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace Lab2;

namespace Lab2
{
    void printActionResult(System::String^ actionName, int n)
    {
        Console::Write(actionName);
        Console::WriteLine(L" = {0}", n);
    }

    template<class T>
    void printSequence(System::String^ sequenceName, Sequence<T>^ sequence)
    {
        Console::WriteLine(sequenceName);
        for each (T^ n in sequence)
        {
            Console::Write("{0} ", n);
        }
        Console::WriteLine("");
    }

    template<class T>
    void printListSequence(System::String^ sequenceName, ListSequence<T>^ sequence)
    {
        Console::WriteLine(sequenceName);
        Item<int>^ currentItem = sequence->First;
        while (currentItem != nullptr)
        {
            Console::Write("{0} ", currentItem->value);
            currentItem = currentItem->next;
        }
        Console::WriteLine("");
    }
}

template<class T>
void processSequenceOperations(char* operation, Sequence<T>^ sequence)
{
    if (strcmp(operation, "sum") == 0)
    {
        T result = sequence->Reduce(sum);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "min") == 0)
    {
        T result = sequence->Reduce(min);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "max") == 0)
    {
        T result = sequence->Reduce(max);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "first") == 0)
    {
        T result = sequence->Reduce(first);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "last") == 0)
    {
        T result = sequence->Reduce(last);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "firstordefault") == 0)
    {
        T result = sequence->Reduce(firstOrDefault);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "lastordefault") == 0)
    {
        T result = sequence->Reduce(lastOrDefault);
        printActionResult("Result: ", result);
    }

    if (strcmp(operation, "increment") == 0)
    {
        sequence->Map(increment);
        printSequence("Result:", sequence);
    }

    if (strcmp(operation, "decrement") == 0)
    {
        sequence->Map(decrement);
        printSequence("Result:", sequence);
    }
}

void processSequence(Sequence<int>^ sequence)
{
    char operation[32];

    while (true)
    {
        printf_s("Available operations: sum, max, min, first, last, firstordefault, lastordefault, increment, decrement, exit\n");
        printf_s("Enter operation: ");
        scanf_s("%s", operation, sizeof(operation));

        processSequenceOperations(operation, sequence);

        if (strcmp(operation, "exit") == 0)
        {
            return;
        }
    }
}

/*void processArraySequenceFloat(ArraySequence<float>^ arraySequence)
{
    char operation[32];

    while (true)
    {
        printf_s("Available operations: sum, max, min, first, last, firstordefault, lastordefault, add, remove, increment, decrement, exit\n");
        printf_s("Enter operation: ");
        scanf_s("%s", operation, sizeof(operation));

        if (strcmp(operation, "add") == 0)
        {
            printf_s("Enter value: ");
            int value;
            scanf_s("%d", &value);
            arraySequence->Add(value);
            printIntSequence("Result:", arraySequence);
        }

        if (strcmp(operation, "remove") == 0)
        {
            printf_s("Enter index: ");
            int index;
            scanf_s("%d", &index);
            arraySequence->Remove(index);
            printIntSequence("Result:", arraySequence);
        }

        processSequenceOperations(operation, arraySequence);

        if (strcmp(operation, "exit") == 0)
        {
            return;
        }
    }
}*/

void processArraySequence(ArraySequence<int>^ arraySequence)
{
    char operation[32];

    while (true)
    {
        printf_s("Available operations: sum, max, min, first, last, firstordefault, lastordefault, add, remove, increment, decrement, exit\n");
        printf_s("Enter operation: ");
        scanf_s("%s", operation, sizeof(operation));

        if (strcmp(operation, "add") == 0)
        {
            printf_s("Enter value: ");
            int value;
            scanf_s("%d", &value);
            arraySequence->Add(value);
            printSequence("Result:", arraySequence);
        }

        if (strcmp(operation, "remove") == 0)
        {
            printf_s("Enter index: ");
            int index;
            scanf_s("%d", &index);
            arraySequence->Remove(index);
            printSequence("Result:", arraySequence);
        }

        processSequenceOperations(operation, arraySequence);

        if (strcmp(operation, "exit") == 0)
        {
            return;
        }
    }
}

template<class T>
void processListSequence(ListSequence<T>^ listSequence)
{
    char operation[32];

    while (true)
    {
        printf_s("Available operations: append, prepend, exit\n");
        printf_s("Enter operation: ");
        scanf_s("%s", operation, sizeof(operation));

        if (strcmp(operation, "append") == 0)
        {
            printf_s("Enter value: ");
            int value;
            scanf_s("%d", &value);
            listSequence->Append(value);
            printListSequence("Result: ", listSequence);
        }

        if (strcmp(operation, "prepend") == 0)
        {
            printf_s("Enter value: ");
            int value;
            scanf_s("%d", &value);
            listSequence->Prepend(value);
            printListSequence("Result: ", listSequence);
        }

        if (strcmp(operation, "remove") == 0)
        {
            printf_s("Enter index: ");
            int index;
            scanf_s("%d", &index);
            listSequence->Prepend(index);
            printListSequence("Result: ", listSequence);
        }

        if (strcmp(operation, "exit") == 0)
        {
            return;
        }
    }
}

int Run()
{
    std::cout << "Lab 2\n";
    printf_s("Enter number of elements: ");
    int n;
    scanf_s("%d", &n);

    char elementType[32];
    printf_s("Enter element type (int): ");
    scanf_s("%s", elementType, sizeof(elementType));

    array<int>^ numbers = gcnew array<int>(n);
    for (int i = 0; i < n; i++)
    {
        printf_s("Enter element %d: ", i + 1);
        scanf_s("%d", &numbers[i]);
    }

    char sequenceType[32];
    printf_s("Enter sequence type (sequence, dynamicarray, linkedlist): ");
    scanf_s("%s", sequenceType, sizeof(sequenceType));

    if (strcmp(sequenceType, "sequence") == 0)
    {
        Sequence<int>^ sequence = gcnew Sequence<int>(numbers, n);
        processSequence(sequence);
    }

    if (strcmp(sequenceType, "dynamicarray") == 0)
    {
        ArraySequence<int>^ arraySequence = gcnew ArraySequence<int>(numbers, n);
        processArraySequence(arraySequence);
    }

    if (strcmp(sequenceType, "linkedlist") == 0)
    {
        ListSequence<int>^ ls = gcnew ListSequence<int>(numbers, n);
        processListSequence(ls);
    }
    
    return 0;
};

void RunTests()
{
    RunSequenceTests();
    RunArraySequenceTests();
    RunListSequenceTests();
}

//right click project name in the solution explorer "Lab2" / Properties / Configuration properties / Debugging / Command Arguments
int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "tests") == 0)
    {
        RunTests();
    }
    else
    {
        Run();
    }
}