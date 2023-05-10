using namespace Lab;

namespace Lab
{
    void ProcessPriorityQueue(String^ elementType)
    {
        if (elementType == "float")
        {
            ProcessFloatPriorityQueue();
        }
        else if (elementType == "int")
        {
            ProcessIntPriorityQueue();
        }
        else if (elementType == "complex")
        {
            ProcessComplexPriorityQueue();
        }
        else if (elementType == "string")
        {
            ProcessStringPriorityQueue();
        }
        else if (elementType == "student")
        {
            ProcessStudentPriorityQueue();
        }
    }
}