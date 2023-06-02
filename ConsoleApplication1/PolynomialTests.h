using namespace Lab;

namespace Lab {
	ref class IntPolynomialTests
	{
		static Polynomial<int>^ CreatePolynomial()
		{
			int n = 5;
			ArraySequence<int>^ arraySequence = gcnew ArraySequence<int>();
			for (int i = 1; i < n; i++)
			{
				arraySequence->Add(i);
			}
			Polynomial<int>^ polynomial = gcnew Polynomial<int>(arraySequence);
			return polynomial;
		}

		static void PolynomialCreationTest()
		{
			Polynomial<int>^ polynomial = CreatePolynomial();
			for (int i = 1; i < 5; i++)
			{
				int result = *(polynomial->Coefficients->Get(i - 1));
				assert(result == i);
				++i;
			}
		}

		static void PolynomialValueTest()
		{
			Polynomial<int>^ polynomial = CreatePolynomial();

			int i = 0;
			int result = *(polynomial->Value(1));
			assert(result == 10);
		}

		static void PolynomialSumTest()
		{
			Polynomial<int>^ polynomial = CreatePolynomial();
			Polynomial<int>^ operationResult = polynomial + polynomial;
			for (int i = 1; i < 5; i++)
			{
				int result = *(operationResult->Coefficients->Get(i - 1));
				assert(result == 2 * i);
				++i;
			}
		}

		static void PolynomialMultiplicationTest()
		{
			Polynomial<int>^ polynomial = CreatePolynomial();
			Polynomial<int>^ operationResult = polynomial * polynomial;
			assert(*(operationResult->Coefficients->Get(0)) == 1);
			assert(*(operationResult->Coefficients->Get(1)) == 4);
			assert(*(operationResult->Coefficients->Get(2)) == 10);
			assert(*(operationResult->Coefficients->Get(3)) == 20);
			assert(*(operationResult->Coefficients->Get(4)) == 25);
			assert(*(operationResult->Coefficients->Get(5)) == 24);
			assert(*(operationResult->Coefficients->Get(6)) == 16);
		}

		static void PolynomialScalarMultiplyTest()
		{
			Polynomial<int>^ polynomial = CreatePolynomial();
			Polynomial<int>^ operationResult = polynomial * 2;
			for (int i = 1; i < 5; i++)
			{
				int result = *(operationResult->Coefficients->Get(i - 1));
				assert(result == 2 * i);
				++i;
			}
		}

	public:
		static void Run()
		{
			PolynomialCreationTest();
			PolynomialValueTest();
			PolynomialSumTest();
			PolynomialMultiplicationTest();
			PolynomialScalarMultiplyTest();
		}
	};
	//емае
	ref class FloatPolynomialTests
	{
		static Polynomial<Single>^ CreatePolynomial()
		{
			Single n = 5;
			ArraySequence<Single>^ arraySequence = gcnew ArraySequence<Single>();
			arraySequence->Add(1.1f);
			arraySequence->Add(2.2f);
			arraySequence->Add(3.3f);
			arraySequence->Add(4.4f);
			Polynomial<Single>^ polynomial = gcnew Polynomial<Single>(arraySequence);
			return polynomial;
		}

		static void PolynomialCreationTest()
		{
			Polynomial<Single>^ polynomial = CreatePolynomial();
			assert(*(polynomial->Coefficients->Get(0)) == 1.1f);
			assert(*(polynomial->Coefficients->Get(1)) == 2.2f);
			assert(*(polynomial->Coefficients->Get(2)) == 3.3f);
			assert(*(polynomial->Coefficients->Get(3)) == 4.4f);
		}

		static void PolynomialValueTest()
		{
			Polynomial<Single>^ polynomial = CreatePolynomial();

			int i = 0;
			int result = *(polynomial->Value(1.0f));
			assert(result == 11);
		}

		static void PolynomialSumTest()
		{
			Polynomial<Single>^ polynomial = CreatePolynomial();
			Polynomial<Single>^ operationResult = polynomial + polynomial;
			assert(*(operationResult->Coefficients->Get(0)) == 2.2f);
			assert(*(operationResult->Coefficients->Get(1)) == 4.4f);
			assert(*(operationResult->Coefficients->Get(2)) == 6.6f);
			assert(*(operationResult->Coefficients->Get(3)) == 8.8f);
		}

		static void PolynomialMultiplicationTest()
		{
			Polynomial<Single>^ polynomial = CreatePolynomial();
			Polynomial<Single>^ operationResult = polynomial * polynomial;
			assert(*(operationResult->Coefficients->Get(0)) == 1.21f);
			assert(*(operationResult->Coefficients->Get(1)) == 4.84f);
			assert(*(operationResult->Coefficients->Get(2)) == 12.1f);
			assert(*(operationResult->Coefficients->Get(3)) == 24.2f);
			assert(*(operationResult->Coefficients->Get(4)) == 30.25f);
			assert(*(operationResult->Coefficients->Get(5)) == 29.04f);
			assert(*(operationResult->Coefficients->Get(6)) == 19.36f);
		}

		static void PolynomialScalarMultiplyTest()
		{
			Polynomial<Single>^ polynomial = CreatePolynomial();
			Polynomial<Single>^ operationResult = polynomial * 2.0f;
			assert(*(operationResult->Coefficients->Get(0)) == 2.2f);
			assert(*(operationResult->Coefficients->Get(1)) == 4.4f);
			assert(*(operationResult->Coefficients->Get(2)) == 6.6f);
			assert(*(operationResult->Coefficients->Get(3)) == 8.8f);
		}

	public:
		static void Run()
		{
			PolynomialCreationTest();
			PolynomialValueTest();
			PolynomialSumTest();
			PolynomialMultiplicationTest();
			PolynomialScalarMultiplyTest();
		}
	};

