using namespace Lab;

namespace Lab
{
	void ProcessIntPolynomial()
	{
		Polynomial<Int32>^ polynomial = ReadIntPolynomial();

		WritePolynomial(polynomial, WriteIntOperand);

        while (true)
        {
            Console::Write("Enter operation: value, multiply, sum, scalar_multiply: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Int32 x = ReadInt32Value("Enter integer x: ");
                Int32^ value = polynomial->Value(x);
                WriteInt(value);
            }

            if (operation == "multiply")
            {
                Polynomial<Int32>^ p = ReadIntPolynomial();
                Polynomial<Int32>^ result;
                result = polynomial * p;
                WritePolynomial(result, WriteIntOperand);
            }

            if (operation == "sum")
            {
                Polynomial<Int32>^ p = ReadIntPolynomial();
                Polynomial<Int32>^ result;
                result = polynomial + p;
                WritePolynomial(result, WriteIntOperand);
            }

            if (operation == "scalar_multiply")
            {
                Int32 x = ReadInt32Value("Enter integer x: ");
                Polynomial<Int32>^ result;
                result = polynomial * x;
                WritePolynomial(result, WriteIntOperand);
            }
        }
	}
}