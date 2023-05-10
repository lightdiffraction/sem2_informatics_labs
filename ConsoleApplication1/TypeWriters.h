using namespace Lab;

namespace Lab
{
	void WriteInt(Int32^ value)
	{
		Console::WriteLine(value);
	}

	void WriteInt(Int32 value)
	{
		Console::WriteLine(value);
	}

	void WriteFloat(Single^ value)
	{
		Console::WriteLine(value);
	}

	void WriteString(String^ value)
	{
		Console::WriteLine(value);
	}

	void WriteComplex(Complex^ value)
	{
		Console::WriteLine("{0}+{1}i", value->Real, value-> Imaginary);
	}

	void WriteIntOperand(Int32^ value)
	{
		Console::Write("{0}", value);
	}

	void WriteFloatOperand(Single^ value)
	{
		Console::Write("{0}", value);
	}

	void WriteComplexOperand(Complex^ value)
	{
		Console::Write("({0}+{1}i)", value->Real, value->Imaginary);
	}

	void WriteComplexValue(Complex value)
	{
		Console::WriteLine("{0}+{1}i", value.Real, value.Imaginary);
	}

	void WriteStudent(Student^ value)
	{
		Console::WriteLine("{0} {1} {2}",
			value->GetFirstName(),
			value->GetLastName(),
			String::Format("{0:dd/MM/yyyy}", value->GetDate()));
	}

	void WriteMatrix(Matrix<int>^ value)
	{
		for (int i = 0; i < value->GetSize(); i++)
		{
			Console::WriteLine();
			for (int j = 0; j < value->GetSize(); j++)
			{
				Console::Write("{0} ", (value->items)[i][j]);
			}
		}

		Console::WriteLine();
	}
}