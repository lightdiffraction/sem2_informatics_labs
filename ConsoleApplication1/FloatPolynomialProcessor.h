using namespace Lab;

namespace Lab
{
	void ProcessFloatPolynomial()
	{
		Polynomial<Single>^ polynomial = ReadFloatPolynomial();

        WritePolynomial(polynomial, WriteFloatOperand);

        while (true)
        {
            Console::Write("Enter operation: value: ");
            String^ operation = Console::ReadLine();

            if (operation == "value")
            {
                Single x = ReadSingleValue("Enter float x: ");
                Single^ value = polynomial->Value(x);
                WriteFloat(value);
            }
        }
	}
}