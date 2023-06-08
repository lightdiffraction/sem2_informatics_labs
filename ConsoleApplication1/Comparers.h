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

    int StringComparer(String^ value1, String^ value2)
    {
        if (value1 == value2)
        {
            return 0;
        }

        if (String::Compare(value1, value2) > 0)
        {
            return 1;
        }

        return -1;
    }

    int StudentComparer(Student^ value1, Student^ value2)
    {
        if (value1->GetLastName() == value2->GetLastName())
        {
            return 0;
        }

        if (String::Compare(value1->GetLastName(), value2->GetLastName()) > 0)
        {
            return 1;
        }

        return -1;
    }

    int ComplexComparer(Complex^ value1, Complex^ value2)
    {
        if (*(value1->Real) == *(value2->Real) && *(value1->Imaginary) == *(value2->Imaginary))
        {
            return 0;
        }

        if (*(value1->Real) > *(value2->Real) && *(value1->Imaginary) > *(value2->Imaginary)
            || *(value1->Real) == *(value2->Real) && *(value1->Imaginary) > *(value2->Imaginary))
        {
            return 1;
        }

        return -1;
    }
}