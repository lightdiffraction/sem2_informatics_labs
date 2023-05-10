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

            for (int i =  0; i < Coefficients->GetSize(); i++)
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

        int Count()
        {
            return Coefficients->GetSize();
        }

    };
}