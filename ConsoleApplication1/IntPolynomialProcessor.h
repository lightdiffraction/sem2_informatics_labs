using namespace Lab;

namespace Lab
{
	void ProcessIntPolynomial()
	{
		Polynomial<Int32>^ polynomial = ReadIntPolynomial();

		WritePolynomial(polynomial, WriteIntOperand);

        while (true)
        {
            Console::Write("Enter operation: value: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Int32 x = ReadInt32Value("Enter integer x: ");
                Int32^ value = polynomial->Value(x);
                WriteInt(value);
            }
        }
	}
}