using namespace Lab;

namespace Lab
{
    void ProcessComplexPolynomial()
    {
        Polynomial<Complex>^ polynomial = ReadComplexPolynomial();

        WritePolynomial(polynomial, WriteComplexOperand);

        while (true)
        {
            Console::Write("Enter operation: value, multiply, sum, scalar_multiply: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Complex^ x = ReadComplexValue("Enter complex x: ");
                Complex^ value = gcnew Complex(polynomial->Value(x));
                WriteComplex(value);
            }
            if (operation == "multiply")
            {
                Polynomial<Complex>^ p = ReadComplexPolynomial();
                Polynomial<Complex>^ result;
                result = polynomial * p;
                WritePolynomial(result, WriteComplexOperand);
            }

            if (operation == "sum")
            {
                Polynomial<Complex>^ p = ReadComplexPolynomial();
                Polynomial<Complex>^ result;
                result = polynomial + p;
                WritePolynomial(result, WriteComplexOperand);
            }

            if (operation == "scalar_multiply")
            {
                Complex^ x = ReadComplexValue("Enter integer x: ");
                Polynomial<Complex>^ result;
                result = polynomial * x;
                WritePolynomial(result, WriteComplexOperand);
            }

        }
    }

}