using namespace Lab;

namespace Lab
{
    template<class T>
    T^ ProcessArraySequenceOperation(String^ operation, ArraySequence<T>^ arraySequence, T ^ (*typeReader)())
    {
        if (operation == "first")
        {
            try
            {
                T^ result = arraySequence->Reduce(first);
                return result;
            }
            catch (Exception^ e)
            {
                Console::WriteLine(e->Message);
            }
        }

        if (operation == "last")
        {
            try
            {
                T^ result = arraySequence->Reduce(last);
                return result;
            }
            catch (Exception^ e)
            {
                Console::WriteLine(e->Message);
            }
        }

        if (operation == "firstordefault")
        {
            T^ result = arraySequence->Reduce(firstOrDefault);
            return result;
        }

        if (operation == "lastordefault")
        {
            T^ result = arraySequence->Reduce(lastOrDefault);
            return result;
        }

        if (operation == "add")
        {
            T^ value = typeReader();
            arraySequence->Add(value);
            return nullptr;
        }

        if (operation == "insertat")
        {
            T^ value = typeReader();
            Int32 index = ReadInt32Value("Enter index: ");
            arraySequence->InsertAt(index, value);
            return nullptr;
        }

        if (operation == "remove")
        {
            Int32 index = ReadInt32Value("Enter index: ");
            arraySequence->Remove(index);
            return nullptr;
        }
    }

    template<class T>
    void ProcessArraySequenceOperations(ArraySequence<T>^ arraySequence, T^(*typeReader)(), void(*typeWriter)(T^), void (*sequenceWriter)(ArraySequence<T>^))
    {
        while (true)
        {
            String^ operation = ReadArraySequenceOperation();

            if (operation == "exit")
            {
                break;
            }

            T^ result = ProcessArraySequenceOperation(operation, arraySequence, typeReader);
            if (result != nullptr)
            {
                Console::Write("Result: ");
                typeWriter(result);
            }
            else
            {
                sequenceWriter(arraySequence);
            }
        }
    }

    void ProcessArraySequence(String^ elementType)
    {
        if (elementType == "int")
        {
            ArraySequence<Int32>^ arraySequence = ReadIntArraySequence();
            ProcessArraySequenceOperations(arraySequence, ReadInt32, WriteInt, WriteIntArraySequence);
            WriteIntArraySequence(arraySequence);
        }
        else if (elementType == "float")
        {
            ArraySequence<Single>^ arraySequence = ReadFloatArraySequence();
            ProcessArraySequenceOperations(arraySequence, ReadSingle, WriteFloat, WriteFloatArraySequence);
            WriteFloatArraySequence(arraySequence);
        }
        else if (elementType == "complex")
        {
            ArraySequence<Complex>^ arraySequence = ReadComplexArraySequence();
            ProcessArraySequenceOperations(arraySequence, ReadComplex, WriteComplex, WriteComplexArraySequence);
            WriteComplexArraySequence(arraySequence);
        }
        else if (elementType == "string")
        {
            ArraySequence<String>^ arraySequence = ReadStringArraySequence();
            ProcessArraySequenceOperations(arraySequence, ReadString, WriteString, WriteStringArraySequence);
            WriteStringArraySequence(arraySequence);
        }
        else if (elementType == "student")
        {
            ArraySequence<Student>^ arraySequence = ReadStudentArraySequence();
            ProcessArraySequenceOperations(arraySequence, ReadStudent, WriteStudent, WriteStudentArraySequence);
            WriteStudentArraySequence(arraySequence);
        }
    }
}