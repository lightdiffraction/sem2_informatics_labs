using namespace Lab;

namespace Lab
{
    ArraySequence<Int32>^ ReadIntArraySequence()
    {
        Int32 n = ReadElementsNumber();
        ArraySequence<Int32>^ arraySequence = gcnew  ArraySequence<Int32>();

        for (int i = 0; i < n; i++)
        {
            Int32^ ptr = ReadInt32();
            arraySequence->Add(ptr);
        }

        return arraySequence;
    }

    ArraySequence<Single>^ ReadFloatArraySequence()
    {
        Int32 n = ReadElementsNumber();
        ArraySequence<Single>^ arraySequence = gcnew  ArraySequence<Single>();

        for (int i = 0; i < n; i++)
        {
            Single^ ptr = ReadSingle();
            arraySequence->Add(ptr);
        }

        return arraySequence;
    }

    ArraySequence<Complex>^ ReadComplexArraySequence()
    {
        Int32 n = ReadElementsNumber();
        ArraySequence<Complex>^ arraySequence = gcnew  ArraySequence<Complex>();

        for (int i = 0; i < n; i++)
        {
            Complex^ ptr = ReadComplex();
            arraySequence->Add(ptr);
        }

        return arraySequence;
    }

    ArraySequence<String>^ ReadStringArraySequence()
    {
        Int32 n = ReadElementsNumber();
        ArraySequence<String>^ arraySequence = gcnew  ArraySequence<String>();

        for (int i = 0; i < n; i++)
        {
            String^ ptr = ReadString();
            arraySequence->Add(ptr);
        }

        return arraySequence;
    }

    ArraySequence<Student>^ ReadStudentArraySequence()
    {
        Int32 n = ReadElementsNumber();
        ArraySequence<Student>^ arraySequence = gcnew  ArraySequence<Student>();

        for (int i = 0; i < n; i++)
        {
            Student^ ptr = ReadStudent();
            arraySequence->Add(ptr);
        }

        return arraySequence;
    }
}