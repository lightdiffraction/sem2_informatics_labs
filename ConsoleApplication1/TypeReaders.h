namespace Lab
{
    Int32^ ReadInt32()
    {
        Console::Write("Enter element: ");
        Int32 value = 0;
        String^ str = Console::ReadLine();
        Int32::TryParse(str, value);
        Int32^ ptr = dynamic_cast<Int32^>((Object^)value);
        return ptr;
    }

    Int32^ ReadInt32(String^ label)
    {
        Console::Write(label);
        Int32 value = 0;
        String^ str = Console::ReadLine();
        Int32::TryParse(str, value);
        Int32^ ptr = dynamic_cast<Int32^>((Object^)value);
        return ptr;
    }

    Int32 ReadInt32Value()
    {
        Console::Write("Enter value: ");
        Int32 value = 0;
        String^ str = Console::ReadLine();
        Int32::TryParse(str, value);
        return value;
    }

    Single^ ReadSingle()
    {
        Console::Write("Enter element: ");
        Single value = 0;
        String^ str = Console::ReadLine();
        Single::TryParse(str, value);
        Single^ ptr = dynamic_cast<Single^>((Object^)value);
        return ptr;
    }

    Single^ ReadSingle(String^ prompt)
    {
        Console::Write(prompt);
        Single value = 0;
        String^ str = Console::ReadLine();
        Single::TryParse(str, value);
        Single^ ptr = dynamic_cast<Single^>((Object^)value);
        return ptr;
    }

    Single ReadSingleValue(String^ prompt)
    {
        Console::Write(prompt);
        Single value = 0;
        String^ str = Console::ReadLine();
        Single::TryParse(str, value);
        return value;
    }

    String^ ReadString()
    {
        Console::Write("Enter element: ");
        String^ str = Console::ReadLine();
        return str;
    }

    String^ ReadString(String^ label)
    {
        Console::Write(label);
        String^ str = Console::ReadLine();
        return str;
    }

    Complex^ ReadComplex()
    {
        Console::WriteLine("Enter element: ");
        Complex^ complex = gcnew Complex();
        complex->Real = ReadSingle("Enter real: ");
        complex->Imaginary = ReadSingle("Enter imaginary: ");
        return complex;
    }

    Complex^ ReadComplex(String^ prompt)
    {
        Console::WriteLine(prompt);
        Complex^ complex = gcnew Complex();
        complex->Real = ReadSingle("Enter real: ");
        complex->Imaginary = ReadSingle("Enter imaginary: ");
        return complex;
    }

    Complex^ ReadComplexValue(String^ label)
    {
        Console::WriteLine(label);
        Complex^ complex = gcnew Complex();
        complex->Real = ReadSingle("Enter real: ");
        complex->Imaginary = ReadSingle("Enter imaginary: ");
        return complex;
    }

    PersonID^ ReadID()
    {
        Console::WriteLine("Enter ID: ");
        PersonID^ id = gcnew PersonID();
        Int32^ series = ReadInt32("Enter series: ");
        id->SetSeries(series);
        Int32^ number = ReadInt32("Enter number: ");
        id->SetNumber(number);
        return id;
    }

    DateTime ReadBirthDate()
    {
        Console::Write("Enter birth date: ");
        String^ dateString = Console::ReadLine();
        DateTime result = Convert::ToDateTime(dateString);
        return result;
    }

    Student^ ReadStudent()
    {
        Console::WriteLine("Enter person: ");
        Student^ student = gcnew Student();
        String^ firstName = ReadString("Enter first name: ");
        student->SetFirstName(firstName);
        String^ middleName = ReadString("Enter middle name: ");
        student->SetMiddleName(middleName);
        String^ lastName = ReadString("Enter last name: ");
        student->SetLastName(lastName);
        PersonID^ id = ReadID();
        student->SetID(id);
        DateTime date = ReadBirthDate();
        student->SetDate(date);
        return student;
    }

    Matrix<int>^ ReadMatrixInt()
    {
        Console::WriteLine("Enter matrix: ");
        Int32 size = ReadInt32Value("Enter size: ");
        Matrix<Int32>^matrix = gcnew Matrix<Int32>(size);
        for (int i = 0; i < size; i++)
        {
            Console::WriteLine("Enter row: ");
            (matrix->items)[i] = gcnew array<int>(size);
            for (int j = 0; j < size; j++)
            {
                (matrix->items)[i][j] = ReadInt32Value("Enter element:");
            }
        }
        return matrix;
    }
}