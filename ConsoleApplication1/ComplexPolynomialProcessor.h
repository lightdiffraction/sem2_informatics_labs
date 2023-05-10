using namespace Lab;

namespace Lab
{
    void ProcessComplexPolynomial()
    {
        Polynomial<Complex>^ polynomial = ReadComplexPolynomial();

        WritePolynomial(polynomial, WriteComplexOperand);

        while (true)
        {
            Console::Write("Enter operation: value: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Complex^ x = ReadComplexValue("Enter complex x: ");
                Complex^ value = gcnew Complex(polynomial->Value(x));
                WriteComplex(value);
            }
        }
    }

}