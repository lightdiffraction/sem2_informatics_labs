using namespace System;
using namespace Lab;

namespace Lab
{
	ref class PriorityQueueTime
	{
	private:

		static void InsertTime()
		{
			int startTime = System::Environment::TickCount;

			PriorityQueue<Int32>^ tree = gcnew PriorityQueue<Int32>();
			for (int i = 1; i <= 1000000; i++)
			{
				Random^ rand = gcnew Random();
				int value = rand->Next(0, 10000);
				Element<Int32>^ e = gcnew Element<Int32>();
				e->Value = value;
				e->Priority = value;
				tree->Insert(e);
				if (i % 10000 == 0)
				{
					int endTime = System::Environment::TickCount;
					int ticks = endTime - startTime;
					int seconds = ticks / 1000;

					Console::WriteLine("Inserted {0} elements, time: {1}", i, seconds);
				}
			}
		}

		static void FindTime(int start, int end, int step, int operations)
		{
			for (int nodes = start; nodes <= end; nodes += step)
			{
				PriorityQueue<Int32>^ tree = gcnew PriorityQueue<Int32>();
				Random^ rand = gcnew Random();
				for (int i = 1; i <= nodes; i++)
				{
					int value = rand->Next(0, 10000);
					Element<Int32>^ e = gcnew Element<Int32>();
					e->Value = value;
					e->Priority = value;
					tree->Insert(e);
				}

				Console::WriteLine("Inserted {0} elementes", nodes);

				long sum = 0;
				for (int avg = 0; avg < 10; avg++)
				{
					int startTime = System::Environment::TickCount;
					for (int j = 0; j < operations; j++)
					{
						int value = rand->Next(0, 10000);
						tree->Find(value);
					}
					int endTime = System::Environment::TickCount;
					int ticks = endTime - startTime;
					sum += ticks;
				}

				int avgTime = sum / 10;
				Console::WriteLine("Avg find element time: {0}", avgTime);
			}
		}

		static void RemoveTime(int start, int end, int step, int operations)
		{
			for (int nodes = start; nodes <= end; nodes += step)
			{
				PriorityQueue<Int32>^ tree = gcnew PriorityQueue<Int32>();
				Random^ rand = gcnew Random();
				for (int i = 1; i <= nodes; i++)
				{
					int value = rand->Next(0, 10000);
					Element<Int32>^ e = gcnew Element<Int32>();
					e->Value = value;
					e->Priority = value;
					tree->Insert(e);
				}

				Console::WriteLine("Inserted {0} elements", nodes);

				long sum = 0;
				for (int avg = 0; avg < 5; avg++)
				{
					int startTime = System::Environment::TickCount;
					for (int j = 0; j < operations; j++)
					{
						int value = rand->Next(0, 10000);
						tree->Remove(value);
					}
					int endTime = System::Environment::TickCount;
					int ticks = endTime - startTime;
					sum += ticks;
				}

				int avgTime = sum / 10;
				Console::WriteLine("Avg remove elements time: {0}", avgTime);
			}
		}

	public:
		static void Run()
		{
			InsertTime();
			//FindTime(10000, 100000, 5000, 1000);
			//RemoveTime(10000, 100000, 5000, 1);
		}
	};
}