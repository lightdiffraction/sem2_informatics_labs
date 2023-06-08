using namespace Lab;

namespace Lab
{
    template <class T>
    void OrderBinaryTree(BinaryTreeNode<T>^ node, void (*func)(T^ value))
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
    void OrderAllBinaryTree(BinaryTreeNode<T>^ node, void (*func)(T^ value))
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

        Console::WriteLine("RLR:");
        BinaryTreeNode<T>::PreOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("RRL:");
        BinaryTreeNode<T>::PreOrderRightLeft(node, func);
        Console::WriteLine();

        Console::WriteLine("LRR:");
        BinaryTreeNode<T>::InOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("RRL:");
        BinaryTreeNode<T>::InOrderRightLeft(node, func);
        Console::WriteLine();

        Console::WriteLine("LRR:");
        BinaryTreeNode<T>::PostOrderLeftRight(node, func);
        Console::WriteLine();

        Console::WriteLine("RLR:");
        BinaryTreeNode<T>::PostOrderRightLeft(node, func);
        Console::WriteLine();
    };
}