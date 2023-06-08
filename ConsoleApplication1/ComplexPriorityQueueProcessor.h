using namespace Lab;

namespace Lab
{
    PriorityQueue<Complex^>^ ReadComplexPriorityQueue()
    {
        int n = ReadElementsNumber();

        array<Complex^>^ items = gcnew array<Complex^>(n);
        for (int i = 0; i < n; i++)
        {
            items[i] = ReadComplex();
        }

        array<int>^ priorities = ReadPriorityQueuePriorities(n);
        PriorityQueue<Complex^>^ priorityQueue = gcnew PriorityQueue<Complex^>();

        for (int i = 0; i < n; i++)
        {
            Element<Complex^>^ element = gcnew Element<Complex^>();
            element->Value = items[i];
            element->Priority = priorities[i];
            priorityQueue->Insert(element);
        }

        return priorityQueue;
    }

    void WriteComplexPriorityQueue(PriorityQueue<Complex^>^ priorityQueue)
    {
        if (priorityQueue->Count() == 0)
        {
            Console::WriteLine("\nComplex Priority Queue is empty");
            return;
        }
        Console::WriteLine("\nComplex Priority Queue:");
        int pow = 0;
        int rowNumber = 0;
        int rowElementNumber = 0;
        int rowElementNumberMax = 1;
        for (int i = 0; i < priorityQueue->Count(); i++)
        {
            Console::Write("v{0:F}+{1:F}i/p{2} ", priorityQueue->Get(i)->Value->Real, priorityQueue->Get(i)->Value->Imaginary, priorityQueue->Get(i)->Priority);
            ++rowElementNumber;
            if (rowElementNumber == rowElementNumberMax)
            {
                Console::WriteLine();
                ++rowNumber;
                rowElementNumber = 0;
                rowElementNumberMax = Math::Pow(2, rowNumber);
            }
        }
        Console::WriteLine();
        Console::WriteLine();
    }

    void ProcessComplexPriorityQueue()
    {
        PriorityQueue<Complex^>^ priorityQueue = ReadComplexPriorityQueue();

        WriteComplexPriorityQueue(priorityQueue);

        while (true)
        {
            Console::Write("Enter operation: insert, extract, find, remove, tostring, exit: ");
            String^ operation = Console::ReadLine();

            if (operation == "insert")
            {
                Element<Complex^>^ element = gcnew Element<Complex^>();
                element->Value = ReadComplex();
                element->Priority = ReadPriority();
                priorityQueue->Insert(element);
                WriteComplexPriorityQueue(priorityQueue);
            }

            if (operation == "extract")
            {
                Element<Complex^>^ min = priorityQueue->ExtractMinimum();
                Console::WriteLine("Min priority {0}", min->Priority);
                WriteComplexPriorityQueue(priorityQueue);
            }

            if (operation == "find")
            {
                int priority = ReadInt32Value("Enter priority to find: ");
                Element<Complex^>^ result = priorityQueue->Find(priority);
                if (result == nullptr)
                {
                    Console::WriteLine("Element with this priority not found.");
                }
                else
                {
                    Console::Write("Element with this priority found: ");
                    WriteComplex(result->Value);
                }
            }

            if (operation == "remove")
            {
                int priority = ReadInt32Value("Enter priority to remove: ");
                priorityQueue->Remove(priority);
                WriteComplexPriorityQueue(priorityQueue);
            }

            if (operation == "tostring")
            {
                String^ command = ReadString("Enter order (ÊËÏ, ÊÏË, ËÊÏ, ÏÊË, ËÏÊ, ÏËÊ): ");
                String^ result = gcnew String("");
                if (command == "ÊËÏ")
                {
                    result = priorityQueue->PreOrderLeftRight(0, "", ComplexToString);
                }
                if (command == "ÊÏË")
                {
                    result = priorityQueue->PreOrderRightLeft(0, "", ComplexToString);
                }
                if (command == "ËÊÏ")
                {
                    result = priorityQueue->InOrderLeftRight(0, "", ComplexToString);
                }
                if (command == "ÏÊË")
                {
                    result = priorityQueue->InOrderRightLeft(0, "", ComplexToString);
                }
                if (command == "ËÏÊ")
                {
                    result = priorityQueue->PostOrderLeftRight(0, "", ComplexToString);
                }
                if (command == "ÏËÊ")
                {
                    result = priorityQueue->PostOrderRightLeft(0, "", ComplexToString);
                }
                Console::WriteLine(result);
            }

            if (operation == "exit")
            {
                return;
            }
        }
    }

}