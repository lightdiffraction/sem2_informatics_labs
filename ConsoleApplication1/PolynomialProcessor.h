#include <stdexcept>;
using namespace Lab;

namespace Lab
{
    void ProcessPolynomial(String^ elementType)
    {
        if (elementType == "float")
        {
            ProcessFloatPolynomial();
        }
        else if (elementType == "int")
        {
            ProcessIntPolynomial();
        }
        else if (elementType == "complex")
        {
            ProcessComplexPolynomial();
        }
        else if (elementType == "matrix")
        {
            ProcessMatrixPolynomial();
        }
        else 
        {
            throw std::invalid_argument("type not supported");
        }
    }
}