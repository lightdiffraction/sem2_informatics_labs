using namespace Lab;

namespace Lab
{
    ref class IntBinaryTreeProcessor
    {
    public:
        
        static void Process()
        {
            BinaryTreeNode<Int32>^ node = ReadIntBinaryTree();

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
                    OrderBinaryTree<Int32>(node, WriteIntTreeNode);
                }

                if (command == "order")
                {
                    OrderAllBinaryTree<Int32>(node, WriteIntTreeNode);
                }

                if (command == "print")
                {
                    OrderBinaryTree<Int32>(node, WriteIntTreeNode);
                }

                if (command == "find")
                {
                    FindNode(node);
                }

                if (command == "remove")
                {
                    RemoveNode(node);
                    OrderBinaryTree<Int32>(node, WriteIntTreeNode);
                }

                if (command == "tostring")
                {
                    String^ command = ReadString("Enter order ( Àœ,  œÀ, À œ, œ À, Àœ , œÀ ): ");
                    String^ result = gcnew String("");
                    result += BinaryTreeStringWriter<Int32>::ToString(command, node, IntTreeNodeToString, result);
                    Console::WriteLine(result);
                }
            }
        };

    private:

        static void FindNode(BinaryTreeNode<Int32>^ node)
        {
            Int32 value = ReadInt32Value("Find value: ");
            BinaryTreeNode<Int32>^ result = node->Find(value, IntComparer);

            if (result == nullptr)
            {
                Console::WriteLine("Value not found.");
                return;
            }

            Console::WriteLine("Value found: {0}.", result->GetValue());
        }

        static void RemoveNode(BinaryTreeNode<Int32>^ node)
        {
            Int32 value = ReadInt32Value("Remove value: ");
            node->Remove(value, IntComparer);
        }

        static BinaryTreeNode<Int32>^ InsertNode(BinaryTreeNode<Int32>^ node)
        {
            Int32^ value = ReadInt32("Insert value: ");
            BinaryTreeNode<Int32>^ newTree = node->InsertNode(value, IntComparer);
            return newTree;
        }
    };
}