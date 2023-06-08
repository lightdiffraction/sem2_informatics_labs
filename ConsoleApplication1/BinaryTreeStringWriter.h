namespace Lab
{
    template<class T>
    ref class BinaryTreeStringWriter
    {

    private: 
        static String^ RootToString(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            result += "{" + func(node->GetValue()) + "}";
            return result;
        }

        static String^ LeftToString(String^ (*orderFunc)(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result), 
            BinaryTreeNode<T>^ node, 
            String ^ (*func)(T^ value), 
            String^ result)
        {
            if (node->GetLeft() != nullptr)
            {
                result += "(";
                result = orderFunc(node->GetLeft(), func, result);
                result += ")";
            }

            return result;
        }

        static String^ RightToString(String ^ (*orderFunc)(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result),
            BinaryTreeNode<T>^ node,
            String ^ (*func)(T^ value),
            String^ result)
        {
            if (node->GetRight() != nullptr)
            {
                result += "[";
                result = orderFunc(node->GetRight(), func, result);
                result += "]";
            }

            return result;
        }

    public:
        static String^ ToString(String^ command, BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            if (command == "RLR")
            {
                return PreOrderLeftRight(node, func, result);
            }
            if (command == "RRL")
            {
                return PreOrderRightLeft(node, func, result);
            }
            if (command == "LRR")
            {
                return InOrderLeftRight(node, func, result);
            }
            if (command == "RRL")
            {
                return InOrderRightLeft(node, func, result);
            }
            if (command == "LRR")
            {
                return PostOrderLeftRight(node, func, result);
            }
            if (command == "RLR")
            {
                return PostOrderRightLeft(node, func, result);
            }
            return result;
        }

        static String^ PreOrderLeftRight(BinaryTreeNode<T>^ node, String^ (*func)(T^ value), String^ result)
        {
            if (node == nullptr)
            {
                return result;
            }

            result = RootToString(node, func, result);
            result = LeftToString(PreOrderLeftRight, node, func, result);
            result = RightToString(PreOrderLeftRight, node, func, result);
            return result;
        }

        static String^ PreOrderRightLeft(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            if (node == nullptr)
            {
                return result;
            }

            result = RootToString(node, func, result);
            result = RightToString(PreOrderRightLeft, node, func, result);
            result = LeftToString(PreOrderRightLeft, node, func, result);
            return result;
        }

        static String^ InOrderLeftRight(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            if (node == nullptr)
            {
                return result;
            }

            result = LeftToString(InOrderLeftRight, node, func, result);
            result = RootToString(node, func, result);
            result = RightToString(InOrderLeftRight, node, func, result);
            return result;
        }

        static String^ InOrderRightLeft(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            if (node == nullptr)
            {
                return result;
            }

            result = RightToString(InOrderRightLeft, node, func, result);
            result = RootToString(node, func, result);
            result = LeftToString(InOrderRightLeft, node, func, result);
            return result;
        }

        static String^ PostOrderLeftRight(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            if (node == nullptr)
            {
                return result;
            }

            result = LeftToString(PostOrderLeftRight, node, func, result);
            result = RightToString(PostOrderLeftRight, node, func, result);
            result = RootToString(node, func, result);
            return result;
        }

        static String^ PostOrderRightLeft(BinaryTreeNode<T>^ node, String ^ (*func)(T^ value), String^ result)
        {
            if (node == nullptr)
            {
                return result;
            }

            result = RightToString(PostOrderRightLeft, node, func, result);
            result = LeftToString(PostOrderRightLeft, node, func, result);
            result = RootToString(node, func, result);
            return result;
        }
    };
}