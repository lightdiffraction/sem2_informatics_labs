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

	void WriteIntTreeNode(Int32^ value)
	{
		Console::Write(" {0} ", value);
	}

	void WriteFloat(Single^ value)
	{
		Console::WriteLine(value);
	}

	void WriteFloatTreeNode(Single^ value)
	{
		Console::Write(" {0} ", value);
	}

	void WriteString(String^ value)
	{
		Console::WriteLine(value);
	}

	void WriteStringTreeNode(String^ value)
	{
		Console::Write(" {0} ", value);
	}

	void WriteComplex(Complex^ value)
	{
		Console::WriteLine("{0}+{1}i", value->Real, value-> Imaginary);
	}

	void WriteComplexTreeNode(Complex^ value)
	{
		Console::Write(" {0}+{1}i ", value->Real, value->Imaginary);
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

	void WriteStudentTreeNode(Student^ value)
	{
		Console::Write(" {0} {1} ", value->GetFirstName(), value->GetLastName());
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

	String^ IntToString(Int32^ value)
	{
		return value->ToString();
	}

	String^ FloatToString(Single^ value)
	{
		return value->ToString();
	}

	String^ StringToString(String^ value)
	{
		return value;
	}

	String^ StudentToString(Student^ value)
	{
		return	value->GetFirstName() + " " + value->GetLastName() + String::Format("{0:dd/MM/yyyy}", value->GetDate());
	}

	String^ StudentTreeNodeToString(Student^ value)
	{
		return	" " + value->GetFirstName() + " " + value->GetLastName() + " ";
	}

	String^ ComplexToString(Complex^ value)
	{
		return value->Real->ToString() + "+" + value->Imaginary->ToString() + "i";
	}

	String^ ComplexTreeNodeToString(Complex^ value)
	{
		return " " + value->Real->ToString() + "+" + value->Imaginary->ToString() + "i ";
	}

	String^ FuncToString(Func<int>^ value)
	{
		return value->ToString();
	}
	
	String^ IntTreeNodeToString(Int32^ value)
	{
		return (*value).ToString();
	}

	String^ FloatTreeNodeToString(Single^ value)
	{
		return (*value).ToString();
	}

	String^ StringTreeNodeToString(String^ value)
	{
		return value;
	}
}