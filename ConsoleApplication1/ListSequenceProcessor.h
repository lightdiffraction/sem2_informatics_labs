using namespace Lab;

namespace Lab
{
    template<class T>
    void ProcessListSequenceOperations(String^ operation, ListSequence<T>^ listSequence, T (*reader)(), void (*writer)(T))
    {
        if (operation == "append")
        {
            T value = reader();
            listSequence->Append(value);
        }

        if (operation == "prepend")
        {
            T value = reader();
            listSequence->Prepend(value);
        }

        if (operation == "remove")
        {
            int index = ReadInt32Value("Enter index: ");
            listSequence->Prepend(index);
        }

        if (operation == "insertat")
        {
            T value = reader();
            int index = ReadInt32Value("Enter index: ");
            listSequence->InsertAt(value, index);
        }

        if (operation == "get")
        {
            int index = ReadInt32Value("Enter index: ");
            T result = listSequence->Get(index + 1);
            writer(result);
        }

        if (operation == "getlast")
        {
            T result = listSequence->GetLast();
            writer(result);
        }

        if (operation == "getfirst")
        {
            T result = listSequence->GetFirst();
            writer(result);
        }

        if (operation == "exit")
        {
            return;
        }
    }

    void ProcessListSequence(String^ elementType)
    {
        if (elementType == "int")
        {
            ListSequence<Int32>^ listSequence = ReadIntListSequence();

            while (true)
            {
                String^ operation = ReadListSequenceOperation();
                ProcessListSequenceOperations(operation, listSequence, ReadInt32Value, WriteInt);
                WriteListSequence(listSequence, WriteInt);
            }
        }
        else if (elementType == "float")
        {
        }
        else if (elementType == "complex")
        {
        }
        else if (elementType == "string")
        {
        }
        else if (elementType == "student")
        {
        }
    }
}