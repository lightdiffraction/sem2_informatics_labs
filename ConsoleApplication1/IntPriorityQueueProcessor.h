using namespace Lab;

namespace Lab
{
    PriorityQueue<Int32^>^ ReadIntPriorityQueue()
    {
        int n = ReadElementsNumber();

        array<Int32^>^ items = gcnew array<Int32^>(n);
        for (int i = 0; i < n; i++)
        {
            items[i] = ReadInt32();
        }

        array<int>^ priorities = ReadPriorityQueuePriorities(n);
        PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();

        for (int i = 0; i < n; i++)
        {
            Element<Int32^>^ element = gcnew Element<Int32^>();
            element->Value = items[i];
            element->Priority = priorities[i];
            priorityQueue->Insert(element);
        }

        return priorityQueue;
    }

    void WriteIntPriorityQueue(PriorityQueue<Int32^>^ priorityQueue)
    {
        if (priorityQueue->Count() == 0)
        {
            Console::WriteLine("\nInt Priority Queue is empty");
            return;
        }
        Console::WriteLine("\nInt Priority Queue:");
        int pow = 0;
        int rowNumber = 0;
        int rowElementNumber = 0;
        int rowElementNumberMax = 1;
        for (int i = 0; i < priorityQueue->Count(); i++)
        {
            Console::Write("v{0}/p{1} ", priorityQueue->Get(i)->Value, priorityQueue->Get(i)->Priority);
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

    void ProcessIntPriorityQueue()
    {
        PriorityQueue<Int32^>^ priorityQueue = ReadIntPriorityQueue();

        WriteIntPriorityQueue(priorityQueue);

        while (true)
        {
            Console::Write("Enter operation: insert, extract, find, remove, getsubqueue, tostring, exit: ");
            String^ operation = Console::ReadLine();

            if (operation == "insert")
            {
                Element<Int32^>^ element = gcnew Element<Int32^>();
                element->Value = ReadInt32();
                element->Priority = ReadPriority();
                priorityQueue->Insert(element);
                WriteIntPriorityQueue(priorityQueue);
            }

            if (operation == "extract")
            {
                Element<Int32^>^ min = priorityQueue->ExtractMinimum();
                Console::WriteLine("Min priority {0}", min->Priority);
                WriteIntPriorityQueue(priorityQueue);
            }

            if (operation == "find")
            {
                int priority = ReadInt32Value("Enter priority to find: ");
                Element<Int32^>^ result = priorityQueue->Find(priority);
                if (result == nullptr)
                {
                    Console::WriteLine("Element with this priority not found.");
                }
                else
                {
                    Console::Write("Element with this priority found: ");
                    WriteInt(result->Value);
                }
            }

            if (operation == "remove")
            {
                int priority = ReadInt32Value("Enter priority to remove: ");
                priorityQueue->Remove(priority);
                WriteIntPriorityQueue(priorityQueue);
            }

            if (operation == "getsubqueue")
            {
                int priority = ReadInt32Value("Enter priority of element to get sub queue of: ");
                Element<Int32^>^ element = priorityQueue->Find(priority);
                if (element == nullptr)
                {
                    Console::WriteLine("Element with this priority not found.");
                }
                else
                {
                    PriorityQueue<Int32^>^ newQueue = priorityQueue->GetSubQueue(element);
                    WriteIntPriorityQueue(newQueue);
                }
            }

            if (operation == "tostring")
            {
                String^ command = ReadString("Enter order (ÊËÏ, ÊÏË, ËÊÏ, ÏÊË, ËÏÊ, ÏËÊ): ");
                String^ result = gcnew String("");
                if (command == "ÊËÏ")
                {
                    result = priorityQueue->PreOrderLeftRight(0, "", IntToString);
                }
                if (command == "ÊÏË")
                {
                    result = priorityQueue->PreOrderRightLeft(0, "", IntToString);
                }
                if (command == "ËÊÏ")
                {
                    result = priorityQueue->InOrderLeftRight(0, "", IntToString);
                }
                if (command == "ÏÊË")
                {
                    result = priorityQueue->InOrderRightLeft(0, "", IntToString);
                }
                if (command == "ËÏÊ")
                {
                    result = priorityQueue->PostOrderLeftRight(0, "", IntToString);
                }
                if (command == "ÏËÊ")
                {
                    result = priorityQueue->PostOrderRightLeft(0, "", IntToString);
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