	ref class ComplexPolynomialTests
	{
		static Polynomial<Complex>^ CreatePolynomial()
		{
			ArraySequence<Complex>^ arraySequence = gcnew ArraySequence<Complex>();

			Complex^ value1 = gcnew Complex();
			value1->Real = 1.1f;
			value1->Imaginary = 1.2f;
			arraySequence->Add(value1);

			Complex^ value2 = gcnew Complex();
			value2->Real = 2.1f;
			value2->Imaginary = 2.2f;
			arraySequence->Add(value2);

			Complex^ value3 = gcnew Complex();
			value3->Real = 3.1f;
			value3->Imaginary = 3.2f;
			arraySequence->Add(value3);

			Complex^ value4 = gcnew Complex();
			value4->Real = 4.1f;
			value4->Imaginary = 4.2f;
			arraySequence->Add(value4);

			Complex^ value5 = gcnew Complex();
			value5->Real = 5.1f;
			value5->Imaginary = 5.2f;
			arraySequence->Add(value5);

			Polynomial<Complex>^ polynomial = gcnew Polynomial<Complex>(arraySequence);
			return polynomial;
		}

		static void PolynomialCreationTest()
		{
			ArraySequence<Complex>^ arraySequence = gcnew ArraySequence<Complex>();

			Complex^ value1 = gcnew Complex();
			value1->Real = 1.1f;
			value1->Imaginary = 1.2f;
			arraySequence->Add(value1);

			Complex^ value2 = gcnew Complex();
			value2->Real = 2.1f;
			value2->Imaginary = 2.2f;
			arraySequence->Add(value2);

			Complex^ value3 = gcnew Complex();
			value3->Real = 3.1f;
			value3->Imaginary = 3.2f;
			arraySequence->Add(value3);

			Complex^ value4 = gcnew Complex();
			value4->Real = 4.1f;
			value4->Imaginary = 4.2f;
			arraySequence->Add(value4);

			Complex^ value5 = gcnew Complex();
			value5->Real = 5.1f;
			value5->Imaginary = 5.2f;
			arraySequence->Add(value5);

			Polynomial<Complex>^ polynomial = gcnew Polynomial<Complex>(arraySequence);

			assert(*(polynomial->Coefficients->Get(0)->Real) == 1.1f);
			assert(*(polynomial->Coefficients->Get(0)->Imaginary) == 1.2f);
			assert(*(polynomial->Coefficients->Get(1)->Real) == 2.1f);
			assert(*(polynomial->Coefficients->Get(1)->Imaginary) == 2.2f);
			assert(*(polynomial->Coefficients->Get(2)->Real) == 3.1f);
			assert(*(polynomial->Coefficients->Get(2)->Imaginary) == 3.2f);
			assert(*(polynomial->Coefficients->Get(3)->Real) == 4.1f);
			assert(*(polynomial->Coefficients->Get(3)->Imaginary) == 4.2f);
			assert(*(polynomial->Coefficients->Get(4)->Real) == 5.1f);
			assert(*(polynomial->Coefficients->Get(4)->Imaginary) == 5.2f);
		}

		static void PolynomialValueTest()
		{
			Polynomial<Complex>^ polynomial = CreatePolynomial();

			Complex^ x = gcnew Complex();
			x->Real = 1.0f;
			x->Imaginary = 1.0f;
			Complex^ result = polynomial->Value(x);
			assert(*(result->Real) == -14.4f);
			assert(Math::Round(*(result->Imaginary), 2) == 14.7);
		}

		static void PolynomialSumTest()
		{
			Polynomial<Complex>^ polynomial = CreatePolynomial();
			Polynomial<Complex>^ operationResult = polynomial + polynomial;
			
			assert(*(operationResult->Coefficients->Get(0)->Real) == 2.2f);
			assert(*(operationResult->Coefficients->Get(0)->Imaginary) == 2.4f);
			assert(*(operationResult->Coefficients->Get(1)->Real) == 4.2f);
			assert(*(operationResult->Coefficients->Get(1)->Imaginary) == 4.4f);
			assert(*(operationResult->Coefficients->Get(2)->Real) == 6.2f);
			assert(*(operationResult->Coefficients->Get(2)->Imaginary) == 6.4f);
			assert(*(operationResult->Coefficients->Get(3)->Real) == 8.2f);
			assert(*(operationResult->Coefficients->Get(3)->Imaginary) == 8.4f);
			assert(*(operationResult->Coefficients->Get(4)->Real) == 10.2f);
			assert(*(operationResult->Coefficients->Get(4)->Imaginary) == 10.4f);
		}

		static void PolynomialMultiplicationTest()
		{
			Polynomial<Complex>^ polynomial = CreatePolynomial();
			Polynomial<Complex>^ operationResult = polynomial * polynomial;

			assert(Math::Round(*(operationResult->Coefficients->Get(0)->Real), 2) == -0.23);
			assert(Math::Round(*(operationResult->Coefficients->Get(0)->Imaginary), 2) == 2.64);
			assert(Math::Round(*(operationResult->Coefficients->Get(1)->Real), 2) == -0.66);
			assert(Math::Round(*(operationResult->Coefficients->Get(1)->Imaginary), 2) == 9.88);
			assert(Math::Round(*(operationResult->Coefficients->Get(2)->Real), 2) == -1.29);
			assert(Math::Round(*(operationResult->Coefficients->Get(2)->Imaginary), 2) == 23.72);
			assert(Math::Round(*(operationResult->Coefficients->Get(3)->Real), 2) == -2.12);
			assert(Math::Round(*(operationResult->Coefficients->Get(3)->Imaginary), 2) == 46.16);
			assert(Math::Round(*(operationResult->Coefficients->Get(4)->Real), 2) == -3.15);
			assert(Math::Round(*(operationResult->Coefficients->Get(4)->Imaginary), 2) == 79.2);
			assert(Math::Round(*(operationResult->Coefficients->Get(5)->Real), 2) == -2.92);
			assert(Math::Round(*(operationResult->Coefficients->Get(5)->Imaginary), 2) == 96.56);
			assert(Math::Round(*(operationResult->Coefficients->Get(6)->Real), 2) == -2.49);
			assert(Math::Round(*(operationResult->Coefficients->Get(6)->Imaginary), 2) == 99.32);
			assert(Math::Round(*(operationResult->Coefficients->Get(7)->Real), 2) == -1.86);
			assert(Math::Round(*(operationResult->Coefficients->Get(7)->Imaginary), 2) == 85.48);
			assert(Math::Round(*(operationResult->Coefficients->Get(8)->Real), 2) == -1.03);
			assert(Math::Round(*(operationResult->Coefficients->Get(8)->Imaginary), 2) == 53.04);
		}

		static void PolynomialScalarMultiplyTest()
		{
			Polynomial<Complex>^ polynomial = CreatePolynomial();
			Complex^ scalar = gcnew Complex();
			scalar->Real = 2.0f;
			scalar->Imaginary = 3.0f;

			Polynomial<Complex>^ operationResult = polynomial * scalar;

			assert(Math::Round(*(operationResult->Coefficients->Get(0)->Real), 2) == -1.4);
			assert(Math::Round(*(operationResult->Coefficients->Get(0)->Imaginary), 2) == 5.7);
			assert(Math::Round(*(operationResult->Coefficients->Get(1)->Real), 2) == -2.4);
			assert(Math::Round(*(operationResult->Coefficients->Get(1)->Imaginary), 2) == 10.7);
			assert(Math::Round(*(operationResult->Coefficients->Get(2)->Real), 2) == -3.4);
			assert(Math::Round(*(operationResult->Coefficients->Get(2)->Imaginary), 2) == 15.7);
			assert(Math::Round(*(operationResult->Coefficients->Get(3)->Real), 2) == -4.4);
			assert(Math::Round(*(operationResult->Coefficients->Get(3)->Imaginary), 2) == 20.7);
			assert(Math::Round(*(operationResult->Coefficients->Get(4)->Real), 2) == -5.4);
			assert(Math::Round(*(operationResult->Coefficients->Get(4)->Imaginary), 2) == 25.7);
			
		}

	public:
		static void Run()
		{
			PolynomialCreationTest();
			PolynomialValueTest();
			PolynomialSumTest();
			PolynomialMultiplicationTest();
			PolynomialScalarMultiplyTest();
		}
	};

