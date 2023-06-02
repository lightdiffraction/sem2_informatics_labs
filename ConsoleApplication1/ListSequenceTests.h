#include <cassert>

using namespace Lab;

namespace Lab
{
	ref class ListSequenceTests
	{
		static ListSequence<int>^ CreateListSequence()
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

		static void ListSequenceCreationTest()
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

		static void ListSequenceAppendTest()
		{
			ListSequence<int>^ sequence = CreateListSequence();
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

		static void ListSequencePrependTest()
		{
			ListSequence<int>^ sequence = CreateListSequence();
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

	public:

		static void Run()
		{
			ListSequenceCreationTest();
			ListSequenceAppendTest();
			ListSequencePrependTest();
		}
	};
}