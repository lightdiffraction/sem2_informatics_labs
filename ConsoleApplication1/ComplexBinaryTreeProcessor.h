using namespace Lab;

namespace Lab
{
    ref class ComplexBinaryTreeProcessor
    {
    public:

        static void Process()
        {
            BinaryTreeNode<Complex>^ node = ReadComplexBinaryTree();

            while (true)
            {
                String^ command = ReadString("Enter command (print, insert, find, remove, order, tostring, exit): ");

                if (command == "exit")
                {
                    return;
                }

                if (command == "insert")
                {
                    node = InsertNode(node);
                    OrderBinaryTree<Complex>(node, WriteComplexTreeNode);
                }

                if (command == "order")
                {
                    OrderAllBinaryTree<Complex>(node, WriteComplexTreeNode);
                }

                if (command == "print")
                {
                    OrderBinaryTree<Complex>(node, WriteComplexTreeNode);
                }

                if (command == "find")
                {
                    FindNode(node);
                }

                if (command == "remove")
                {
                    RemoveNode(node);
                    OrderBinaryTree<Complex>(node, WriteComplexTreeNode);
                }

                if (command == "tostring")
                {
                    String^ command = ReadString("Enter order (RLR, RRL, LRR, RRL, LRR, RLR): ");
                    String^ result = gcnew String("");
                    result += BinaryTreeStringWriter<Complex>::ToString(command, node, ComplexTreeNodeToString, result);
                    Console::WriteLine(result);
                }
            }
        };

    private:

        static void FindNode(BinaryTreeNode<Complex>^ node)
        {
            Complex^ value = ReadComplex();
            BinaryTreeNode<Complex>^ result = node->Find(value, ComplexComparer);

            if (result == nullptr)
            {
                Console::WriteLine("Value not found.");
                return;
            }

            String^ resultString = ComplexToString(result->GetValue());

            Console::WriteLine("Value found: {0}.", resultString);
        }

        static void RemoveNode(BinaryTreeNode<Complex>^ node)
        {
            Complex^ value = ReadComplex();
            node->Remove(value, ComplexComparer);
        }

        static BinaryTreeNode<Complex>^ InsertNode(BinaryTreeNode<Complex>^ node)
        {
            Complex^ value = ReadComplex("Insert value: ");
            BinaryTreeNode<Complex>^ newTree = node->InsertNode(value, ComplexComparer);
            return newTree;
        }
    };
}