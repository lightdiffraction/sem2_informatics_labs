using namespace Lab;

namespace Lab
{
	void ProcessFloatPolynomial()
	{
		Polynomial<Single>^ polynomial = ReadFloatPolynomial();

        WritePolynomial(polynomial, WriteFloatOperand);

        while (true)
        {
            Console::Write("Enter operation: value, multiply, sum, scalar_multiply: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Single x = ReadSingleValue("Enter float x: ");
                Single^ value = polynomial->Value(x);
                WriteFloat(value);
            }

            if (operation == "multiply")
            {
                Polynomial<Single>^ p = ReadFloatPolynomial();
                Polynomial<Single>^ result;
                result = polynomial * p;
                WritePolynomial(result, WriteFloatOperand);
            }

            if (operation == "sum")
            {
                Polynomial<Single>^ p = ReadFloatPolynomial();
                Polynomial<Single>^ result;
                result = polynomial + p;
                WritePolynomial(result, WriteFloatOperand);

            if (operation == "scalar_multiply")
            {
                Single x = ReadSingleValue("Enter integer x: ");
                Polynomial<Single>^ result;
                result = polynomial * x;
                WritePolynomial(result, WriteFloatOperand);
            }

            }
        }
	}
}