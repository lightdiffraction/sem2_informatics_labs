#include <iostream>
#include "Enumerator.h"
#include "ICollection.h"

using namespace System::Collections;
using namespace Lab2;

template<class T>
public ref class Sequence : System::Collections::IEnumerable, Lab2::ICollection<T>
{

public:
    int size;
    array<T>^ numbers;

    Sequence() {}

    Sequence(array<T>^ items, int count)
    {
        numbers = gcnew array<T>(count);
        for (int i = 0; i < count; i++)
        {
            numbers[i] = items[i];
            size = count;
        }
    }

    Sequence(Sequence<T>^ sequence)
    {
        numbers = gcnew array<T>(count);
        for (int i = 0; i < count; i++)
        {
            numbers[i] = sequence->numbers[i];
            size = sequence->size;
            maxSize = size;
        }
    }

    Sequence(int count)
    {
        numbers = gcnew array<T>(count);
    }

    T GetLast()
    {
        return numbers[size - 1];
    }

    T GetFirst()
    {
        return numbers[0];
    }

    int GetSize()
    {
        return size;
    }

    T Get(int i)
    {
        if (i < size && i >= 0 && numbers[i] != NULL)
        {
            return numbers[i];
        }
        else
        {
            throw new IndexOutOfRangeException();
        }
    }

    T Reduce(T(*func)(array<T>^, int))
    {
        return func(numbers, size);
    }

    void Map(void (*func)(array<T>^, int))
    {
        func(numbers, size);
    }

    int Find(T element)
    {
        for (int i = 0; i < size; i++)
        {
            if (numbers[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    void Set(T element, int i)
    {
        if (i < size && i >= 0)
        {
            numbers[i] = element;
        }
        else
        {
            throw new IndexOutOfRangeException();
        }
    }

    virtual System::Collections::IEnumerator^ GetEnumerator()
    {
        return gcnew CEnumerator<T>(numbers);
    }

    void CopyTo(array<T>^ destination, int)
    {
        destination = gcnew array<T>(size);
        for (int i = 0; i < size; i++)
        {
            destination[i] = numbers[i];
        }
    }

    int Count()
    {
        return size;
    }
};