using namespace Lab;

namespace Lab
{
    ref class FloatBinaryTreeProcessor
    {
        public:

            static void Process()
            {
                BinaryTreeNode<Single>^ node = ReadFloatBinaryTree();

                while (true)
                {
                    String^ command = ReadString("Enter command (print, insert, find, remove, order, exit): ");

                    if (command == "exit")
                    {
                        return;
                    }

                    if (command == "insert")
                    {
                        node = InsertNode(node);
                        OrderBinaryTree<Single>(node, WriteFloatTreeNode);
                    }

                    if (command == "order")
                    {
                        OrderAllBinaryTree<Single>(node, WriteFloatTreeNode);
                    }

                    if (command == "print")
                    {
                        OrderBinaryTree<Single>(node, WriteFloatTreeNode);
                    }

                    if (command == "find")
                    {
                        FindNode(node);
                    }

                    if (command == "remove")
                    {
                        RemoveNode(node);
                        OrderBinaryTree<Single>(node, WriteFloatTreeNode);
                    }

                    if (command == "tostring")
                    {
                        String^ command = ReadString("Enter order (RLR, RRL, LRR, RRL, LRR, RLR): ");
                        String^ result = gcnew String("");
                        result += BinaryTreeStringWriter<Single>::ToString(command, node, FloatTreeNodeToString, result);
                        Console::WriteLine(result);
                    }
                }
            };

        private:

            static void FindNode(BinaryTreeNode<Single>^ node)
            {
                Single value = ReadSingleValue("Find value: ");
                BinaryTreeNode<Single>^ result = node->Find(value, SingleComparer);

                if (result == nullptr)
                {
                    Console::WriteLine("Value not found.");
                    return;
                }

                Console::WriteLine("Value found: {0}.", result->GetValue());
            }

            static void RemoveNode(BinaryTreeNode<Single>^ node)
            {
                Single value = ReadSingleValue("Remove value: ");
                node->Remove(value, SingleComparer);
            }

            static BinaryTreeNode<Single>^ InsertNode(BinaryTreeNode<Single>^ node)
            {
                Single^ value = ReadSingle("Insert value: ");
                BinaryTreeNode<Single>^ newTree = node->InsertNode(value, SingleComparer);
                return newTree;
            }
        };
}