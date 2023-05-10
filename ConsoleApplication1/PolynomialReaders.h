using namespace Lab;

namespace Lab
{
    Polynomial<Int32>^ ReadIntPolynomial()
    {
        int n = ReadElementsNumber();

        ArraySequence<Int32>^ arraySequence = gcnew ArraySequence<Int32>();

        for (int i = 0; i < n; i++)
        {
            Int32^ item = ReadInt32();
            arraySequence->Add(item);
        }

        Polynomial<Int32>^ polynomial = gcnew Polynomial<Int32>(arraySequence);

        return polynomial;
    }

    Polynomial<Single>^ ReadFloatPolynomial()
    {
        int n = ReadElementsNumber();

        ArraySequence<Single>^ arraySequence = gcnew ArraySequence<Single>();

        for (int i = 0; i < n; i++)
        {
            Single^ item = ReadSingle();
            arraySequence->Add(item);
        }

        Polynomial<Single>^ polynomial = gcnew Polynomial<Single>(arraySequence);

        return polynomial;
    }

    Polynomial<Complex>^ ReadComplexPolynomial()
    {
        int n = ReadElementsNumber();

        ArraySequence<Complex>^ arraySequence = gcnew ArraySequence<Complex>();

        for (int i = 0; i < n; i++)
        {
            Complex^ item = ReadComplex();
            arraySequence->Add(item);
        }

        Polynomial<Complex>^ polynomial = gcnew Polynomial<Complex>(arraySequence);

        return polynomial;
    }

    Polynomial<Matrix<int>>^ ReadMatrixPolynomial()
    {
        int n = ReadElementsNumber();

        ArraySequence<Matrix<int>>^ arraySequence = gcnew ArraySequence<Matrix<int>>();

        Int32 matrixSize;

        for (int i = 0; i < n; i++)
        {
            Matrix<int>^ item = ReadMatrixInt();
            matrixSize = item->GetSize();
            arraySequence->Add(item);
        }

        Polynomial<Matrix<int>>^ polynomial = gcnew Polynomial<Matrix<int>>(arraySequence);
        polynomial->SetParam(matrixSize);

        return polynomial;
    }
}