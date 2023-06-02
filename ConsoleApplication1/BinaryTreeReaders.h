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
}