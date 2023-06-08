using namespace Lab;

namespace Lab
{
    ref class StringBinaryTreeProcessor
    {
    public:

        static void Process()
        {
            BinaryTreeNode<String>^ node = ReadStringBinaryTree();

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
                    OrderBinaryTree<String>(node, WriteStringTreeNode);
                }

                if (command == "order")
                {
                    OrderAllBinaryTree<String>(node, WriteStringTreeNode);
                }

                if (command == "print")
                {
                    OrderBinaryTree<String>(node, WriteStringTreeNode);
                }

                if (command == "find")
                {
                    FindNode(node);
                }

                if (command == "remove")
                {
                    RemoveNode(node);
                    OrderBinaryTree<String>(node, WriteStringTreeNode);
                }

                if (command == "tostring")
                {
                    String^ command = ReadString("Enter order (RLR, RRL, LRR, RRL, LRR, RLR): ");
                    String^ result = gcnew String("");
                    result += BinaryTreeStringWriter<String>::ToString(command, node, StringTreeNodeToString, result);
                    Console::WriteLine(result);
                }
            }
        };

    private:

        static void FindNode(BinaryTreeNode<String>^ node)
        {
            String^ value = ReadString("Find value: ");
            BinaryTreeNode<String>^ result = node->Find(value, StringComparer);

            if (result == nullptr)
            {
                Console::WriteLine("Value not found.");
                return;
            }

            Console::WriteLine("Value found: {0}.", result->GetValue());
        }

        static void RemoveNode(BinaryTreeNode<String>^ node)
        {
            String^ value = ReadString("Remove value: ");
            node->Remove(value, StringComparer);
        }

        static BinaryTreeNode<String>^ InsertNode(BinaryTreeNode<String>^ node)
        {
            String^ value = ReadString("Insert value: ");
            BinaryTreeNode<String>^ newTree = node->InsertNode(value, StringComparer);
            return newTree;
        }
    };
}