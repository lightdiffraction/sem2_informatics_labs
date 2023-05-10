using namespace Lab;

namespace Lab
{
    template<class T>
    void WritePolynomial(Polynomial<T>^ polynomial, void (*writer)(T^))
    {
        if (polynomial->Count() == 0)
        {
            Console::WriteLine("\Polynomial is empty");
            return;
        }

        Console::WriteLine("\Polynomial:");

        int n = polynomial->Count();
        for (int i = 0; i < n; i++)
        {
            writer(polynomial->Coefficients->Get(i));

            if (i < n - 1)
            {
                Console::Write("x");
            }

            if (i < n - 2)
            {
                int pow = n - i - 1;
                Console::Write("^{0}", pow);
            }

            if (i < n - 1)
            {
                Console::Write(" + ");
            }
        }
        Console::WriteLine();
    }

    void WriteComplexPolynomial(Polynomial<Complex>^ polynomial)
    {
        if (polynomial->Count() == 0)
        {
            Console::WriteLine("\Complex Polynomial is empty");
            return;
        }

        Console::WriteLine("\nComplex Polynomial:");

        int n = polynomial->Count();
        for (int i = 0; i < n; i++)
        {
            WriteComplexOperand(polynomial->Coefficients->Get(i));

            if (i < n - 2)
            {
                Console::Write("x");
            }

            if (i < n - 1)
            {
                int pow = n - i - 1;
                Console::Write("^{0}", pow);
            }

            if (i < n - 1)
            {
                Console::Write(" + ");
            }
        }
        Console::WriteLine();
    }
}
