#include <iostream>

using namespace System::Collections;
using namespace Lab;

namespace Lab
{
    template<class T>
    ref class DynamicArray 
    {
    private:
        int size = 0;
    
    public:
        array<T^>^ items;

    public:
        DynamicArray()
        {
        }

        DynamicArray(int count) 
        {
            items = gcnew array<T>(count);
        }

        DynamicArray(array<T^>^ items, int count) 
        {
            items = gcnew array<T^>(count);
            for (int i = 0; i < count; i++)
            {
                items[i] = items[i];
                size = count;
            }
        }

        DynamicArray(T^ items, int count)
        {
        }

    public:
        void Resize(int newSize)
        {
            array<T^>^ temp = gcnew array<T^>(size);
            for (int i = 0; i < size; i++)
            {
                temp[i] = items[i];
            }

            items = gcnew array<T^>(newSize);
            int n = size < newSize ? size : newSize;
            for (int i = 0; i < n; i++)
            {
                items[i] = temp[i];
            }

            size = newSize;
        }

        int Count()
        {
            return size;
        }

        int Find(T^ element)
        {
            for (int i = 0; i < size; i++)
            {
                if (items[i] == element)
                {
                    return i;
                }
            }
            return -1;
        }

        void Set(T^ element, int i)
        {
            if (i < size && i >= 0)
            {
                items[i] = element;
            }
            else
            {
                throw gcnew IndexOutOfRangeException();
            }
        }

        T^ Reduce(T^(*func)(array<T^>^, int))
        {
            return func(items, size);
        }

        void Map(void (*func)(array<T^>^, int))
        {
            func(items, size);
        }

        T^ GetLast()
        {
            return items[size - 1];
        }

        T^ GetFirst()
        {
            return items[0];
        }

        T^ Get(int i)
        {
            if (i < size && i >= 0)
            {
                return items[i];
            }
            else
            {
                throw gcnew IndexOutOfRangeException();
            }
        }
    };
}