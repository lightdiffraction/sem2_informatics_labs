using namespace Lab;

namespace Lab
{
    ref class Student
    {
    private:
        PersonID^ id;
        String^ firstName;
        String^ middleName;
        String^ lastName;
        DateTime date;

    public:
        void SetID(PersonID^ value)
        {
            id = value;
        }

        PersonID^ GetID()
        {
            return id;
        };

        void SetFirstName(String^ value)
        {
            firstName = value;
        };

        String^ GetFirstName()
        {
            return firstName;
        };

        void SetLastName(String^ value)
        {
            lastName = value;
        };

        String^ GetLastName()
        {
            return lastName;
        };

        void SetMiddleName(String^ value)
        {
            middleName = value;
        };

        String^ GetMiddleName()
        {
            return middleName;
        };

        void SetDate(DateTime value)
        {
            date = value;
        };

        DateTime GetDate()
        {
            return date;
        };
    };
}