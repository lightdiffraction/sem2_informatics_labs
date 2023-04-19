#pragma once
using namespace System;
using namespace System::Collections;

template<class T>
public ref class CEnumerator : public System::Collections::IEnumerator
{
private:
    array<T>^ items;
    int cur;

public:
    CEnumerator(array<T>^ list)
    {
        items = list;
        cur = -1;
    }

    virtual property Object^ Current
    {
        Object^ get()
        {
            try {
                return items[cur];
            }
            catch (IndexOutOfRangeException^)
            {
                Console::WriteLine("Ошибка доступа с элементу массива");
                return nullptr;
            }
        }
    }

    virtual void Reset()
    {
        cur = -1;
    }

    virtual bool MoveNext()
    {
        cur++;

        if (cur < items->Length)
            return true;
        else
            return false;
    }
};