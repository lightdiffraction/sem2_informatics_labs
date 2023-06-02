using namespace Lab;

namespace Lab
{
    ListSequence<Int32>^ ReadIntListSequence()
    {
        Int32 n = ReadElementsNumber();
        ListSequence<Int32>^ listSequence = gcnew  ListSequence<Int32>();

        for (int i = 0; i < n; i++)
        {
            Int32 value = ReadInt32Value("Enter item: ");
            listSequence->Append(value);
        }

        return listSequence;
    }
}