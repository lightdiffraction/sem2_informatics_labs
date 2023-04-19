#include <iostream>

using namespace System::Collections;
using namespace Lab2;

template<class T>
ref class ArraySequence : Sequence<T>
{

public:
    ArraySequence()
    {
    }

    ArraySequence(int count) : Sequence(count)
    {
    }

    ArraySequence(array<T>^ items, int count) : Sequence(items, count)
    {
    }

private:
    void Resize(int newSize)
    {
        array<T>^ temp = gcnew array<T>(size);
        for (int i = 0; i < size; i++)
        {
            temp[i] = numbers[i];
        }

        numbers = gcnew array<int>(newSize);
        int n = size < newSize ? size : newSize;
        for (int i = 0; i < n; i++)
        {
            numbers[i] = temp[i];
        }

        size = newSize;
    }

public:
    void Add(T value)
    {
        Resize(size + 1);
        numbers[size - 1] = value;
    }

    void Remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw gcnew IndexOutOfRangeException();
        }

        for (int i = index; i < size - 1; i++)
        {
            numbers[i] = numbers[i + 1];
        }

        Resize(size - 1);
    }

    void InsertAt(int index, T value)
    {
        if (index < 0 || index >= this.size)
        {
            throw gcnew IndexOutOfRangeException();
        }

        Resize();

        for (int i = index + 1; i < this.size; i++)
        {
            numbers[i] = numbers[i - 1];
        }

        numbers[index] = value;
        ++this.size;
    }
};