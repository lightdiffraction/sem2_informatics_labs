namespace Lab
{

    Int32 ReadElementsNumber()
    {
        Console::Write("Enter elements number: ");
        Int32 n = 0;
        String^ str = Console::ReadLine();
        Int32::TryParse(str, n);
        return n;
    }

    Int32 ReadInt32Value(String^ label)
    {
        Console::Write(label);
        Int32 value = 0;
        String^ str = Console::ReadLine();
        Int32::TryParse(str, value);
        return value;
    }

    String^ ReadElementType()
    {
        String^ elementType;
        Console::Write("Enter element type (int, float, complex, string, student, matrix, function): ");
        elementType = Console::ReadLine();
        return elementType;
    }

    String^ ReadSequenceType()
    {
        String^ sequenceType;
        Console::Write("Enter sequence type (ArraySequence, LinkedList, PriorityQueue, Polynomial, BinaryTree): ");
        sequenceType = Console::ReadLine();
        return sequenceType;
    }

    array<int>^ ReadPriorityQueuePriorities(int count)
    {
        array<int>^ priorities = gcnew array<int>(count);

        for (int i = 0; i < count; i++)
        {
            Console::Write("Enter priority {0}: ", i + 1);
            scanf_s("%d", &priorities[i]);
        }

        return priorities;
    }

    int ReadPriority()
    {
        Console::Write("Enter priority: ");
        int priority = 0;
        scanf_s("%d", &priority);
        return priority;
    }

    String^ ReadArraySequenceOperation()
    {
        Console::WriteLine("Operations: first, last, firstordefault, lastordefault, add, insertat, remove, exit");
        Console::Write("Enter operation: ");
        String^ operation = Console::ReadLine();
        return operation;
    }

    String^ ReadListSequenceOperation()
    {
        Console::WriteLine("Operations: append, prepend, insertat, exit, get, getlast");
        Console::Write("Enter operation: ");
        String^ operation = Console::ReadLine();
        return operation;
    }
}