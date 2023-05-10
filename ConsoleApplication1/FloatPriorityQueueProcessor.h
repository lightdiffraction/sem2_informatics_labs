using namespace Lab;

namespace Lab
{
    PriorityQueue<Single^>^ ReadFloatPriorityQueue()
    {
        int n = ReadElementsNumber();

        array<Single^>^ items = gcnew array<Single^>(n);
        for (int i = 0; i < n; i++)
        {
            items[i] = ReadSingle();
        }

        array<int>^ priorities = ReadPriorityQueuePriorities(n);
        PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();

        for (int i = 0; i < n; i++)
        {
            Element<Single^>^ element = gcnew Element<Single^>();
            element->Value = items[i];
            element->Priority = priorities[i];
            priorityQueue->Insert(element);
        }

        return priorityQueue;
    }

    void WriteFloatPriorityQueue(PriorityQueue<Single^>^ priorityQueue)
    {
        if (priorityQueue->Count() == 0)
        {
            Console::WriteLine("\nFloat Priority Queue is empty");
            return;
        }
        Console::WriteLine("\nFloat Priority Queue:");
        int pow = 0;
        int rowNumber = 0;
        int rowElementNumber = 0;
        int rowElementNumberMax = 1;
        for (int i = 0; i < priorityQueue->Count(); i++)
        {
            Console::Write("v{0:F}/p{1} ", priorityQueue->Get(i)->Value, priorityQueue->Get(i)->Priority);
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

    void ProcessFloatPriorityQueue()
    {
        PriorityQueue<Single^>^ priorityQueue = ReadFloatPriorityQueue();

        WriteFloatPriorityQueue(priorityQueue);

        while (true)
        {
            Console::Write("Enter operation: insert, extract, exit: ");
            String^ operation = Console::ReadLine();

            if (operation == "insert")
            {
                Element<Single^>^ element = gcnew Element<Single^>();
                element->Value = ReadSingle();
                element->Priority = ReadPriority();
                priorityQueue->Insert(element);
                WriteFloatPriorityQueue(priorityQueue);
            }

            if (operation == "extract")
            {
                Element<Single^>^ min = priorityQueue->ExtractMinimum();
                Console::WriteLine("Min priority {0}", min->Priority);
                WriteFloatPriorityQueue(priorityQueue);
            }

            if (operation == "exit")
            {
                return;
            }
        }
    }
}