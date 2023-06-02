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
	}
}