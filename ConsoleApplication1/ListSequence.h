#include <iostream>

using namespace System::Collections;
using namespace Lab2;

template<class T>
ref class Item
{
    public:
        T value;
        Item^ next;
        Item()
        {
            value = NULL;
            next = nullptr;
    }
};

template<class T>
ref class ListSequence
{
public:
    Item<T>^ First;

    ListSequence(Sequence<T> sequence)
    {
        Item^ nextItem;
        Item^ item;
        for (int i = sequence.GetSize() - 1; i >= 0; i--)
        {
            item->value = sequence.numbers[i];
            if (i != sequence.GetSize() - 1)
            {
                item->next = nextItem;
            }
            else
            {
                item->next = NULL;
            }
            if (i == 0)
            {
                First = item;
            }
            nextItem = item;
        }

    };

    ListSequence()
    {
        First = NULL;
    }

    ListSequence(array<T>^ items, int count)
    {
        Item<T>^ nextItem;
        Item<T>^ item;
        for (int i = count - 1; i >= 0; i--)
        {
            item = gcnew Item<T>();
            item->value = items[i];
            if (i != count - 1)
            {
                item->next = nextItem;
            }
            else
            {
                item->next = nullptr;
            }
            if (i == 0)
            {
                First = item;
            }
            nextItem = item;
        }

    }

    ListSequence(const ListSequence <T>^ list)
    {
        new ListSequence<T> result;
        Item* currentItem = list.First;
        Item firstItem;
        firstItem.value = currentItem->value;
        firstItem.next = currentItem->next;
        Item* prevItem;
        prevItem = &currentItem;
        while (currentItem->next != NULL)
        {
            currentItem = currentItem->next;
            Item newItem;
            newItem.value = currentItem->value;
            prevItem.next = currentItem;
        };
        result.First = firstItem;
        return result;
    }

    ListSequence<T>^ Concat(ListSequence<T>^ list)
    {
        new ListSequence<T> result;
        Item* currentItem = First;
        Item firstItem;
        firstItem.value = currentItem->value;
        firstItem.next = currentItem->next;
        Item* prevItem;
        prevItem = currentItem;
        while (currentItem->next != NULL)
        {
            currentItem = currentItem->next;
            Item newItem;
            newItem.value = currentItem->value;
            prevItem->next = newItem;
        };
        result.First = firstItem;
        currentItem = list.First;
        firstItem.value = currentItem->value;
        firstItem.next = currentItem->next;
        prevItem->next = firstItem;
        while (currentItem->next != NULL)
        {
            currentItem = currentItem->next;
            Item newItem;
            newItem.value = currentItem->value;
            prevItem.next = newItem;
        };
        return result;
    }


    void Prepend(T value)
    {
        Item<T>^ item = gcnew Item<T>();
        item->value = value;
        item->next = First;
        First = item;
    };

    void Append(T value)
    {
        Item<T>^ item = gcnew Item<T>();
        item->value = value;
        item->next = nullptr;
        Item<T>^ currentItem = First;
        while (currentItem->next != nullptr)
        {
            currentItem = currentItem->next;
        };
        currentItem->next = item;
    };

    T GetFirst()
    {
        if (First == NULL)
        {
            throw new IndexOutOfRangeException();
        }
        return ^ First;
    }

    T GetLast()
    {
        if (First == NULL)
        {
            throw new IndexOutOfRangeException();
        }
        Item* currentItem = First;
        while (currentItem->next != NULL)
        {
            currentItem = currentItem->next;
        };
        return ^ currentItem;
    }

    T Get(int index)
    {
        Item* currentItem = First;
        int i = 1;
        while (i < index)
        {
            currentItem = currentItem->next;
            i++;
            if (currentItem.next == NULL)
            {
                throw new IndexOutOfRangeException();
            }
        };
        return ^ currentItem;

    }

    void InsertAt(T value, int index)
    {
        if (index == 0)
        {
            Prepend(value);
            return;
        }
        Item item;
        item.value = value;
        Item* currentItem = First;
        int i = 1;
        while (i < index)
        {
            currentItem = currentItem->next;
            i++;
            if (currentItem.next == NULL)
            {
                throw new IndexOutOfRangeException();
            }
        };
        item.next->currentItem->next;
        currentItem->next = &item;

    }
};