using namespace Lab;

namespace Lab
{
    template <class T>
    void OrderPriorityQueue(PriorityQueue<T>^ node, void (*func)(T value))
    {
        if (node == nullptr)
        {
            Console::WriteLine("Null priority queue");
            return;
        }

        if (node->Get(0)->Value == nullptr)
        {
            Console::WriteLine("Empty priority queue");
            return;
        }

        Console::WriteLine("Priority queue:");
        PriorityQueue<T>::PreOrderLeftRight(0, func);
        Console::WriteLine();
    };

    template <class T>
    void OrderAllPriorityQueue(PriorityQueue^ node, void (*func)(T value))
    {
        if (node == nullptr)
        {
            Console::WriteLine("Null priority queue");
            return;
        }

        if (node->Get(0)->Value == nullptr)
        {
            Console::WriteLine("Empty priority queue");
            return;
        }

        Console::WriteLine("����� ���:");
        node->PreOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("����� ���:");
        node->PreOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("����� ���:");
        node->InOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("����� ���:");
        node->InOrderRightLeft(0, func);
        Console::WriteLine();

        Console::WriteLine("����� ���:");
        node->PostOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("����� ���:");
        node->PostOrderRightLeft(0, func);
        Console::WriteLine();
    };
}