using namespace Lab;

namespace Lab
{
    void ProcessMatrixPolynomial()
    {
        Polynomial<Matrix<int>>^ polynomial = ReadMatrixPolynomial();

        WritePolynomial(polynomial, WriteMatrix);

        while (true)
        {
            Console::Write("Enter operation: value, multiply, sum, matrix_multiply, scalar_multiply: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Matrix<int>^ x = ReadMatrixInt();
                Matrix<int>^ value = gcnew Matrix<int>(*(polynomial->Value(x)));
                WriteMatrix(value);
            }
            if (operation == "multiply")
            {
                Polynomial<Matrix<int>>^ p = ReadMatrixPolynomial();
                Polynomial<Matrix<int>>^ result;
                result = polynomial * p;
                WritePolynomial(result, WriteMatrix);
            }

            if (operation == "sum")
            {
                Polynomial<Matrix<int>>^ p = ReadMatrixPolynomial();
                Polynomial<Matrix<int>>^ result;
                result = polynomial + p;
                WritePolynomial(result, WriteMatrix);
            }


            if (operation == "matrix_multiply")
            {
                Matrix<int>^ x = ReadMatrixInt();
                Polynomial<Matrix<int>>^ result;
                result = polynomial * x;
                WritePolynomial(result, WriteMatrix);
            }

            if (operation == "scalar_multiply")
            {
                Int32^ x = ReadInt32();
                Polynomial<Matrix<int>>^ result;
                result = polynomial / x;
                WritePolynomial(result, WriteMatrix);
            }

        }
    }

}