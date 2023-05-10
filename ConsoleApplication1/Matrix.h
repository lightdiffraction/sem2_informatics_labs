#pragma once
using namespace Lab;

namespace Lab
{
    template<class T>
    ref class Matrix
    {
    public:
        array<array<T>^>^ items;

        Matrix<T>()
        {
        }

        Matrix<T>(Matrix<T>% const matrix)
        {
            items = matrix.items;
            size = matrix.size;
        }

        Matrix<T>(ArraySequence<T> arraysequence)
        {
            size = Math::Sqrt(arraySequence.GetSize());
            if (Math::Pow(size, 2) != arraySequence.GetSize())
            {
                throw gcnew Exception;
            }

            items = gcnew array<array<T>^>(size);

            for (int i = 0; i < size; i++)
            {
                items[i] = gcnew array<T>(size);

                for (int j = 0; j < size; j++)
                {
                    items[i][j] = ArraySequence[i * size + j];
                }
            }

        }

        Matrix<T>(int s)
        {
            size = s;
            items = gcnew array<array<T>^>(size);

            for (int i = 0; i < size; i++)
            {
                items[i] = gcnew array<T>(size);

                for (int j = 0; j < size; j++)
                {
                    items[i][j] = *(gcnew T());
                }
            }
        }

        Matrix<T>(int s, char param)
        {
            size = s;
            items = gcnew array<array<T>^>(size);

            for (int i = 0; i < size; i++)
            {
                items[i] = gcnew array<T>(size);

                for (int j = 0; j < size; j++)
                {
                    items[i][j] = *(gcnew T());
                    items[i][j] = *(GetZero(items[i][j]));
                }
            }
            if (param == 'I')
            {
                for (int i = 0; i < size; i++)
                {
                    items[i][i] = *(GetOne(items[i][i]));
                }
            }
        }

        Matrix<T>^ operator+(Matrix<T>^ matrix)
        {
            Matrix^ res = gcnew Matrix(size, 'I');
            res->items = gcnew array<array<T>^>(size);
            res->size = size;

            if (size != matrix->GetSize())
            {
                throw gcnew Exception;
            }

            for (int i = 0; i < size; i++)
            {
                (res->items)[i] = gcnew array<T>(size);
                for (int j = 0; j < size; j++)
                {
                    (res->items)[i][j] = *(gcnew T());
                    (res->items)[i][j] = items[i][j] + (matrix->items)[i][j];
                }
            }
            return res;
        }

        Matrix<T>^ operator*(Matrix<T>^ matrix)
        {
            if (size != matrix->GetSize())
            {
                throw gcnew Exception;
            }

            Matrix<T>^ res = gcnew Matrix(size);
            res->size = size;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    (res->items)[i][j] = *(gcnew T());
                    for (int k = 0; k < matrix->GetSize(); k++)
                    {
                        (res->items)[i][j] += items[i][k] * (matrix->items)[k][j];
                    }
                }
            }
            return res;
        }

        Matrix<T>^ operator^(int pow)
        {
            Matrix<T>^ res = gcnew Matrix<T> (size, 'I');
            res->size = size;

            for (int i = 0; i < pow; i++)
            {
                res = res * this;
            }
            return res;
        }


        int GetSize()
        {
            return size;
        }

    private:
        Int32 size;
    };
}