using namespace Lab;

namespace Lab
{
    template <class T>
    void OrderBinaryTree(BinaryTreeNode<T>^ node, void (*func)(T value))
    {
        if (node == nullptr)
        {
            Console::WriteLine("Null tree");
            return;
        }

        if (node->GetValue() == nullptr)
        {
            Console::WriteLine("Empty tree");
            return;
        }

        Console::WriteLine("Tree:");
        BinaryTreeNode<T>::PreOrderLeftRight(node, func);
        Console::WriteLine();
    };

    template <class T>
    void OrderAllBinaryTree(BinaryTreeNode<T>^ node, void (*func)(T value))
    {
        if (node == nullptr)
        {
            Console::WriteLine("Null tree");
            return;
        }

        if (node->GetValue() == nullptr)
        {
            Console::WriteLine("Empty tree");
            return;
        }

        Console::WriteLine("Œ·ıÓ‰  Àœ:");
        BinaryTreeNode<T>::PreOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("Œ·ıÓ‰  œÀ:");
        BinaryTreeNode<T>::PreOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("Œ·ıÓ‰ À œ:");
        BinaryTreeNode<T>::InOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("Œ·ıÓ‰ œ À:");
        BinaryTreeNode<T>::InOrderRightLeft(node, func);
        Console::WriteLine();

        Console::WriteLine("Œ·ıÓ‰ Àœ :");
        BinaryTreeNode<T>::PostOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("Œ·ıÓ‰ œÀ :");
        BinaryTreeNode<T>::PostOrderRightLeft(node, func);
        Console::WriteLine();
    };
}