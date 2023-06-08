using namespace Lab;

namespace Lab
{
    BinaryTreeNode<Int32>^ ReadIntBinaryTree()
    {
        Int32 n = ReadElementsNumber();
        BinaryTreeNode<Int32>^ node = gcnew  BinaryTreeNode<Int32>();

        for (int i = 0; i < n; i++)
        {
            Int32^ ptr = ReadInt32();
            node = node->InsertNode(ptr, IntComparer);
        }

        return node;
    }

    BinaryTreeNode<Single>^ ReadFloatBinaryTree()
    {
        Int32 n = ReadElementsNumber();
        BinaryTreeNode<Single>^ node = gcnew  BinaryTreeNode<Single>();

        for (int i = 0; i < n; i++)
        {
            Single^ ptr = ReadSingle();
            node = node->InsertNode(ptr, SingleComparer);
        }

        return node;
    }

    BinaryTreeNode<String>^ ReadStringBinaryTree()
    {
        Int32 n = ReadElementsNumber();
        BinaryTreeNode<String>^ node = gcnew  BinaryTreeNode<String>();

        for (int i = 0; i < n; i++)
        {
            String^ ptr = ReadString();
            node = node->InsertNode(ptr, StringComparer);
        }

        return node;
    }

    BinaryTreeNode<Student>^ ReadStudentBinaryTree()
    {
        Int32 n = ReadElementsNumber();
        BinaryTreeNode<Student>^ node = gcnew  BinaryTreeNode<Student>();

        for (int i = 0; i < n; i++)
        {
            Student^ ptr = ReadStudent();
            node = node->InsertNode(ptr, StudentComparer);
        }

        return node;
    }

    BinaryTreeNode<Complex>^ ReadComplexBinaryTree()
    {
        Int32 n = ReadElementsNumber();
        BinaryTreeNode<Complex>^ node = gcnew  BinaryTreeNode<Complex>();

        for (int i = 0; i < n; i++)
        {
            Complex^ ptr = ReadComplex();
            node = node->InsertNode(ptr, ComplexComparer);
        }

        return node;
    }
}