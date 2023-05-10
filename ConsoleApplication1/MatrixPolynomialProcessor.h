using namespace Lab;

namespace Lab
{
    void ProcessMatrixPolynomial()
    {
        Polynomial<Matrix<int>>^ polynomial = ReadMatrixPolynomial();

        WritePolynomial(polynomial, WriteMatrix);

        while (true)
        {
            Console::Write("Enter operation: value: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Matrix<int>^ x = ReadMatrixInt();
                Matrix<int>^ value = gcnew Matrix<int>(*(polynomial->Value(x)));
                WriteMatrix(value);
            }
        }
    }

}