namespace Lab
{
    int IntComparer(Int32^ value1, Int32^ value2)
    {
        if (*value1 == *value2)
        {
            return 0;
        }

        if (*value1 > *value2)
        {
            return 1;
        }

        return -1;
    }

    int SingleComparer(Single^ value1, Single^ value2)
    {
        if (*value1 == *value2)
        {
            return 0;
        }

        if (*value1 > *value2)
        {
            return 1;
        }

        return -1;
    }
}