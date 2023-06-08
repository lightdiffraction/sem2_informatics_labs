using namespace Lab;
using namespace System;

namespace Lab
{
    PriorityQueue<Student^>^ ReadStudentPriorityQueue()
    {
        int n = ReadElementsNumber();

        array<Student^>^ items = gcnew array<Student^>(n);
        for (int i = 0; i < n; i++)
        {
            items[i] = ReadStudent();
        }

        array<int>^ priorities = ReadPriorityQueuePriorities(n);
        PriorityQueue<Student^>^ priorityQueue = gcnew PriorityQueue<Student^>();

        for (int i = 0; i < n; i++)
        {
            Element<Student^>^ element = gcnew Element<Student^>();
            element->Value = items[i];
            element->Priority = priorities[i];
            priorityQueue->Insert(element);
        }

        return priorityQueue;
    }

    void WriteStudentPriorityQueue(PriorityQueue<Student^>^ priorityQueue)
    {
        if (priorityQueue->Count() == 0)
        {
            Console::WriteLine("\Student Priority Queue is empty");
            return;
        }
        Console::WriteLine("\Student Priority Queue:");
        int pow = 0;
        int rowNumber = 0;
        int rowElementNumber = 0;
        int rowElementNumberMax = 1;
        for (int i = 0; i < priorityQueue->Count(); i++)
        {
            WriteStudent(priorityQueue->Get(i)->Value);
            ++rowElementNumber;
            if (rowElementNumber == rowElementNumberMax)
            {
                Console::WriteLine();
                ++rowNumber;
                rowElementNumber = 0;
                rowElementNumberMax = Math::Pow(2, rowNumber);
            }
        }
        Console::WriteLine();
        Console::WriteLine();
    }

    void ProcessStudentPriorityQueue()
    {
        PriorityQueue<Student^>^ priorityQueue = ReadStudentPriorityQueue();

        WriteStudentPriorityQueue(priorityQueue);

        while (true)
        {
            Console::Write("Enter operation: insert, extract, find, remove, getsubqueue, tostring, exit: ");
            String^ operation = Console::ReadLine();

            if (operation == "insert")
            {
                Element<Student^>^ element = gcnew Element<Student^>();
                element->Value = ReadStudent();
                element->Priority = ReadPriority();
                priorityQueue->Insert(element);
                WriteStudentPriorityQueue(priorityQueue);
            }

            if (operation == "extract")
            {
                Element<Student^>^ min = priorityQueue->ExtractMinimum();
                Console::WriteLine("Min priority {0}", min->Priority);
                WriteStudentPriorityQueue(priorityQueue);
            }

            if (operation == "find")
            {
                int priority = ReadInt32Value("Enter priority to find: ");
                Element<Student^>^ result = priorityQueue->Find(priority);
                if (result == nullptr)
                {
                    Console::WriteLine("Student with this priority not found.");
                }
                else
                {
                    Console::Write("Student with this priority found: ");
                    WriteStudent(result->Value);
                }
            }

            if (operation == "remove")
            {
                int priority = ReadInt32Value("Enter priority to remove: ");
                priorityQueue->Remove(priority);
                WriteStudentPriorityQueue(priorityQueue);
            }

            if (operation == "getsubqueue")
            {
                int priority = ReadInt32Value("Enter priority of student to get sub queue of: ");
                Element<Student^>^ element = priorityQueue->Find(priority);
                if (element == nullptr)
                {
                    Console::WriteLine("Student with this priority not found.");
                }
                else
                {
                    PriorityQueue<Student^>^ newQueue = priorityQueue->GetSubQueue(element);
                    WriteStudentPriorityQueue(newQueue);
                }
            }

            if (operation == "tostring")
            {
                String^ command = ReadString("Enter order (ÊËÏ, ÊÏË, ËÊÏ, ÏÊË, ËÏÊ, ÏËÊ): ");
                String^ result = gcnew String("");
                if (command == "ÊËÏ")
                {
                    result = priorityQueue->PreOrderLeftRight(0, "", StudentToString);
                }
                if (command == "ÊÏË")
                {
                    result = priorityQueue->PreOrderRightLeft(0, "", StudentToString);
                }
                if (command == "ËÊÏ")
                {
                    result = priorityQueue->InOrderLeftRight(0, "", StudentToString);
                }
                if (command == "ÏÊË")
                {
                    result = priorityQueue->InOrderRightLeft(0, "", StudentToString);
                }
                if (command == "ËÏÊ")
                {
                    result = priorityQueue->PostOrderLeftRight(0, "", StudentToString);
                }
                if (command == "ÏËÊ")
                {
                    result = priorityQueue->PostOrderRightLeft(0, "", StudentToString);
                }
                Console::WriteLine(result);
            }

            if (operation == "exit")
            {
                return;
            }
        }
    }
}