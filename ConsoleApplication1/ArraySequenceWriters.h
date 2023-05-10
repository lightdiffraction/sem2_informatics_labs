namespace Lab
{
	void WriteIntArraySequence(ArraySequence<Int32>^ arraySequence)
	{
		Console::WriteLine("Int Array Sequence:");
		for (int i = 0; i < arraySequence->GetSize(); i++)
		{
			Console::Write("{0} ", arraySequence->Get(i));
		}
		Console::WriteLine();
	}

	void WriteFloatArraySequence(ArraySequence<Single>^ arraySequence)
	{
		Console::WriteLine("Single Array Sequence:");
		for (int i = 0; i < arraySequence->GetSize(); i++)
		{
			Console::Write("{0} ", arraySequence->Get(i));
		}
		Console::WriteLine();
	}

	void WriteComplexArraySequence(ArraySequence<Complex>^ arraySequence)
	{
		Console::WriteLine("Complex Array Sequence:");
		for (int i = 0; i < arraySequence->GetSize(); i++)
		{
			Console::Write("{0}+{1}i ", arraySequence->Get(i)->Real, arraySequence->Get(i)->Imaginary);
		}
		Console::WriteLine();
	}

	void WriteStringArraySequence(ArraySequence<String>^ arraySequence)
	{
		Console::WriteLine("String Array Sequence:");
		for (int i = 0; i < arraySequence->GetSize(); i++)
		{
			Console::Write("{0} ", arraySequence->Get(i));
		}
		Console::WriteLine();
	}

	void WriteStudentArraySequence(ArraySequence<Student>^ arraySequence)
	{
		Console::WriteLine("Student Array Sequence:");
		for (int i = 0; i < arraySequence->GetSize(); i++)
		{
			Console::Write("{0} {1}", arraySequence->Get(i)->GetFirstName(), arraySequence->Get(i)->GetLastName());
		}
		Console::WriteLine();
	}
}