	ref class MatrixPolynomialTests
	{
		static Polynomial<Matrix<int>>^ CreatePolynomial()
		{
			int n = 5;
			ArraySequence<Matrix<int>>^ arraySequence = gcnew ArraySequence<Matrix<int>>();
			Matrix<int>^ matrix = gcnew Matrix<int>(2);
			matrix->items[0][0] = 0;
			matrix->items[0][1] = 1;
			matrix->items[1][0] = 2;
			matrix->items[1][1] = 3;
			
			Polynomial<Matrix<int>>^ polynomial = gcnew Polynomial<Matrix<int>>();

			polynomial->Coefficients->Add(matrix);

			polynomial->Coefficients->Add(matrix);

			polynomial->SetParam(2);

			return polynomial;
		}

		static void PolynomialCreationTest()
		{
			Polynomial<Matrix<int>>^ polynomial = CreatePolynomial();
			assert(polynomial->Coefficients->Get(0)->items[0][0] == 0);
			assert(polynomial->Coefficients->Get(0)->items[0][1] == 1);
			assert(polynomial->Coefficients->Get(0)->items[1][0] == 2);
			assert(polynomial->Coefficients->Get(0)->items[1][1] == 3);

			assert(polynomial->Coefficients->Get(1)->items[0][0] == 0);
			assert(polynomial->Coefficients->Get(1)->items[0][1] == 1);
			assert(polynomial->Coefficients->Get(1)->items[1][0] == 2);
			assert(polynomial->Coefficients->Get(1)->items[1][1] == 3);
		}

		static void PolynomialValueTest()
		{
			Polynomial<Matrix<int>>^ polynomial = CreatePolynomial();
			Matrix<int>^ matrix = gcnew Matrix<int>(2);
			matrix->items[0][0] = 0;
			matrix->items[0][1] = 1;
			matrix->items[1][0] = 2;
			matrix->items[1][1] = 3;

			Matrix<int>^ result = polynomial->Value(matrix);

			assert(result->items[0][0] == 2);
			assert(result->items[0][1] == 4);
			assert(result->items[1][0] == 8);
			assert(result->items[1][1] == 14);
		}

		static void PolynomialSumTest()
		{
			Polynomial<Matrix<int>>^ polynomial = CreatePolynomial();
			Polynomial<Matrix<int>>^ operationResult = polynomial + polynomial;
			assert(operationResult->Coefficients->Get(0)->items[0][0] == 0);
			assert(operationResult->Coefficients->Get(0)->items[0][1] == 2);
			assert(operationResult->Coefficients->Get(0)->items[1][0] == 4);
			assert(operationResult->Coefficients->Get(0)->items[1][1] == 6);

			assert(operationResult->Coefficients->Get(1)->items[0][0] == 0);
			assert(operationResult->Coefficients->Get(1)->items[0][1] == 2);
			assert(operationResult->Coefficients->Get(1)->items[1][0] == 4);
			assert(operationResult->Coefficients->Get(1)->items[1][1] == 6);
		}

		static void PolynomialMultiplicationTest()
		{
			Polynomial<Matrix<int>>^ polynomial = CreatePolynomial();
			Polynomial<Matrix<int>>^ operationResult = polynomial * polynomial;

			assert(operationResult->Coefficients->Get(0)->items[0][0] == 2);
			assert(operationResult->Coefficients->Get(0)->items[0][1] == 3);
			assert(operationResult->Coefficients->Get(0)->items[1][0] == 6);
			assert(operationResult->Coefficients->Get(0)->items[1][1] == 11);

			assert(operationResult->Coefficients->Get(1)->items[0][0] == 4);
			assert(operationResult->Coefficients->Get(1)->items[0][1] == 6);
			assert(operationResult->Coefficients->Get(1)->items[1][0] == 12);
			assert(operationResult->Coefficients->Get(1)->items[1][1] == 22);

			assert(operationResult->Coefficients->Get(2)->items[0][0] == 2);
			assert(operationResult->Coefficients->Get(2)->items[0][1] == 3);
			assert(operationResult->Coefficients->Get(2)->items[1][0] == 6);
			assert(operationResult->Coefficients->Get(2)->items[1][1] == 11);
		}

		static void PolynomialScalarMultiplyTest()
		{
			Polynomial<Matrix<int>>^ polynomial = CreatePolynomial();
			Polynomial<Matrix<int>>^ operationResult = polynomial / 2;
			assert(polynomial->Coefficients->Get(0)->items[0][0] == 0);
			assert(polynomial->Coefficients->Get(0)->items[0][1] == 1);
			assert(polynomial->Coefficients->Get(0)->items[1][0] == 2);
			assert(polynomial->Coefficients->Get(0)->items[1][1] == 3);

			assert(polynomial->Coefficients->Get(1)->items[0][0] == 0);
			assert(polynomial->Coefficients->Get(1)->items[0][1] == 1);
			assert(polynomial->Coefficients->Get(1)->items[1][0] == 2);
			assert(polynomial->Coefficients->Get(1)->items[1][1] == 3);
		}


	public:
		static void Run()
		{
			PolynomialCreationTest();
			PolynomialValueTest();
			PolynomialSumTest();
			PolynomialMultiplicationTest();
			PolynomialScalarMultiplyTest();
		}
	};

	ref class PolynomialTests
	{
	public:
		static void Run()
		{
			IntPolynomialTests::Run();
			FloatPolynomialTests::Run();
			ComplexPolynomialTests::Run();
			MatrixPolynomialTests::Run();
		}
	};
}