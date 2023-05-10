#include <cassert> 

using namespace Lab;

namespace Lab
{
	ref class ArraySequenceTests
	{
		/*static ArraySequence<int^>^ CreateArraySequence()
		{
			int n = 5;
			array<int^>^ a = gcnew array<int^>(5);
			for (int i = 0; i < n; i++)
			{
				a[i] = i;
			}

			ArraySequence<int^>^ arraySequence = gcnew ArraySequence<int^>(a, 5);
			return arraySequence; 
		}

		static void ArraySequenceCreationTest()
		{
			ArraySequence<int>^ arraySequence = CreateArraySequence();

			int i = 0;
			for each (int value in arraySequence)
			{
				assert(value == i);
				++i;
			}
		}

		static void ArraySequenceAddTest()
		{
			ArraySequence<int>^ arraySequence = CreateArraySequence();
			int size = arraySequence->Count();
			arraySequence->Add(arraySequence->Count());
			int i = 0;
			for each (int value in arraySequence)
			{
				assert(value == i);
				++i;
			}
			assert(arraySequence->Count() == size + 1);
		}

		static void ArraySequenceRemoveTest()
		{
			ArraySequence<int>^ arraySequence = CreateArraySequence();
			int size = arraySequence->Count();
			arraySequence->Remove(0);
			int i = 1;
			for each (int value in arraySequence)
			{
				assert(value == i);
				++i;
			}
			assert(arraySequence->Count() == size - 1);
		}*/

	public: 
		static void RunArraySequenceTests()
		{
			//ArraySequenceCreationTest();
			//ArraySequenceAddTest();
			//ArraySequenceRemoveTest();
		}
	};
}