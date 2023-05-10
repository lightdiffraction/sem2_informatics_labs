#include <cassert> 

using namespace Lab;

namespace Lab
{
	/*Sequence<float>^ CreateFloatSequence()
	{
		int n = 5;
		array<float>^ a = gcnew array<float>(5);

		for (int i = 0; i < n; i++)
		{
			a[i] = i;
		}

		Sequence<float>^ sequence = gcnew Sequence<float>(a, 5);
		return sequence;
	}

	void FloatSequenceCreationTest()
	{
		Sequence<float>^ sequence = CreateFloatSequence();

		float i = 0;
		for each (float value in sequence)
		{
			assert(value == i);
			++i;
		}
	}
	

	Sequence<int>^ CreateSequence()
	{
		int n = 5;
		array<int>^ a = gcnew array<int>(5);

		for (int i = 0; i < n; i++)
		{
			a[i] = i;
		}

		Sequence<int>^ sequence = gcnew Sequence<int>(a, 5);
		return sequence;
	}

	Sequence<int>^ CreateEmptySequence()
	{
		array<int>^ a = gcnew array<int>(0);
		Sequence<int>^ sequence = gcnew Sequence<int>(a, 0);
		return sequence;
	}

	void SequenceCreationTest()
	{
		Sequence<int>^ sequence = CreateSequence();

		int i = 0;
		for each (int value in sequence)
		{
			assert(value == i);
			++i;
		}
	}

	void SequenceSumTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		int result  = sequence->Reduce(sum);
		assert(result == 10);
	}

	void SequenceMaxTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		int result = sequence->Reduce(max);
		assert(result == 4);
	}

	void SequenceMinTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		int result = sequence->Reduce(min);
		assert(result == 0);
	}

	void SequenceFirstTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		int result = sequence->Reduce(first);
		assert(result == 0);
	}

	void SequenceLastTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		int result = sequence->Reduce(last);
		assert(result == 4);
	}

	void SequenceIncrementTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		sequence->Map(increment);
		int i = 0;
		for each (int value in sequence)
		{
			assert(value == i + 1);
			++i;
		}
	}

	void SequenceDecrementTest()
	{
		Sequence<int>^ sequence = CreateSequence();
		sequence->Map(decrement);
		int i = 0;
		for each (int value in sequence)
		{
			assert(value == i - 1);
			++i;
		}
	}

	void FirstOrDefaultTest()
	{
		Sequence<int>^ sequence = CreateEmptySequence();
		assert(sequence->Reduce(firstOrDefault) == NULL);
	}

	void LastOrDefaultTest()
	{
		Sequence<int>^ sequence = CreateEmptySequence();
		assert(sequence->Reduce(lastOrDefault) == NULL);
	}*/

	void RunSequenceTests()
	{
		/*SequenceCreationTest();
		SequenceSumTest();
		SequenceMaxTest();
		SequenceMinTest();
		SequenceFirstTest();
		SequenceLastTest();
		SequenceIncrementTest();
		SequenceDecrementTest();
		FirstOrDefaultTest();
		LastOrDefaultTest();
		FloatSequenceCreationTest();*/
	}
}