namespace Lab2
{
    template<typename T>
    T sum(array<T>^ numbers, int count)
    {
        T result = 0;
        for (T i = 0; i < count; i++)
        {
            result += numbers[i];
        }
        return result;
    }

    template<typename T>
    T max(array<T>^ numbers, int count)
    {
        T max = INT32_MIN;
        for (int i = 0; i < count; i++)
        {
            if (numbers[i] > max)
            {
                max = numbers[i];
            }
        }
        return max;
    }

    template<typename T>
    T min(array<T>^ numbers, int count)
    {
        T min = INT32_MAX;
        for (int i = 0; i < count; i++)
        {
            if (numbers[i] < min)
            {
                min = numbers[i];
            }
        }
        return min;
    }

    template<typename T>
    T first(array<T>^ numbers, int count)
    {
        if (count == 0)
        {
            throw gcnew InvalidOperationException();
        }
        return numbers[0];
    }

    template<typename T>
    T firstOrDefault(array<T>^ numbers, int count)
    {
        if (count == 0)
        {
            return T();
        }
        return numbers[0];
    }

    template<typename T>
    T last(array<T>^ numbers, int count)
    {
        if (count == 0)
        {
            throw gcnew InvalidOperationException();
        }
        return numbers[count - 1];
    }

    template<typename T>
    T lastOrDefault(array<T>^ numbers, int count)
    {
        if (count == 0)
        {
            return T();
        }
        return numbers[count - 1];
    }

    template<typename T>
    void increment(array<T>^ numbers, int count)
    {
        for (int i = 0; i < count; i++)
        {
            numbers[i]++;
        }
    }

    template<typename T>
    void decrement(array<T>^ numbers, int count)
    {
        for (int i = 0; i < count; i++)
        {
            numbers[i]--;
        }
    }
}