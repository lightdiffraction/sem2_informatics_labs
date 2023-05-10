// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


#include <iostream>
#include <string>
#include "Enumerator.h"
#include "Sequence.h"
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Functions.h"
#include "Polynomial.h"
#include "Complex.h"
#include "Person.h"
#include "Student.h"
#include "Matrix.h"
#include "GetOneFunctions.h"
#include "Readers.h"
#include "TypeWriters.h"
#include "TypeReaders.h"
#include "ArraySequenceReaders.h"
#include "ArraySequenceWriters.h"
#include "PolynomialReaders.h"
#include "PolynomialWriters.h"
#include "PriorityQueue.h"
#include "SequenceTests.h"
#include "ArraySequenceTests.h"
#include "ListSequenceTests.h"
#include "ArraySequenceProcessor.h"
#include "FloatPriorityQueueProcessor.h"
#include "IntPriorityQueueProcessor.h"
#include "ComplexPriorityQueueProcessor.h"
#include "IntPolynomialProcessor.h"
#include "FloatPolynomialProcessor.h"
#include "ComplexPolynomialProcessor.h"
#include "MatrixPolynomialProcessor.h"
#include "PolynomialProcessor.h"
#include "StringPriorityQueueProcessor.h"
#include "StudentPriorityQueueProcessor.h"
#include "PriorityQueueProcessor.h"
#include "ListSequenceReaders.h"
#include "ListSequenceWriters.h"
#include "ListSequenceProcessor.h"


using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace Lab;

namespace Lab
{
    void RunTests()
    {
        RunSequenceTests();
        ArraySequenceTests::RunArraySequenceTests();
        RunListSequenceTests();
    }
}

    //right click project name in the solution explorer "Lab3" / Properties / Configuration properties / Debugging / Command Arguments
    int main(int argc, char* argv[])
    {
        if (argc == 2 && strcmp(argv[1], "tests") == 0)
        {
            RunTests();
        }
        else
        {
            String^ elementType = ReadElementType();
            String^ sequenceType = ReadSequenceType();

            if (sequenceType == "PriorityQueue")
            {
                ProcessPriorityQueue(elementType);
            }
            else if (sequenceType == "ArraySequence")
            {
                ProcessArraySequence(elementType);
            }
            else if (sequenceType == "LinkedList")
            {
                ProcessListSequence(elementType);
            }
            else if (sequenceType == "Polynomial")
            {
                if (!(elementType == "int" || elementType == "float" || elementType == "complex" || elementType == "matrix"))
                {
                    Console::WriteLine("Polynomial sequence data type supports types: int, float, complex, matrix.");
                    exit(0);
                }
                ProcessPolynomial(elementType);
            }
        }
    }