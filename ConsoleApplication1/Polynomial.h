using namespace Lab;

namespace Lab
{
    template<class T>
    ref class Polynomial
    {
    private:
        Int32 param;
        bool isParam;

    public:
        ArraySequence<T>^ Coefficients;

        Polynomial()
        {
            Coefficients = gcnew ArraySequence<T>();
        }

        Polynomial(ArraySequence<T>^ coefficients)
        {
            Coefficients = coefficients;
        }

        void SetParam(Int32 value)
        {
            param = value;
            isParam = true;
        }

        T^ Value(T^ x)
        {
            T^ result;

            if (isParam)
            {
                result = gcnew T(param);
            }
            else
            {
                result = gcnew T();
            }

            for (int i = 0; i < Coefficients->GetSize(); i++)
            {
                T^ coeff;

                if (isParam)
                {
                    coeff = gcnew T(param);
                }
                else
                {
                    coeff = gcnew T();
                }

                coeff = (Coefficients->Get(Coefficients->GetSize() - i - 1));
                T^ powResult = x ^ i;
                T^ multResult = coeff * powResult;
                result = result + multResult;
            }

            return result;
        }

        Polynomial^ operator*(Polynomial^ obj)
        {
            Polynomial^ polynomial = gcnew Polynomial();
            int size = Coefficients->GetSize() + obj->Coefficients->GetSize() - 1;  
            for (int q = 0; q < size; q++)
            {
                T^ res;
                if (isParam)
                {
                    res = gcnew T(param);
                }

                else
                {   
                    res = gcnew T();
                }

                for (int i = 0; i < Coefficients->GetSize(); i++)
                {
                    for (int j = 0; j < obj->Coefficients->GetSize(); j++)
                    {
                        if (Coefficients->GetSize() - i - 1 + obj->Coefficients->GetSize() - j - 1 == size - q - 1)
                        {
                            res = res + Coefficients->Get(i) * obj->Coefficients->Get(j);
                        }
                    }
                }
                polynomial->Coefficients->Add(res);
            }
            return polynomial;
        }

        Polynomial^ operator+(Polynomial^ obj)
        {
            Polynomial^ polynomial = gcnew Polynomial();
            int size = std::max(Coefficients->GetSize(), obj->Coefficients->GetSize());
            int m1 = size - Coefficients->GetSize();
            int m2 = size - obj->Coefficients->GetSize();
            for (int q = 0; q < size; q++)
            {
                T^ res;
                if (isParam)
                {
                    res = gcnew T(param);
                }

                else
                {
                    res = gcnew T();
                }

                if ((q - m1) < Coefficients->GetSize() && (q - m1) >= 0)
                {
                    res = res + Coefficients->Get(q - m1);
                }

                if ((q - m2) < obj->Coefficients->GetSize() && (q - m2) >= 0)
                {
                    res = res + obj->Coefficients->Get(q - m2);
                }

                polynomial->Coefficients->Add(res);
            }
            return polynomial;
        }

        Polynomial^ operator*(T^ obj)
        {
            Polynomial^ polynomial = gcnew Polynomial();
            int size = Coefficients->GetSize();
            for (int q = 0; q < size; q++)
            {
                T^ res;
                if (isParam)
                {
                    res = gcnew T(param);
                }

                else
                {
                    res = gcnew T();
                }
                res = Coefficients->Get(q) * obj;
                polynomial->Coefficients->Add(res);
            }
            return polynomial;
        }

        Polynomial^ operator/(Int32^ obj)
        {
            Polynomial^ polynomial = gcnew Polynomial();
            int size = Coefficients->GetSize();
            for (int q = 0; q < size; q++)
            {
                T^ res;
                if (isParam)
                {
                    res = gcnew T(param);
                }

                else
                {
                    res = gcnew T();
                }
                res = Coefficients->Get(q) * obj;
                polynomial->Coefficients->Add(res);
            }
            return polynomial;
        }


        int Count()
        {
            return Coefficients->GetSize();
        }

    };
}