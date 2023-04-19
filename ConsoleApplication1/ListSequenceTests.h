#include <cassert>

using namespace Lab2;

namespace Lab2
{
	ListSequence<int>^ CreateListSequence()
	{
		int n = 5;
		array<int>^ a = gcnew array<int>(5);

		for (int i = 0; i < n; i++)
		{
			a[i] = i;
		}

		ListSequence<int>^ sequence = gcnew ListSequence<int>(a, 5);
		return sequence;
	}

	void ListSequenceCreationTest()
	{
		ListSequence<int>^ sequence = CreateListSequence();
		int i = 0;
		Item<int>^ currentItem = sequence->First;
		while (currentItem->next != nullptr)
		{
			assert(currentItem->value == i);
			++i;
			currentItem = currentItem->next;
		}
		
	}

	void ListSequenceAppendTest()
	{
		ListSequence<int>^ sequence = CreateListSequence();
		//TO DO Add method test
		sequence->Append(5);
		int i = 0;
		Item<int>^ currentItem = sequence->First;
		while (currentItem->next != nullptr)
		{
			assert(currentItem->value == i);
			++i;
			currentItem = currentItem->next;
		}
	}

	void ListSequencePrependTest()
	{
		ListSequence<int>^ sequence = CreateListSequence();
		//TO DO Prepend method test
		sequence->Prepend(-1);
		int i = -1;
		Item<int>^ currentItem = sequence->First;
		while (currentItem->next != nullptr)
		{
			assert(currentItem->value == i);
			++i;
			currentItem = currentItem->next;
		}
	}

	void RunListSequenceTests()
	{
		ListSequenceCreationTest();
		ListSequenceAppendTest();
		ListSequencePrependTest();
	}
}