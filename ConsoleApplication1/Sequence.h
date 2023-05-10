#include <iostream>
#include "Enumerator.h"
#include "ICollection.h"

using namespace System::Collections;
using namespace Lab;

template<class T>
public ref class Sequence
{
public:
    Sequence() {}

    int GetSize()
    {
        return 0;
    }

    T^ Get(int i)
    {
        return T();
    }

    int Find(T^ element)
    {
        return 0;
    }

    void Set(T^ element, int i)
    {
    }
};
