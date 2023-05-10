#include <iostream>

using namespace System::Collections;
using namespace Lab;

namespace Lab
{
    template<class T>
    ref class Element
    {
        public:
            int Priority;
            T Value;

            void SetValue(T value)
            {
                Value = value;
            }
    };

    template<class T>
    ref class PriorityQueue
    {
    private:
        ArraySequence<Element<T>>^ arraySequence;

    public:
        PriorityQueue()
        {
            arraySequence = gcnew ArraySequence<Element<T>>();
        }
    
        void Insert(Element<T>^ element)
        {
            Insert(element, arraySequence);
        }

        Element<T>^ ExtractMinimum()
        {
            if (arraySequence->GetSize() == 0)
            {
                return nullptr;
            }

            Element<T>^ result = arraySequence->Get(0);
            arraySequence->Remove(0);
            Heapify();

            return result;
        }

        int Count()
        {
            return arraySequence->GetSize();
        }

        Element<T>^ Get(int index)
        {
            return arraySequence->Get(index);
        }

    private:
        void Insert(Element<T>^ element, ArraySequence<Element<T>>^ arraySequence)
        {
            arraySequence->Add(element);
            int i = arraySequence->GetSize() - 1;
            int parent = (i - 1) / 2;

            while (parent >= 0 && i > 0)
            {
                Element<T>^ item = arraySequence->dynamicArray->items[i];
                Element<T>^ parentItem = arraySequence->dynamicArray->items[parent];
                if (item->Priority < parentItem->Priority)
                {
                    int tempPriority = item->Priority;
                    item->Priority = parentItem->Priority;
                    parentItem->Priority = tempPriority;

                    T tempValue = item->Value;
                    item->Value = parentItem->Value;
                    parentItem->Value = tempValue;
                }
                i = (i - 1) / 2;
                parent = (i - 1) / 2;
            }
        }

        void Heapify()
        {
            ArraySequence<Element<T>>^ temp = gcnew ArraySequence<Element<T>>;

            for (int i = 0; i < arraySequence->GetSize(); i++)
            {
                Insert(arraySequence->Get(i), temp);
            }

            arraySequence = temp;
            //for (int i; i < temp->GetSize(); i++)
            //{
                //arraySequence->Set(i, temp.Get(i));
                //arraySequence[i] = result[i];
            //}
        }
    };
}