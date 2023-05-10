using namespace Lab;

namespace Lab
{
    ref class PersonID
    {
    private:

        Int32^ series;

        Int32^ number;

    public:

        void SetSeries(Int32^ value)
        {
            series = value;
        }

        Int32^ GetSeries()
        {
            return series;
        }

        void SetNumber(Int32^ value)
        {
            number = value;
        }

        Int32^ GetNumber()
        {
            return number;
        }
    };
}