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

        ArraySequence<Element<T>>^ GetArraySequence()
        {
            return arraySequence;
        }

        Element<T>^ Find(int priority)
        {
            return Find(priority, 0);
        }

        void Remove(int priority)
        {
            int index = FindIndex(priority);
            if (index == -1)
            {
                return;
            }

            arraySequence->Remove(index);
            Heapify();
        }

        PriorityQueue<T>^ GetSubQueue(Element<T>^ e)
        {
            int index = FindIndex(e->Priority);
            if (index == -1)
            {
                return nullptr;
            }

            PriorityQueue<T>^ newQueue = gcnew PriorityQueue<T>();
            return GetSubQueue(index, newQueue);
        }

        void PreOrderLeftRight(int i, void (*func)(T value))
        {
            if (this == nullptr)
            {
                return;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            func(*(Get(i)->Value));
            PreOrderLeftRight(left, func);
            PreOrderLeftRight(right, func);
        }

        void PreOrderRightLeft(int i, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            func(*(Get(i)->Value));
            PreOrderRightLeft(right, func);
            PreOrderRightLeft(left, func);
        }

        void InOrderLeftRight(int i, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            InOrderLeftRight(left, func);
            func(*(Get(i)->Value));
            InOrderLeftRight(right, func);
        }

        void InOrderRightLeft(int i, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            InOrderRightLeft(right, func);
            func(*(Get(i)->Value));
            InOrderRightLeft(left, func);
        }

        void PostOrderLeftRight(int i, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            PostOrderLeftRight(left, func);
            PostOrderLeftRight(right, func);
            func(*(Get(i)->Value));
        }

        void PostOrderRightLeft(int i, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            PostOrderRightLeft(right, func);
            PostOrderRightLeft(left, func);
            func(*(this[i]->Value));
        }

        String^ PreOrderLeftRight(int i, String^ result) {
            return "";
        }

        String^ PreOrderLeftRight(int i, String^ result, String ^ (*func)(T value))
        {
            if (this == nullptr)
            {
                return nullptr;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            result += ("{" + (func(Get(i)->Value)) + "}");
            result += "(";
            if (left < this->arraySequence->GetSize())
                result = PreOrderLeftRight(left, result, func);
            result += ")";
            result += "[";
            if (right < this->arraySequence->GetSize())
                result = PreOrderLeftRight(right, result, func);
            result += "]";
            return result;
        }

        String^ PreOrderRightLeft(int i, String^ result, String ^ (*func)(T value))
        {
            if (this == nullptr)
            {
                return nullptr;;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            result += ("{" + (func(Get(i)->Value)) + "}");
            result += "[";
            if (right < this->arraySequence->GetSize())
                result = PreOrderRightLeft(right, result, func);
            result += "]";
            result += "(";
            if (left < this->arraySequence->GetSize())
                result = PreOrderRightLeft(left, result, func);
            result += ")";
            return result;
        }

        String^ InOrderLeftRight(int i, String^ result, String^ (*func)(T value))
        {
            if (this == nullptr)
            {
                return nullptr;;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            result += "(";
            if (left < this->arraySequence->GetSize())
                result = InOrderLeftRight(left, result, func);
            result += ")";
            result += ("{" + (func(Get(i)->Value)) + "}");
            result += "[";
            if (right < this->arraySequence->GetSize())
                result = InOrderLeftRight(right, result, func);
            result += "]";
            return result;
        }

        String^ InOrderRightLeft(int i, String^ result, String^ (*func)(T value))
        {
            if (this == nullptr)
            {
                return nullptr;;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            result += "[";
            if (right < this->arraySequence->GetSize())
                result = InOrderRightLeft(right, result, func);
            result += "]";
            result += ("{" + (func(Get(i)->Value)) + "}");
            result += "(";
            if (left < this->arraySequence->GetSize())
                result = InOrderRightLeft(left, result, func);
            result += ")";
            return result;
        }

        String^ PostOrderLeftRight(int i, String^ result, String^ (*func)(T value))
        {
            if (this == nullptr)
            {
                return nullptr;;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            result += "(";
            if (left < this->arraySequence->GetSize())
                result = PostOrderLeftRight(left, result, func);
            result += ")";
            result += "[";
            if (right < this->arraySequence->GetSize())
                result = PostOrderLeftRight(right, result, func);
            result += "]";
            result += ("{" + (func(Get(i)->Value)) + "}");
            return result;

        }

        String^ PostOrderRightLeft(int i, String^ result, String^ (*func)(T value))
        {
            if (this == nullptr)
            {
                return nullptr;;
            }
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            result += "[";
            if (right < this->arraySequence->GetSize())
                result = PostOrderRightLeft(right, result, func);
            result += "]";
            result += "(";
            if (left < this->arraySequence->GetSize())
                result = PostOrderRightLeft(left, result, func);
            result += ")";
            result += ("{" + (func(Get(i)->Value)) + "}");
            return result;
        }


    private:

        PriorityQueue<T>^ GetSubQueue(int parentIndex, PriorityQueue<T>^ newQueue)
        {
            if (parentIndex >= arraySequence->GetSize())
            {
                return newQueue;
            }

            int i = parentIndex;

            newQueue->Insert(arraySequence->Get(i));
            
            int left = 2 * i + 1;
            newQueue = GetSubQueue(left, newQueue);

            int right = 2 * i + 2;
            newQueue = GetSubQueue(right, newQueue);

            return newQueue;
        }

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
        }

        Element<T>^ Find(int priority, int parentIndex)
        {
            if (parentIndex >= arraySequence->GetSize())
            {
                return nullptr;
            }

            int i = parentIndex;

            int currentPriority = arraySequence->Get(i)->Priority;

            if (currentPriority > priority)
            {
                return nullptr;
            }

            if (currentPriority == priority)
            {
                return arraySequence->Get(i);
            }

            Element<T>^ result;
            int left = 2 * i + 1;
            result = Find(priority, left);
            if (result != nullptr)
            {
                return result;
            }

            int right = 2 * i + 2;
            result = Find(priority, right);
            if (result != nullptr)
            {
                return result;
            }

            return nullptr;
        }

        int FindIndex(int priority)
        {
            return FindIndex(priority, 0);
        }

        int FindIndex(int priority, int parentIndex)
        {
            int i = parentIndex;

            if (i < 0 || i >= arraySequence->GetSize())
            {
                return -1;
            }

            int currentPriority = arraySequence->Get(i)->Priority;

            if (currentPriority > priority)
            {
                return -1;
            }

            if (currentPriority == priority)
            {
                return i;
            }

            int result;
            int left = 2 * i + 1;
            result = FindIndex(priority, left);
            if (result != -1)
            {
                return result;
            }

            int right = 2 * i + 2;
            result = FindIndex(priority, right);
            if (result != -1)
            {
                return result;
            }

            return -1;
        }
    };
}