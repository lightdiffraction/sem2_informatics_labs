using namespace Lab;

namespace Lab
{
    template<class T>
    String^ DisplayName(Func<T>^ function)
    {

        Func <int>^ func0 = gcnew Func <int>(f0);
        Func <int>^ func1 = gcnew Func <int>(f1);
        Func <int>^ func2 = gcnew Func <int>(f2);
        Func <int>^ func3 = gcnew Func <int>(f3);


        String^ result;

        
        if (function == func0)
        {
            result = " get zero";
        }
        if (function == func1)
        {
            result = " get one";
        }
        if (function == func2)
        {
            result = " get two";
        }
        if (function == func3)
        {
            result = " get three";
        }
        return result;
    }

    template<class T>
    PriorityQueue<Func<T>^>^ ReadFunctionPriorityQueue()
    {


        Func <int>^ func0 = gcnew Func <int>(f0);
        Func <int>^ func1 = gcnew Func <int>(f1);
        Func <int>^ func2 = gcnew Func <int>(f2);
        Func <int>^ func3 = gcnew Func <int>(f3);

        array<Func<int>^>^ functions = gcnew array<Func<int>^>(4);

        functions[0] = func0;
        functions[1] = func1;
        functions[2] = func2;
        functions[3] = func3;

        int n = ReadElementsNumber();

        array<Func<int>^>^ items = gcnew array<Func<int>^>(n);

        for (int i = 0; i < n; i++)
        {
            items[i] = functions[ReadInt32Value()];
        }

        array<int>^ priorities = ReadPriorityQueuePriorities(n);
        PriorityQueue<Func<T>^>^ priorityQueue = gcnew PriorityQueue<Func<T>^>();

        for (int i = 0; i < n; i++)
        {
            Element<Func<T>^>^ element = gcnew Element<Func<T>^>();
            element->Value = items[i];
            element->Priority = priorities[i];
            priorityQueue->Insert(element);
        }

        return priorityQueue;
    }

    template<class T>
    void WriteFunctionPriorityQueue(PriorityQueue<Func<T>^>^ priorityQueue)
    {
        

        if (priorityQueue->Count() == 0)
        {
            Console::WriteLine("\Function Priority Queue is empty");
            return;
        }

        Console::WriteLine("\Function Priority Queue:");
        int pow = 0;
        int rowNumber = 0;
        int rowElementNumber = 0;
        int rowElementNumberMax = 1;
        for (int i = 0; i < priorityQueue->Count(); i++)
        {
            Console::Write("v{0}/p{1} ", DisplayName(priorityQueue->Get(i)->Value), priorityQueue->Get(i)->Priority);
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

    template<class T>
    void ProcessFunctionPriorityQueue()
    {
        Console::WriteLine("\Enter numbers from 0 to 3 for functions f0, f1, f2, f3:");

        PriorityQueue<Func<T>^>^ priorityQueue = ReadFunctionPriorityQueue<int>();

        Func <int>^ func0 = gcnew Func <int>(f0);
        Func <int>^ func1 = gcnew Func <int>(f1);
        Func <int>^ func2 = gcnew Func <int>(f2);
        Func <int>^ func3 = gcnew Func <int>(f3);

        array<Func<int>^>^ functions = gcnew array<Func<int>^>(4);

        functions[0] = func0;
        functions[1] = func1;
        functions[2] = func2;
        functions[3] = func3;   

        WriteFunctionPriorityQueue<int>(priorityQueue);


        while (true)
        {
            Console::Write("Enter operation: insert, extract, exit: ");
            String^ operation = Console::ReadLine();

            if (operation == "insert")
            {
                Element<Func<T>^>^ element = gcnew Element<Func<T>^>();
                element->Value = functions[ReadInt32Value()];
                element->Priority = ReadPriority();
                priorityQueue->Insert(element);
                WriteFunctionPriorityQueue<int>(priorityQueue);
            }

            if (operation == "extract")
            {
                Element<Func<T>^>^ min = priorityQueue->ExtractMinimum();
                Console::WriteLine("Min priority {0}", min->Priority);
                WriteFunctionPriorityQueue<int>(priorityQueue);
            }



            if (operation == "exit")
            {
                return;
            }
        }
    }

}