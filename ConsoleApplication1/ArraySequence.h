#include <iostream>

using namespace System::Collections;
using namespace Lab;

namespace Lab
{
    template<class T>
    public ref class ArraySequence : Sequence<T>, System::Collections::IEnumerable
    {
    public:
        DynamicArray<T>^ dynamicArray;

    public:
        ArraySequence()
        {
            dynamicArray = gcnew DynamicArray<T>();
        }

        ArraySequence(int count)
        {
            dynamicArray = gcnew DynamicArray<T>(count);
        }

        /*ArraySequence(array<T^>^ items, int count)
        {
            dynamicArray = gcnew DynamicArray<T>(items, count);
        }

        ArraySequence(T^ items, int count)
        {
            dynamicArray = gcnew DynamicArray<T>(items, count);
        }*/

        T^ Get(int index)
        {
            return dynamicArray->Get(index);
        }

        int GetSize()
        {
            return dynamicArray->Count();
        }

        T^ Reduce(T ^ (*func)(array<T^>^, int))
        {
            return dynamicArray->Reduce(func);
        }

        void Map(void (*func)(array<T^>^, int))
        {
            dynamicArray->Map(func);
        }

        T^ GetLast()
        {
            dynamicArray->GetLast();
        }

        T^ GetFirst()
        {
            return dynamicArray->GetFirst();
        }

        void Set(T^ value, int index)
        {
            dynamicArray->Set(value, index);
        }

        void Add(T^ value)
        {
            dynamicArray->Resize(GetSize() + 1);
            Set(value, GetSize() - 1);
        }

        bool Contains(T^ value, int (*comparer)(T^ value1, T^ value2))
        {
            for (int i = 0; i < GetSize(); i++)
            {
                if (comparer(Get(i), value) == 0)
                {
                    return true;
                }
            }

            return false;
        }

        void Remove(int index)
        {
            if (index < 0 || index >= GetSize())
            {
                throw gcnew IndexOutOfRangeException();
            }

            for (int i = index; i < GetSize() - 1; i++)
            {
                Set(Get(i+1), i);
            }

            dynamicArray->Resize(GetSize() - 1);
        }

        void InsertAt(Int32 index, T^ value)
        {
            if (index < 0 || index >= GetSize())
            {
                throw gcnew IndexOutOfRangeException();
            }

            dynamicArray->Resize(GetSize() + 1);

            for (int i = index + 1; i < GetSize(); i++)
            {
                Set(Get(i-1), i);
            }

            Set(value, index);
        }

        virtual System::Collections::IEnumerator^ GetEnumerator()
        {
            return gcnew CEnumerator<T>(dynamicArray->items);
        }
    };
}