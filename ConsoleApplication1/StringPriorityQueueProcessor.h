using namespace Lab;

namespace Lab
{
    PriorityQueue<String^>^ ReadStringPriorityQueue()
    {
        int n = ReadElementsNumber();

        array<String^>^ items = gcnew array<String^>(n);
        for (int i = 0; i < n; i++)
        {
            items[i] = ReadString();
        }

        array<int>^ priorities = ReadPriorityQueuePriorities(n);
        PriorityQueue<String^>^ priorityQueue = gcnew PriorityQueue<String^>();

        for (int i = 0; i < n; i++)
        {
            Element<String^>^ element = gcnew Element<String^>();
            element->Value = items[i];
            element->Priority = priorities[i];
            priorityQueue->Insert(element);
        }

        return priorityQueue;
    }

    void WriteStringPriorityQueue(PriorityQueue<String^>^ priorityQueue)
    {
        if (priorityQueue->Count() == 0)
        {
            Console::WriteLine("\String Priority Queue is empty");
            return;
        }
        Console::WriteLine("\String Priority Queue:");
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

    void ProcessStringPriorityQueue()
    {
        PriorityQueue<String^>^ priorityQueue = ReadStringPriorityQueue();

        WriteStringPriorityQueue(priorityQueue);

        while (true)
        {
            Console::Write("Enter operation: insert, extract, find, remove, getsubqueue, tostring, exit: ");
            String^ operation = Console::ReadLine();

            if (operation == "insert")
            {
                Element<String^>^ element = gcnew Element<String^>();
                element->Value = ReadString();
                element->Priority = ReadPriority();
                priorityQueue->Insert(element);
                WriteStringPriorityQueue(priorityQueue);
            }

            if (operation == "extract")
            {
                Element<String^>^ min = priorityQueue->ExtractMinimum();
                Console::WriteLine("Min priority {0}", min->Priority);
                WriteStringPriorityQueue(priorityQueue);
            }

            if (operation == "find")
            {
                int priority = ReadInt32Value("Enter priority to find: ");
                Element<String^>^ result = priorityQueue->Find(priority);
                if (result == nullptr)
                {
                    Console::WriteLine("Element with this priority not found.");
                }
                else
                {
                    Console::Write("Element with this priority found: ");
                    WriteString(result->Value);
                }
            }

            if (operation == "remove")
            {
                int priority = ReadInt32Value("Enter priority to remove: ");
                priorityQueue->Remove(priority);
                WriteStringPriorityQueue(priorityQueue);
            }

            if (operation == "getsubqueue")
            {
                int priority = ReadInt32Value("Enter priority of element to get sub queue of: ");
                Element<String^>^ element = priorityQueue->Find(priority);
                if (element == nullptr)
                {
                    Console::WriteLine("Element with this priority not found.");
                }
                else
                {
                    PriorityQueue<String^>^ newQueue = priorityQueue->GetSubQueue(element);
                    WriteStringPriorityQueue(newQueue);
                }
            }

            if (operation == "tostring")
            {
                String^ command = ReadString("Enter order (���, ���, ���, ���, ���, ���): ");
                String^ result = gcnew String("");
                if (command == "���")
                {
                    result = priorityQueue->PreOrderLeftRight(0, "", StringToString);
                }
                if (command == "���")
                {
                    result = priorityQueue->PreOrderRightLeft(0, "", StringToString);
                }
                if (command == "���")
                {
                    result = priorityQueue->InOrderLeftRight(0, "", StringToString);
                }
                if (command == "���")
                {
                    result = priorityQueue->InOrderRightLeft(0, "", StringToString);
                }
                if (command == "���")
                {
                    result = priorityQueue->PostOrderLeftRight(0, "", StringToString);
                }
                if (command == "���")
                {
                    result = priorityQueue->PostOrderRightLeft(0, "", StringToString);
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