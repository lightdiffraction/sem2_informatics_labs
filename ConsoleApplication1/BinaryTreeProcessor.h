namespace Lab
{
	void ProcessBinaryTree(String^ elementType)
	{
		if (elementType == "int")
		{
			IntBinaryTreeProcessor::Process();
		}
		else if (elementType == "float")
		{
			FloatBinaryTreeProcessor::Process();
		}
		else if (elementType == "complex")
		{
			ComplexBinaryTreeProcessor::Process();
		}
		else if (elementType == "string")
		{
			StringBinaryTreeProcessor::Process();
		}
		else if (elementType == "student")
		{
			StudentBinaryTreeProcessor::Process();
		}
	}
}