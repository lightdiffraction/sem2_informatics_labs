#include <cassert> 

using namespace Lab;

namespace Lab
{
	ref class IntPriorityQueueTests
	{
		static PriorityQueue<Int32^>^ CreatePriorityQueue()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 1;
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			Element<Int32^>^ item2 = gcnew Element<Int32^>();
			item2->Value = 2;
			item2->Priority = 2;
			priorityQueue->Insert(item2);

			Element<Int32^>^ item3 = gcnew Element<Int32^>();
			item3->Value = 3;
			item3->Priority = 1;
			priorityQueue->Insert(item3);

			return priorityQueue;
		}

		static void CreationTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = CreatePriorityQueue();
			ArraySequence<Element<Int32^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 3);
			assert(*(arraySequence->Get(1)->Value) == 1);
			assert(*(arraySequence->Get(2)->Value) == 2);

			assert(arraySequence->Get(0)->Priority, 1);
			assert(arraySequence->Get(1)->Priority, 3);
			assert(arraySequence->Get(2)->Priority, 2);
		}

		static void InsertTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 10;
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			ArraySequence<Element<Int32^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 10);
			assert(arraySequence->Get(0)->Priority == 3);
		}

		static void InsertManyTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();
			ArraySequence<Element<Int32^>>^ arraySequence;

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 10;
			item1->Priority = 100;
			priorityQueue->Insert(item1);

			arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 10);
			assert(arraySequence->Get(0)->Priority == 100);

			Element<Int32^>^ item2 = gcnew Element<Int32^>();
			item2->Value = 20;
			item2->Priority = 200;
			priorityQueue->Insert(item2);

			arraySequence = priorityQueue->GetArraySequence();

			assert((*arraySequence->Get(0)->Value) == 10);
			assert(arraySequence->Get(0)->Priority == 100);
			assert((*arraySequence->Get(1)->Value) == 20);
			assert(arraySequence->Get(1)->Priority == 200);

			Element<Int32^>^ item3 = gcnew Element<Int32^>();
			item3->Value = 30;
			item3->Priority = 300;
			priorityQueue->Insert(item3);

			arraySequence = priorityQueue->GetArraySequence();

			assert((*arraySequence->Get(0)->Value) == 10);
			assert(arraySequence->Get(0)->Priority == 100);
			assert((*arraySequence->Get(1)->Value) == 20);
			assert(arraySequence->Get(1)->Priority == 200);
			assert(*(arraySequence->Get(2)->Value) == 30);
			assert(arraySequence->Get(2)->Priority == 300);
		}

		static void ExtractTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = CreatePriorityQueue();
			Element<Int32^>^ min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 3);
			assert(min->Priority == 1);
		}

		static void ExtractManyTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = CreatePriorityQueue();
			Element<Int32^>^ min = priorityQueue->ExtractMinimum();
			assert((*min->Value) == 3);
			assert(min->Priority == 1);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 2);
			assert(min->Priority == 2);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 1);
			assert(min->Priority == 3);
		}

		static void Find1Test()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();
			ArraySequence<Element<Int32^>>^ arraySequence;

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 10;
			item1->Priority = 1;
			priorityQueue->Insert(item1);

			Element<Int32^>^ item2 = gcnew Element<Int32^>();
			item2->Value = 20;
			item2->Priority = 2;
			priorityQueue->Insert(item2);

			Element<Int32^>^ item4 = gcnew Element<Int32^>();
			item4->Value = 30;
			item4->Priority = 3;
			priorityQueue->Insert(item4);

			Element<Int32^>^ item5 = gcnew Element<Int32^>();
			item5->Value = 40;
			item5->Priority = 4;
			priorityQueue->Insert(item5);

			Element<Int32^>^ item6 = gcnew Element<Int32^>();
			item6->Value = 50;
			item6->Priority = 5;
			priorityQueue->Insert(item6);

			Element<Int32^>^ item7 = gcnew Element<Int32^>();
			item7->Value = 60;
			item7->Priority = 6;
			priorityQueue->Insert(item7);

			Element<Int32^>^ result = priorityQueue->Find(4);
			assert(*(result->Value) == 40);
			assert(result->Priority == 4);
		}

		static void Find2Test()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();
			ArraySequence<Element<Int32^>>^ arraySequence;

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 60;
			item1->Priority = 6;
			priorityQueue->Insert(item1);

			Element<Int32^>^ item2 = gcnew Element<Int32^>();
			item2->Value = 50;
			item2->Priority = 5;
			priorityQueue->Insert(item2);

			Element<Int32^>^ item4 = gcnew Element<Int32^>();
			item4->Value = 40;
			item4->Priority = 4;
			priorityQueue->Insert(item4);

			Element<Int32^>^ item5 = gcnew Element<Int32^>();
			item5->Value = 30;
			item5->Priority = 3;
			priorityQueue->Insert(item5);

			Element<Int32^>^ item6 = gcnew Element<Int32^>();
			item6->Value = 20;
			item6->Priority = 2;
			priorityQueue->Insert(item6);

			Element<Int32^>^ item7 = gcnew Element<Int32^>();
			item7->Value = 10;
			item7->Priority = 1;
			priorityQueue->Insert(item7);

			Element<Int32^>^ result = priorityQueue->Find(4);
			assert(*(result->Value) == 40);
			assert(result->Priority == 4);
		}

		static void RemoveTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();
			ArraySequence<Element<Int32^>>^ arraySequence;

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 60;
			item1->Priority = 6;
			priorityQueue->Insert(item1);

			Element<Int32^>^ item2 = gcnew Element<Int32^>();
			item2->Value = 50;
			item2->Priority = 5;
			priorityQueue->Insert(item2);

			Element<Int32^>^ item4 = gcnew Element<Int32^>();
			item4->Value = 40;
			item4->Priority = 4;
			priorityQueue->Insert(item4);

			Element<Int32^>^ item5 = gcnew Element<Int32^>();
			item5->Value = 30;
			item5->Priority = 3;
			priorityQueue->Insert(item5);

			Element<Int32^>^ item6 = gcnew Element<Int32^>();
			item6->Value = 20;
			item6->Priority = 2;
			priorityQueue->Insert(item6);

			Element<Int32^>^ item7 = gcnew Element<Int32^>();
			item7->Value = 10;
			item7->Priority = 1;
			priorityQueue->Insert(item7);

			priorityQueue->Remove(4);

			Element<Int32^>^ result = priorityQueue->Find(4);
			assert(result == nullptr);
		}

		static void GetSubQueueTest()
		{
			PriorityQueue<Int32^>^ priorityQueue = gcnew PriorityQueue<Int32^>();

			Element<Int32^>^ item1 = gcnew Element<Int32^>();
			item1->Value = 60;
			item1->Priority = 6;
			priorityQueue->Insert(item1);

			Element<Int32^>^ item2 = gcnew Element<Int32^>();
			item2->Value = 50;
			item2->Priority = 5;
			priorityQueue->Insert(item2);

			Element<Int32^>^ item4 = gcnew Element<Int32^>();
			item4->Value = 40;
			item4->Priority = 4;
			priorityQueue->Insert(item4);

			Element<Int32^>^ item5 = gcnew Element<Int32^>();
			item5->Value = 30;
			item5->Priority = 3;
			priorityQueue->Insert(item5);

			Element<Int32^>^ item6 = gcnew Element<Int32^>();
			item6->Value = 20;
			item6->Priority = 2;
			priorityQueue->Insert(item6);

			Element<Int32^>^ item7 = gcnew Element<Int32^>();
			item7->Value = 10;
			item7->Priority = 1;
			priorityQueue->Insert(item7);

			Element<Int32^>^ item = gcnew Element<Int32^>();
			item->Value = 30;
			item->Priority = 3;

			PriorityQueue<Int32^>^ subQueue = priorityQueue->GetSubQueue(item);
			ArraySequence<Element<Int32^>>^ ar = subQueue->GetArraySequence();
			assert(ar->GetSize() == 3);
			assert(*(ar->Get(0)->Value) == 30);
			assert(*(ar->Get(1)->Value) == 60);
			assert(*(ar->Get(2)->Value) == 40);

			item = gcnew Element<Int32^>();
			item->Value = 10;
			item->Priority = 1;

			subQueue = priorityQueue->GetSubQueue(item);
			ar = subQueue->GetArraySequence();
			assert(ar->GetSize() == 6);
			assert(*(ar->Get(0)->Value) == 10);
			assert(*(ar->Get(1)->Value) == 20);
			assert(*(ar->Get(2)->Value) == 50);
			assert(*(ar->Get(3)->Value) == 40);
			assert(*(ar->Get(4)->Value) == 30);
			assert(*(ar->Get(5)->Value) == 60);
		}

	public:
		static void Run()
		{
			CreationTest();
			InsertTest();
			InsertManyTest();
			ExtractTest();
			ExtractManyTest();
			Find1Test();
			Find2Test();
			RemoveTest();
			GetSubQueueTest();
		}
	};

	ref class FloatPriorityQueueTests
	{
		static PriorityQueue<Single^>^ CreatePriorityQueue()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 1.1f;
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			Element<Single^>^ item2 = gcnew Element<Single^>();
			item2->Value = 2.2f;
			item2->Priority = 2;
			priorityQueue->Insert(item2);

			Element<Single^>^ item3 = gcnew Element<Single^>();
			item3->Value = 3.3f;
			item3->Priority = 1;
			priorityQueue->Insert(item3);

			return priorityQueue;
		}

		static void CreationTest()
		{
			PriorityQueue<Single^>^ priorityQueue = CreatePriorityQueue();
			ArraySequence<Element<Single^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 3.3f);
			assert(*(arraySequence->Get(1)->Value) == 1.1f);
			assert(*(arraySequence->Get(2)->Value) == 2.2f);

			assert(arraySequence->Get(0)->Priority == 1);
			assert(arraySequence->Get(1)->Priority == 3);
			assert(arraySequence->Get(2)->Priority == 2);
		}

		static void InsertTest()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 10.1f;
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			ArraySequence<Element<Single^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 10.1f);
			assert(arraySequence->Get(0)->Priority == 3);
		}

		static void InsertManyTest()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();
			ArraySequence<Element<Single^>>^ arraySequence;

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 10.5f;
			item1->Priority = 100;
			priorityQueue->Insert(item1);

			arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 10.5f);
			assert(arraySequence->Get(0)->Priority == 100);

			Element<Single^>^ item2 = gcnew Element<Single^>();
			item2->Value = 20.5f;
			item2->Priority = 200;
			priorityQueue->Insert(item2);

			arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 10.5f);
			assert(arraySequence->Get(0)->Priority == 100);
			assert(*(arraySequence->Get(1)->Value) == 20.5f);
			assert(arraySequence->Get(1)->Priority == 200);

			Element<Single^>^ item3 = gcnew Element<Single^>();
			item3->Value = 30.5f;
			item3->Priority = 300;
			priorityQueue->Insert(item3);

			arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value) == 10.5f);
			assert(arraySequence->Get(0)->Priority == 100);
			assert(*(arraySequence->Get(1)->Value) == 20.5f);
			assert(arraySequence->Get(1)->Priority == 200);
			assert(*(arraySequence->Get(2)->Value) == 30.5f);
			assert(arraySequence->Get(2)->Priority == 300);
		}

		static void ExtractTest()
		{
			PriorityQueue<Single^>^ priorityQueue = CreatePriorityQueue();
			Element<Single^>^ min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 3.3f);
			assert(min->Priority == 1);
		}

		static void ExtractManyTest()
		{
			PriorityQueue<Single^>^ priorityQueue = CreatePriorityQueue();
			Element<Single^>^ min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 3.3f);
			assert(min->Priority == 1);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 2.2f);
			assert(min->Priority == 2);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value) == 1.1f);
			assert(min->Priority == 3);
		}

		static void Find1Test()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();
			ArraySequence<Element<Single^>>^ arraySequence;

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 10.0f;
			item1->Priority = 1;
			priorityQueue->Insert(item1);

			Element<Single^>^ item2 = gcnew Element<Single^>();
			item2->Value = 20.0f;
			item2->Priority = 2;
			priorityQueue->Insert(item2);

			Element<Single^>^ item4 = gcnew Element<Single^>();
			item4->Value = 30.0f;
			item4->Priority = 3;
			priorityQueue->Insert(item4);

			Element<Single^>^ item5 = gcnew Element<Single^>();
			item5->Value = 40.0f;
			item5->Priority = 4;
			priorityQueue->Insert(item5);

			Element<Single^>^ item6 = gcnew Element<Single^>();
			item6->Value = 50.0f;
			item6->Priority = 5;
			priorityQueue->Insert(item6);

			Element<Single^>^ item7 = gcnew Element<Single^>();
			item7->Value = 60.0f;
			item7->Priority = 6;
			priorityQueue->Insert(item7);

			Element<Single^>^ result = priorityQueue->Find(4);
			assert(*(result->Value) == 40.0);
			assert(result->Priority == 4);
		}

		static void Find2Test()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();
			ArraySequence<Element<Single^>>^ arraySequence;

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 60.0f;
			item1->Priority = 6;
			priorityQueue->Insert(item1);

			Element<Single^>^ item2 = gcnew Element<Single^>();
			item2->Value = 50.0f;
			item2->Priority = 5;
			priorityQueue->Insert(item2);

			Element<Single^>^ item4 = gcnew Element<Single^>();
			item4->Value = 40.0f;
			item4->Priority = 4;
			priorityQueue->Insert(item4);

			Element<Single^>^ item5 = gcnew Element<Single^>();
			item5->Value = 30.0f;
			item5->Priority = 3;
			priorityQueue->Insert(item5);

			Element<Single^>^ item6 = gcnew Element<Single^>();
			item6->Value = 20.0f;
			item6->Priority = 2;
			priorityQueue->Insert(item6);

			Element<Single^>^ item7 = gcnew Element<Single^>();
			item7->Value = 10.0f;
			item7->Priority = 1;
			priorityQueue->Insert(item7);

			Element<Single^>^ result = priorityQueue->Find(4);
			assert(*(result->Value) == 40.0f);
			assert(result->Priority == 4);
		}

		static void RemoveTest()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();
			ArraySequence<Element<Single^>>^ arraySequence;

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 60.0f;
			item1->Priority = 6;
			priorityQueue->Insert(item1);

			Element<Single^>^ item2 = gcnew Element<Single^>();
			item2->Value = 50.0f;
			item2->Priority = 5;
			priorityQueue->Insert(item2);

			Element<Single^>^ item4 = gcnew Element<Single^>();
			item4->Value = 40.0f;
			item4->Priority = 4;
			priorityQueue->Insert(item4);

			Element<Single^>^ item5 = gcnew Element<Single^>();
			item5->Value = 30.0f;
			item5->Priority = 3;
			priorityQueue->Insert(item5);

			Element<Single^>^ item6 = gcnew Element<Single^>();
			item6->Value = 20.0f;
			item6->Priority = 2;
			priorityQueue->Insert(item6);

			Element<Single^>^ item7 = gcnew Element<Single^>();
			item7->Value = 10.0f;
			item7->Priority = 1;
			priorityQueue->Insert(item7);

			priorityQueue->Remove(4.0);

			Element<Single^>^ result = priorityQueue->Find(4.0);
			assert(result == nullptr);
		}

		static void GetSubQueueTest()
		{
			PriorityQueue<Single^>^ priorityQueue = gcnew PriorityQueue<Single^>();

			Element<Single^>^ item1 = gcnew Element<Single^>();
			item1->Value = 60.0f;
			item1->Priority = 6;
			priorityQueue->Insert(item1);

			Element<Single^>^ item2 = gcnew Element<Single^>();
			item2->Value = 50.0f;
			item2->Priority = 5;
			priorityQueue->Insert(item2);

			Element<Single^>^ item4 = gcnew Element<Single^>();
			item4->Value = 40.0f;
			item4->Priority = 4;
			priorityQueue->Insert(item4);

			Element<Single^>^ item5 = gcnew Element<Single^>();
			item5->Value = 30.0f;
			item5->Priority = 3;
			priorityQueue->Insert(item5);

			Element<Single^>^ item6 = gcnew Element<Single^>();
			item6->Value = 20.0f;
			item6->Priority = 2;
			priorityQueue->Insert(item6);

			Element<Single^>^ item7 = gcnew Element<Single^>();
			item7->Value = 10.0f;
			item7->Priority = 1;
			priorityQueue->Insert(item7);

			Element<Single^>^ item = gcnew Element<Single^>();
			item->Value = 30.0f;
			item->Priority = 3;

			PriorityQueue<Single^>^ subQueue = priorityQueue->GetSubQueue(item);
			ArraySequence<Element<Single^>>^ ar = subQueue->GetArraySequence();
			assert(ar->GetSize() == 3);
			assert(*(ar->Get(0)->Value) == 30.0);
			assert(*(ar->Get(1)->Value) == 60.0);
			assert(*(ar->Get(2)->Value) == 40.0);

			item = gcnew Element<Single^>();
			item->Value = 10.0f;
			item->Priority = 1;

			subQueue = priorityQueue->GetSubQueue(item);
			ar = subQueue->GetArraySequence();
			assert(ar->GetSize() == 6);
			assert(*(ar->Get(0)->Value) == 10.0);
			assert(*(ar->Get(1)->Value) == 20.0);
			assert(*(ar->Get(2)->Value) == 50.0);
			assert(*(ar->Get(3)->Value) == 40.0);
			assert(*(ar->Get(4)->Value) == 30.0);
			assert(*(ar->Get(5)->Value) == 60.0);
		}

	public:
		static void Run()
		{
			CreationTest();
			InsertTest();
			InsertManyTest();
			ExtractTest();
			ExtractManyTest();
			Find1Test();
			Find2Test();
			RemoveTest();
			GetSubQueueTest();
		}
	};

	ref class ComplexPriorityQueueTests
	{
		static PriorityQueue<Complex^>^ CreatePriorityQueue()
		{
			PriorityQueue<Complex^>^ priorityQueue = gcnew PriorityQueue<Complex^>();

			Element<Complex^>^ item1 = gcnew Element<Complex^>();
			item1->Value = gcnew Complex();
			item1->Value->Real = 1.0f;
			item1->Value->Imaginary = 1.0f;
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			Element<Complex^>^ item2 = gcnew Element<Complex^>();
			item2->Value = gcnew Complex();
			item2->Value->Real = 2.0f;
			item2->Value->Imaginary = 2.0f;
			item2->Priority = 2;
			priorityQueue->Insert(item2);

			Element<Complex^>^ item3 = gcnew Element<Complex^>();
			item3->Value = gcnew Complex();
			item3->Value->Real = 3.0f;
			item3->Value->Imaginary = 3.0f;
			item3->Priority = 1;
			priorityQueue->Insert(item3);

			return priorityQueue;
		}

		static void CreationTest()
		{
			PriorityQueue<Complex^>^ priorityQueue = CreatePriorityQueue();
			ArraySequence<Element<Complex^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value->Real) == 3.0f);
			assert(*(arraySequence->Get(1)->Value->Real) == 1.0f);
			assert(*(arraySequence->Get(2)->Value->Real) == 2.0f);
			assert(*(arraySequence->Get(0)->Value->Imaginary) == 3.0f);
			assert(*(arraySequence->Get(1)->Value->Imaginary) == 1.0f);
			assert(*(arraySequence->Get(2)->Value->Imaginary) == 2.0f);

			assert(arraySequence->Get(0)->Priority, 1);
			assert(arraySequence->Get(1)->Priority, 3);
			assert(arraySequence->Get(2)->Priority, 2);
		}

		static void InsertTest()
		{
			PriorityQueue<Complex^>^ priorityQueue = gcnew PriorityQueue<Complex^>();

			Element<Complex^>^ item1 = gcnew Element<Complex^>();
			item1->Value = gcnew Complex();
			item1->Value->Real = 10.1f;
			item1->Value->Imaginary = 10.2f;
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			ArraySequence<Element<Complex^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value->Real) == 10.1f);
			assert(*(arraySequence->Get(0)->Value->Imaginary) == 10.2f);
			assert(arraySequence->Get(0)->Priority == 3);
		}

		static void InsertManyTest()
		{
			PriorityQueue<Complex^>^ priorityQueue = gcnew PriorityQueue<Complex^>();
			ArraySequence<Element<Complex^>>^ arraySequence;

			Element<Complex^>^ item1 = gcnew Element<Complex^>();
			item1->Value = gcnew Complex();
			item1->Value->Real = 10.1f;
			item1->Value->Imaginary = 10.2f;
			item1->Priority = 100;
			priorityQueue->Insert(item1);

			arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value->Real) == 10.1f);
			assert(*(arraySequence->Get(0)->Value->Imaginary) == 10.2f);
			assert(arraySequence->Get(0)->Priority == 100);

			Element<Complex^>^ item2 = gcnew Element<Complex^>();
			item2->Value = gcnew Complex();
			item2->Value->Real = 20.1f;
			item2->Value->Imaginary = 20.2f;
			item2->Priority = 200;
			priorityQueue->Insert(item2);

			arraySequence = priorityQueue->GetArraySequence();

			assert((*arraySequence->Get(0)->Value->Real) == 10.1f);
			assert((*arraySequence->Get(0)->Value->Imaginary) == 10.2f);
			assert(arraySequence->Get(0)->Priority == 100);
			assert((*arraySequence->Get(1)->Value->Real) == 20.1f);
			assert((*arraySequence->Get(1)->Value->Imaginary) == 20.2f);
			assert(arraySequence->Get(1)->Priority == 200);

			Element<Complex^>^ item3 = gcnew Element<Complex^>();
			item3->Value = gcnew Complex();
			item3->Value->Real = 30.1f;
			item3->Value->Imaginary = 30.2f;
			item3->Priority = 300;
			priorityQueue->Insert(item3);

			arraySequence = priorityQueue->GetArraySequence();

			assert((*arraySequence->Get(0)->Value->Real) == 10.1f);
			assert((*arraySequence->Get(0)->Value->Imaginary) == 10.2f);
			assert(arraySequence->Get(0)->Priority == 100.0f);
			assert((*arraySequence->Get(1)->Value->Real) == 20.1f);
			assert((*arraySequence->Get(1)->Value->Imaginary) == 20.2f);
			assert(arraySequence->Get(1)->Priority == 200.0f);
			assert(*(arraySequence->Get(2)->Value->Real) == 30.1f);
			assert(*(arraySequence->Get(2)->Value->Imaginary) == 30.2f);
			assert(arraySequence->Get(2)->Priority == 300.0f);
		}

		static void ExtractTest()
		{
			PriorityQueue<Complex^>^ priorityQueue = CreatePriorityQueue();
			Element<Complex^>^ min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->Real) == 3.0f);
			assert(*(min->Value->Imaginary) == 3.0f);
			assert(min->Priority == 1);
		}

		static void ExtractManyTest()
		{
			PriorityQueue<Complex^>^ priorityQueue = CreatePriorityQueue();
			Element<Complex^>^ min = priorityQueue->ExtractMinimum();
			assert((*min->Value->Real) == 3.0f);
			assert((*min->Value->Imaginary) == 3.0f);
			assert(min->Priority == 1);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->Real) == 2.0f);
			assert(*(min->Value->Imaginary) == 2.0f);
			assert(min->Priority == 2);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->Real) == 1.0f);
			assert(*(min->Value->Imaginary) == 1.0f);
			assert(min->Priority == 3);
		}

	public:
		static void Run()
		{
			CreationTest();
			InsertTest();
			InsertManyTest();
			ExtractTest();
			ExtractManyTest();
		}
	};

	ref class StudentPriorityQueueTests
	{
		static PriorityQueue<Student^>^ CreatePriorityQueue()
		{
			PriorityQueue<Student^>^ priorityQueue = gcnew PriorityQueue<Student^>();

			Element<Student^>^ item1 = gcnew Element<Student^>();
			item1->Value = gcnew Student();
			PersonID^ id1 = gcnew PersonID();
			id1->SetNumber(111);
			id1->SetSeries(111111);
			item1->Value->SetID(id1);
			item1->Value->SetFirstName("A1");
			item1->Value->SetMiddleName("B1");
			item1->Value->SetLastName("C1");
			item1->Value->SetDate(Convert::ToDateTime("01/01/2003"));
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			Element<Student^>^ item2 = gcnew Element<Student^>();
			item2->Value = gcnew Student();
			PersonID^ id2 = gcnew PersonID();
			id2->SetNumber(222);
			id2->SetSeries(222222);
			item2->Value->SetID(id2);
			item2->Value->SetFirstName("A2");
			item2->Value->SetMiddleName("B2");
			item2->Value->SetLastName("C2");
			item2->Value->SetDate(Convert::ToDateTime("01/01/2004"));
			item2->Priority = 2;
			priorityQueue->Insert(item2);

			Element<Student^>^ item3 = gcnew Element<Student^>();
			item3->Value = gcnew Student();
			PersonID^ id3 = gcnew PersonID();
			id3->SetNumber(333);
			id3->SetSeries(333333);
			item3->Value->SetID(id3);
			item3->Value->SetFirstName("A3");
			item3->Value->SetMiddleName("B3");
			item3->Value->SetLastName("C3");
			item3->Value->SetDate(Convert::ToDateTime("01/01/2005"));
			item3->Priority = 1;
			priorityQueue->Insert(item3);

			return priorityQueue;
		}

		static void CreationTest()
		{
			PriorityQueue<Student^>^ priorityQueue = CreatePriorityQueue();
			ArraySequence<Element<Student^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(arraySequence->Get(0)->Value->GetFirstName() == "A3");
			assert(arraySequence->Get(1)->Value->GetFirstName() == "A1");
			assert(arraySequence->Get(2)->Value->GetFirstName() == "A2");

			assert(arraySequence->Get(0)->Priority, 1);
			assert(arraySequence->Get(1)->Priority, 3);
			assert(arraySequence->Get(2)->Priority, 2);
		}

		static void InsertTest()
		{
			PriorityQueue<Student^>^ priorityQueue = gcnew PriorityQueue<Student^>();

			Element<Student^>^ item1 = gcnew Element<Student^>();
			item1->Value = gcnew Student();
			PersonID^ id1 = gcnew PersonID();
			id1->SetNumber(111);
			id1->SetSeries(222222);
			item1->Value->SetID(id1);
			item1->Value->SetFirstName("A1");
			item1->Value->SetMiddleName("B1");
			item1->Value->SetLastName("C1");
			item1->Value->SetDate(Convert::ToDateTime("01/02/2003"));
			item1->Priority = 3;
			priorityQueue->Insert(item1);

			ArraySequence<Element<Student^>>^ arraySequence = priorityQueue->GetArraySequence();

			assert(*(arraySequence->Get(0)->Value->GetID()->GetNumber()) == 111);
			assert(*(arraySequence->Get(0)->Value->GetID()->GetSeries()) == 222222);
			assert(arraySequence->Get(0)->Value->GetFirstName() == "A1");
			assert(arraySequence->Get(0)->Value->GetMiddleName() == "B1");
			assert(arraySequence->Get(0)->Value->GetLastName() == "C1");
			assert(arraySequence->Get(0)->Value->GetDate().Day == 1);
			assert(arraySequence->Get(0)->Value->GetDate().Month == 2);
			assert(arraySequence->Get(0)->Value->GetDate().Year == 2003);
			assert(arraySequence->Get(0)->Priority == 3);
		}

		static void ExtractTest()
		{
			PriorityQueue<Student^>^ priorityQueue = CreatePriorityQueue();
			Element<Student^>^ min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->GetID()->GetNumber()) == 333);
			assert(*(min->Value->GetID()->GetSeries()) == 333333);
			assert(min->Value->GetFirstName() == "A3");
			assert(min->Value->GetMiddleName() == "B3");
			assert(min->Value->GetLastName() == "C3");
			assert(min->Value->GetDate().Day == 1);
			assert(min->Value->GetDate().Month == 1);
			assert(min->Value->GetDate().Year == 2005);
			assert(min->Priority == 1);
		}

		static void ExtractManyTest()
		{
			PriorityQueue<Student^>^ priorityQueue = CreatePriorityQueue();
			Element<Student^>^ min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->GetID()->GetNumber()) == 333);
			assert(*(min->Value->GetID()->GetSeries()) == 333333);
			assert(min->Value->GetFirstName() == "A3");
			assert(min->Value->GetMiddleName() == "B3");
			assert(min->Value->GetLastName() == "C3");
			assert(min->Value->GetDate().Day == 1);
			assert(min->Value->GetDate().Month == 1);
			assert(min->Value->GetDate().Year == 2005);
			assert(min->Priority == 1);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->GetID()->GetNumber()) == 222);
			assert(*(min->Value->GetID()->GetSeries()) == 222222);
			assert(min->Value->GetFirstName() == "A2");
			assert(min->Value->GetMiddleName() == "B2");
			assert(min->Value->GetLastName() == "C2");
			assert(min->Value->GetDate().Day == 1);
			assert(min->Value->GetDate().Month == 1);
			assert(min->Value->GetDate().Year == 2004);
			assert(min->Priority == 2);

			min = priorityQueue->ExtractMinimum();
			assert(*(min->Value->GetID()->GetNumber()) == 111);
			assert(*(min->Value->GetID()->GetSeries()) == 111111);
			assert(min->Value->GetFirstName() == "A1");
			assert(min->Value->GetMiddleName() == "B1");
			assert(min->Value->GetLastName() == "C1");
			assert(min->Value->GetDate().Day == 1);
			assert(min->Value->GetDate().Month == 1);
			assert(min->Value->GetDate().Year == 2003);
			assert(min->Priority == 3);
		}

	public:
		static void Run()
		{
			CreationTest();
			InsertTest();
			ExtractTest();
			ExtractManyTest();
		}
	};

	ref class PriorityQueueTests
	{
	public:
		static void Run()
		{
			IntPriorityQueueTests::Run();
			FloatPriorityQueueTests::Run();
			ComplexPriorityQueueTests::Run();
			StudentPriorityQueueTests::Run();
		}
	};
}