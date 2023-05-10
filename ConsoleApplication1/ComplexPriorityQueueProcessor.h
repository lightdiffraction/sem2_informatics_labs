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
            Console::Write("Enter operation: insert, extract, exit: ");
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

            if (operation == "exit")
            {
                return;
            }
        }
    }

}