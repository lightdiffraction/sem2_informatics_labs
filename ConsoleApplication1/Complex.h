using namespace Lab;

namespace Lab
{
    ref class Complex
    {
    public:
        Single^ Real;
        Single^ Imaginary;

        Complex()
        {
            Single real = 0;
            Single imaginary = 0;
            Real = dynamic_cast<Single^>((Object^)real);
            Imaginary = dynamic_cast<Single^>((Object^)imaginary);
        }

        Complex(Int32 param)
        {
        }

        Complex(const Complex^ complex)
        {
            Real = complex->Real;
            Imaginary = complex->Imaginary;
        }

        Complex^ operator+(Complex^ obj)
        {
            Complex^ res = gcnew Complex();
            res->Real = *Real + *(obj->Real);
            res->Imaginary = *Imaginary + *(obj->Imaginary);
            return res;
        }

        Complex^ operator=(Complex^ obj)
        {
            Complex^ res = gcnew Complex();
            res->Real = *Real;
            res->Imaginary = *Imaginary;
            return res;
        }

        Complex^ operator*(Complex^ obj)
        {
            Complex^ res = gcnew Complex();
            res->Real = (*Real) * (*(obj->Real)) - (*Imaginary) * (*(obj->Imaginary));
            res->Imaginary = (*Real) * (*(obj->Imaginary)) + (*Imaginary) * (*(obj->Real));
            return res;
        };



        Complex^ operator^(int k)
        {
            Complex^ res = gcnew Complex();
            Single real = 1;
            Single imaginary = 0;
            res->Real = dynamic_cast<Single^>((Object^)real);
            res->Imaginary = dynamic_cast<Single^>((Object^)imaginary);
            for (int i = 0; i < k; i++)
            {
                res = res * this;
            }
            return res;
        };

        Complex^ operator*(Single^ val)
        {
            Complex^ res = gcnew Complex();
            res->Real = (*Real) * *val;
            res->Imaginary = (*Imaginary) * *val;
            return res;
        };

        Complex^ operator*(Int32^ val)
        {
            Complex^ res = gcnew Complex();
            res->Real = (*Real) * *val;
            res->Imaginary = (*Imaginary) * *val;
            return res;
        };
    };
}