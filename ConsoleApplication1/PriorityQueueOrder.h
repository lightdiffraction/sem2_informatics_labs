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

        Console::WriteLine("Îáõîä ÊËÏ:");
        node->PreOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("Îáõîä ÊÏË:");
        node->PreOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("Îáõîä ËÊÏ:");
        node->InOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("Îáõîä ÏÊË:");
        node->InOrderRightLeft(0, func);
        Console::WriteLine();

        Console::WriteLine("Îáõîä ËÏÊ:");
        node->PostOrderLeftRight(0, func);
        Console::WriteLine();

        Console::WriteLine("Îáõîä ÏËÊ:");
        node->PostOrderRightLeft(0, func);
        Console::WriteLine();
    };
}