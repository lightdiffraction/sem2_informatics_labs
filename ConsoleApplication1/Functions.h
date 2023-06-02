namespace Lab
{

    int f0()
    {
        return 0;
    }

    int f1()
    {
        return 1;
    }

    int f2()
    {
        return 2;
    }
    int f3()
    {
        return 3;
    }

    Single^ operator^(Single^ t1, int pow)
    {
        Single res = Math::Pow(*t1, pow);
        Single^ ptr = dynamic_cast<Single^>((Object^)res);
        return ptr;
    }

    Int32^ operator^(Int32^ t1, int pow)
    {
        Single sT1 = Convert::ToSingle(*t1);
        Single res = Math::Pow(sT1, pow);
        Int32^ ptr = dynamic_cast<Int32^>((Object^)Convert::ToInt32(res));
        return ptr;
    }

    Int32^ operator*(Int32^ t1, Int32^ t2)
    {
        Int32 res = *t1 * *t2;
        Int32^ ptr = dynamic_cast<Int32^>((Object^)res);
        return ptr;
    }

    Single^ operator*(Single^ t1, Single^ t2)
    {
        Single res = *t1 * *t2;
        Single^ ptr = dynamic_cast<Single^>((Object^)res);
        return ptr;
    }

    Int32^ operator+(Int32^ t1, Int32^ t2)
    {
        Int32 res = *t1 + *t2;
        Int32^ ptr = dynamic_cast<Int32^>((Object^)res);
        return ptr;
    }

    Single^ operator+(Single^ t1, Single^ t2)
    {
        Single res = *t1 + *t2;
        Single^ ptr = dynamic_cast<Single^>((Object^)res);
        return ptr;
    }

    template<typename T>
    T^ sum(array<T^>^ items, int count)
    {
        T result = 0;


        for (T i = 0; i < count; i++)
        {
            result += items[i];
        }
        return result;
    }

    Int32^ IntMax(array<Int32^>^ items, int count)
    {
        Int32 max = INT32_MIN;
        for (int i = 0; i < count; i++)
        {
            if (*(items[i]) > max)
            {
                max = *(items[i]);
            }
        }
        return max;
    }

    Single^ FloatMax(array<Single^>^ items, int count)
    {
        Single max = INT32_MIN;
        for (int i = 0; i < count; i++)
        {
            if (*(items[i]) > max)
            {
                max = *(items[i]);
            }
        }
        return max;
    }

    template<typename T>
    T max(array<T>^ items, int count)
    {
        T max = INT32_MIN;
        for (int i = 0; i < count; i++)
        {
            if (items[i] > max)
            {
                max = items[i];
            }
        }
        return max;
    }

    Int32^ IntMin(array<Int32^>^ items, int count)
    {
        Int32 min = INT32_MAX;
        for (int i = 0; i < count; i++)
        {
            if (*(items[i]) < min)
            {
                min = *(items[i]);
            }
        }
        return min;
    }

    Single^ FloatMin(array<Single^>^ items, int count)
    {
        Single min = INT32_MAX;
        for (int i = 0; i < count; i++)
        {
            if (*(items[i]) < min)
            {
                min = *(items[i]);
            }
        }
        return min;
    }

    template<typename T>
    T min(array<T>^ items, int count)
    {
        T min = INT32_MAX;
        for (int i = 0; i < count; i++)
        {
            if (items[i] < min)
            {
                min = items[i];
            }
        }
        return min;
    }

    template<typename T>
    T^ first(array<T^>^ items, int count)
    {
        if (count == 0)
        {
            throw gcnew InvalidOperationException();
        }
        return items[0];
    }

    template<typename T>
    T firstOrDefault(array<T>^ items, int count)
    {
        if (count == 0)
        {
            return T();
        }
        return items[0];
    }

    template<typename T>
    T last(array<T>^ items, int count)
    {
        if (count == 0)
        {
            throw gcnew InvalidOperationException();
        }
        return items[count - 1];
    }

    template<typename T>
    T lastOrDefault(array<T>^ items, int count)
    {
        if (count == 0)
        {
            return T();
        }
        return items[count - 1];
    }

    void IntIncrement(array<Int32^>^ items, int count)
    {
        for (int i = 0; i < count; i++)
        {
            (*(items[i]))++;
        }
    }

    void FloatIncrement(array<Single^>^ items, int count)
    {
        for (int i = 0; i < count; i++)
        {
            (*(items[i]))++;
        }
    }

    template<typename T>
    void increment(array<T>^ items, int count)
    {
        for (int i = 0; i < count; i++)
        {
            items[i]++;
        }
    }

    template<typename T>
    void decrement(array<T>^ items, int count)
    {
        for (int i = 0; i < count; i++)
        {
            items[i]--;
        }
    }

    bool IntEven(Int32^ item)
    {
        return *item % 2 == 0;
    }

    bool FloatPositive(Single^ item)
    {
        return *(item) > 0;
    }
}