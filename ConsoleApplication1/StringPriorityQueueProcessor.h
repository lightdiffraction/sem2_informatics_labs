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
            Console::Write("Enter operation: insert, extract, exit: ");
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

            if (operation == "exit")
            {
                return;
            }
        }
    }

}