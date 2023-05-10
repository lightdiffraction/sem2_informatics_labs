namespace Lab
{
    Single^ GetOne(Single^ t)
    {
        Single^ res = gcnew Single();
        *res = 1;
        return res;
    }

    Int32^ GetOne(Int32^ t)
    {
        Int32^ res = gcnew Int32();
        *res = 1;
        return res;
    }

    Complex^ GetOne(Complex^ t)
    {
        Complex^ res = gcnew Complex();
        *(res->Real) = 1;
        *(res->Imaginary) = 0;
        return res;
    }

    Single^ GetZero(Single^ t)
    {
        Single^ res = gcnew Single();
        *res = 0;
        return res;
    }

    Int32^ GetZero(Int32^ t)
    {
        Int32^ res = gcnew Int32();
        *res = 0;
        return res;
    }

    Complex^ GetZero(Complex^ t)
    {
        Complex^ res = gcnew Complex();
        *(res->Real) = 0;
        *(res->Imaginary) = 0;
        return res;
    }
}