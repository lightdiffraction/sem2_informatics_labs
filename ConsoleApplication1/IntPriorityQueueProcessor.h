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
            Console::Write("Enter operation: insert, extract, exit: ");
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

            if (operation == "exit")
            {
                return;
            }
        }
    }

}