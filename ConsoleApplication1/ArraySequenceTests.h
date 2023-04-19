#include <cassert> 

using namespace Lab2;

namespace Lab2
{
	ArraySequence<int>^ CreateArraySequence()
	{
		int n = 5;
		array<int>^ a = gcnew array<int>(5);
		for (int i = 0; i < n; i++)
		{
			a[i] = i;
		}

		ArraySequence<int>^ sequence = gcnew ArraySequence<int>(a, 5);
		return sequence;
	}

	void ArraySequenceCreationTest()
	{
		ArraySequence<int>^ sequence = CreateArraySequence();

		int i = 0;
		for each (int value in sequence)
		{
			assert(value == i);
			++i;
		}
	}

	void ArraySequenceAddTest()
	{
		ArraySequence<int>^ sequence = CreateArraySequence();
		int size = sequence->Count();
		sequence->Add(sequence->Count());
		int i = 0;
		for each (int value in sequence)
		{
			assert(value == i);
			++i;
		}
		assert(sequence->Count() == size + 1);
	}

	void ArraySequenceRemoveTest()
	{
		ArraySequence<int>^ sequence = CreateArraySequence();
		int size = sequence->Count();
		sequence->Remove(0);
		int i = 1;
		for each (int value in sequence)
		{
			assert(value == i);
			++i;
		}
		assert(sequence->Count() == size - 1);
	}

	void RunArraySequenceTests()
	{
		ArraySequenceCreationTest();
		ArraySequenceAddTest();
		ArraySequenceRemoveTest();
	}
}