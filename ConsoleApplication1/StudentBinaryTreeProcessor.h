using namespace Lab;

namespace Lab
{
    ref class StudentBinaryTreeProcessor
    {
    public:

        static void Process()
        {
            BinaryTreeNode<Student>^ node = ReadStudentBinaryTree();

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
                    OrderBinaryTree<Student>(node, WriteStudentTreeNode);
                }

                if (command == "order")
                {
                    OrderAllBinaryTree<Student>(node, WriteStudentTreeNode);
                }

                if (command == "print")
                {
                    OrderBinaryTree<Student>(node, WriteStudentTreeNode);
                }

                if (command == "find")
                {
                    FindNode(node);
                }

                if (command == "remove")
                {
                    RemoveNode(node);
                    OrderBinaryTree<Student>(node, WriteStudentTreeNode);
                }

                if (command == "tostring")
                {
                    String^ command = ReadString("Enter order (RLR, RRL, LRR, RRL, LRR, RLR): ");
                    String^ result = gcnew String("");
                    result += BinaryTreeStringWriter<Student>::ToString(command, node, StudentTreeNodeToString, result);
                    Console::WriteLine(result);
                }
            }
        };

    private:

        static void FindNode(BinaryTreeNode<Student>^ node)
        {
            Console::WriteLine("Enter student data to find student: ");
            Student^ value = ReadStudent();
            BinaryTreeNode<Student>^ result = node->Find(value, StudentComparer);

            if (result == nullptr)
            {
                Console::WriteLine("Student not found.");
                return;
            }

            String^ studentString = StudentTreeNodeToString(result->GetValue());
            Console::WriteLine("Student found: {0}.", studentString);
        }

        static void RemoveNode(BinaryTreeNode<Student>^ node)
        {
            Console::WriteLine("Enter student data to remove student: ");
            Student^ value = ReadStudent();
            node->Remove(value, StudentComparer);
        }

        static BinaryTreeNode<Student>^ InsertNode(BinaryTreeNode<Student>^ node)
        {
            Console::WriteLine("Enter student data to insert student: ");
            Student^ value = ReadStudent();
            BinaryTreeNode<Student>^ newTree = node->InsertNode(value, StudentComparer);
            return newTree;
        }
    };
}