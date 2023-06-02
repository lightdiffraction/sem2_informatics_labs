using namespace Lab;

namespace Lab 
{
 
    template<class T>
    ref class BinaryTreeNode
    {
    private:
        T^ value;
        BinaryTreeNode<T>^ left;
        BinaryTreeNode<T>^ right;
        BinaryTreeNode<T>^ parent;
        int balanceFactor;
        int height;

    public:
        T^ GetValue()
        {
            return value;
        }

        BinaryTreeNode<T>^ GetLeft()
        {
            return left;
        }

        BinaryTreeNode<T>^ GetRight()
        {
            return right;
        }

        BinaryTreeNode<T>^ GetParent()
        {
            return parent;
        }

        int GetHeight()
        {
            if (this == nullptr)
            {
                return 0;
            }
            else
            {
                return height;
            }
        }

        int GetBF(BinaryTreeNode<T>^ node)
        {
            int leftHeight = -1;
            int rightHeight = -1;

            if (left != nullptr)
            {
                leftHeight = left->height;
            }

            if (right != nullptr)
            {
                rightHeight = right->height;
            }

            return leftHeight - rightHeight;
        }

        void SetValue(BinaryTreeNode<T>^ node)
        {
            value = node;
        }

        void SetLeft(BinaryTreeNode<T>^ node)
        {
            left = node;
        }

        void SetRight(BinaryTreeNode<T>^ node)
        {
            right = node;
        }

    public:
        BinaryTreeNode()
        {
            this->value = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        BinaryTreeNode(T^ value, BinaryTreeNode<T>^ parent)
        {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = parent;
        }

        BinaryTreeNode<T>(BinaryTreeNode<T>^ const tree)
        {
            this->value = tree->value;
            if (tree->left != nullptr)
            {
                this->left = gcnew BinaryTreeNode<T>(tree->left);
            }
            if (tree->right != nullptr)
            {
                this->right = gcnew BinaryTreeNode<T>(tree->right);
            }
        }

        BinaryTreeNode<T>^ InsertNode(T^ value, int (*comparer)(T^ value1, T^ value2))
        {
            BinaryTreeNode<T>^ result;
            if (this->value == nullptr)
            {
                this->value = value;
                return this;
            }
            else
            {
                InsertNode(value, this, comparer);
                result = Balance(this);
            }

            return result;
        }

        BinaryTreeNode<T>^ InsertNode(T^ value, BinaryTreeNode<T>^ parent, int (*comparer)(T^ value1, T^ value2))
        {
            BinaryTreeNode<T>^ result;

            if (comparer(value, parent->value) < 0)
            {
                if (parent->left == nullptr)
                {
                    result = gcnew BinaryTreeNode<T>(value, parent);
                    parent->left = result;
                }
                else
                {
                    result = InsertNode(value, parent->left, comparer);
                }
            }
            else
            {
                if (parent->right == nullptr)
                {
                    result = gcnew BinaryTreeNode<T>(value, parent);
                    parent->right = result;
                }
                else
                {
                    result = InsertNode(value, parent->right, comparer);
                }
            }

            BinaryTreeNode<T>^ current;
            current = result;
            while (current->parent != nullptr)
            {
                current = current->parent;
                current->height = Math::Max(current->left->GetHeight(), current->right->GetHeight()) + 1;
            }

            return result;
        }

        BinaryTreeNode<T>^ Find(T value, int (*comparer)(T^ value1, T^ value2))
        {
            BinaryTreeNode<T>^ node = this;
            while (node != nullptr)
            {
                if (comparer(node->value, value) == 0)
                {
                    return node;
                }

                if (comparer(node->value, value) < 0)
                {
                    node = node->right;
                }

                if (comparer(node->value, value) > 0)
                {
                    node = node->left;
                }
            }

            return nullptr;
        }

        BinaryTreeNode<T>^ GetSubTree(BinaryTreeNode<T>^ node, int (*comparer)(T^ value1, T^ value2))
        {
            BinaryTreeNode<T>^ newTree = gcnew BinaryTreeNode<T>();
            return GetSubTree(node, newTree, comparer);
        }

        BinaryTreeNode<T>^ GetSubTree(BinaryTreeNode<T>^ node, BinaryTreeNode<T>^ newTree, int (*comparer)(T^ value1, T^ value2))
        {
            if (node == nullptr)
            {
                return newTree;
            }

            newTree = newTree->InsertNode(node->GetValue(), comparer);
            newTree = GetSubTree(node->left, newTree, comparer);
            newTree = GetSubTree(node->right, newTree, comparer);
            return newTree;
        }

        BinaryTreeNode^ Remove(T^ value, int (*comparer)(T^ value1, T^ value2))
        {
            if (comparer(this->value, value) == 0 && this->right == nullptr && this->left == nullptr)
            {
                this->value = nullptr;
                this->height = 0;
                return this;
            }
            Remove(value, this, nullptr, false, comparer);
            UpdateHeights(this);
            return this;
        }

        void Remove(T^ value, BinaryTreeNode<T>^ node, BinaryTreeNode<T>^ parent, bool direction, int (*comparer)(T^ value1, T^ value2))
        {
            //дерево не задано
            if (node == nullptr)
            {
                return;
            }

            //ищем вершину которую надо удалить
            if (comparer(node->value, value) > 0)
            {
                Remove(value, node->left, node, false, comparer);
            }
            else if (comparer(node->value, value) < 0)
            {
                Remove(value, node->right, node, true, comparer);
            }
            else // нашли - node - вершина которую надо удалить
            {
                if (node->right == nullptr && node->left == nullptr)//у нее нет потомков
                {
                    if (direction)
                        parent->right = nullptr;
                    else
                        parent->left = nullptr;
                }
                else if (node->right != nullptr) //есть правый потомок
                {
                    T^ min = FindMin(node);
                    if (min != nullptr)
                    {
                        node->value = min;
                    }
                    return;
                }
                else // есть только левый
                {
                    if (direction)
                        parent->right = node->left;
                    else
                        parent->left = node->left;
                    return;
                }
            }
            return;
        }


        T^ FindMin(BinaryTreeNode<T>^ parent)
        {
            bool direction;

            if (parent == nullptr)
            {
                return nullptr;
            }

            BinaryTreeNode<T>^ currentParent = parent;
            BinaryTreeNode<T>^ current = parent->right;
            direction = true;

            if (current == nullptr)
            {
                return nullptr;
            }

            while (current->left != nullptr)
            {
                currentParent = current;
                direction = false;
                current = current->left;
            }
            
            T^ result = current->value; //минимум нашли - result это минимум

            if (current->right != nullptr) // у него есть правый потомок (левого быть не может)
            {
                current->value = current->right->value; //весь правый потомок должен стать им

                BinaryTreeNode<T>^ right = current->right->right;
                BinaryTreeNode<T>^ left = current->right->left;
                current->right = right;
                current->left = left;

                if (current->right != nullptr)
                {
                    current->right->parent = current;
                }

                if (current->left != nullptr)
                {
                    current->left->parent = current;
                }
            }
            else // потомков нет
            {
                if (direction == true)
                    currentParent->right = nullptr;
                else
                    currentParent->left = nullptr;
            }

            return result;
        }

        ArraySequence<T>^ ToArray()
        {
            ArraySequence<T>^ result = gcnew ArraySequence<T>();

            if (this->value == nullptr)
            {
                return result;
            }

            ToArray(this, result);
            return result;
        }

        void static PreOrderLeftRight(BinaryTreeNode<T>^ node, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            func(*(node->value));
            PreOrderLeftRight(node->left, func);
            PreOrderLeftRight(node->right, func);
        }

        void static PreOrderRightLeft(BinaryTreeNode<T>^ node, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            func(*(node->value));
            PreOrderRightLeft(node->right, func);
            PreOrderRightLeft(node->left, func);
        }

        void static InOrderLeftRight(BinaryTreeNode<T>^ node, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            InOrderLeftRight(node->left, func);
            func(*(node->value));
            InOrderLeftRight(node->right, func);
        }

        void static InOrderRightLeft(BinaryTreeNode<T>^ node, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            InOrderRightLeft(node->right, func);
            func(*(node->value));
            InOrderRightLeft(node->left, func);
        }

        void static PostOrderLeftRight(BinaryTreeNode<T>^ node, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            PostOrderLeftRight(node->left, func);
            PostOrderLeftRight(node->right, func);
            func(*(node->value));
        }

        void static PostOrderRightLeft(BinaryTreeNode<T>^ node, void (*func)(T value))
        {
            if (node == nullptr)
            {
                return;
            }

            PostOrderRightLeft(node->right, func);
            PostOrderRightLeft(node->left, func);
            func(*(node->value));
        }

        void Map(void (*func)(array<T^>^, int), int (*comparer)(T^ value1, T^ value2))
        {
            ArraySequence<T>^ ar = ToArray();
            ar->Map(func);

            BinaryTreeNode<T>^ result = gcnew BinaryTreeNode<T>();

            for (int i = 0; i < ar->GetSize(); i++)
            {
                result = result->InsertNode(ar->Get(i), comparer);
            }
        }

        T^ Reduce(T ^ (*func)(array<T^>^, int))
        {
            ArraySequence<T>^ ar = ToArray();
            T^ result = ar->Reduce(func);
            return result;
        }

        BinaryTreeNode^ Where(bool (*func)(T^), int (*comparer)(T^ value1, T^ value2))
        {
            ArraySequence<T>^ ar = ToArray();

            BinaryTreeNode<T>^ result = gcnew BinaryTreeNode<T>();

            for (int i = 0; i < ar->GetSize(); i++)
            {
                if (func(ar->Get(i)))
                {
                    result = result->InsertNode(ar->Get(i), comparer);
                }
            }

            return result;
        }

    private:

        void static ToArray(BinaryTreeNode^ node, ArraySequence<T>^ arraySequence)
        {
            if (node == nullptr)
            {
                return;
            }

            arraySequence->Add(node->value);
            ToArray(node->GetLeft(), arraySequence);
            ToArray(node->GetRight(), arraySequence);
        }

        void static UpdateHeights(BinaryTreeNode<T>^ node)
        {
            if (node == nullptr)
            {
                return;
            }

            UpdateHeights(node->GetRight());
            UpdateHeights(node->GetLeft());
            
            int leftHeight = -1;
            int rightHeight = -1;

            if (node->left != nullptr)
            {
                leftHeight = node->left->height;
            }

            if (node->right != nullptr)
            {
                rightHeight = node->right->height;
            }

            node->height = Math::Max(leftHeight, rightHeight) + 1;
        }

        BinaryTreeNode<T>^ Balance(BinaryTreeNode<T>^ node)
        {
            int bf = node->GetBF(node);

            if (bf == 0 || bf == 1)
            {
                return node;
            }

            if (bf == 2)
            {
                node = RotateRight(node);
            }
            else if (bf == -2)
            {
                node = RotateLeft(node);
            }

            UpdateHeights(node);
            return node;
        }

        BinaryTreeNode<T>^ RotateLeft(BinaryTreeNode<T>^ node)
        {
            BinaryTreeNode<T>^ result;
            BinaryTreeNode<T>^ temp;
            result = node->right;

            if (node->right->left != nullptr && node->right->right != nullptr)
            {
                temp = node->right->left;
                node->right->left = node;
                node->right = temp;
            }
            else if (node->right->right != nullptr)
            {
                node->right->left = node;
                node->right = nullptr;
            }
            else if (node->left->right != nullptr)
            {
                node->left->left = node;
                node->left = nullptr;
            }

            if (result->left != nullptr)
            {
                result->left->parent = result;
            }

            if (result->right != nullptr)
            {
                result->right->parent = result;
            }

            result->parent = nullptr;

            return result;
        }

        BinaryTreeNode<T>^ RotateRight(BinaryTreeNode<T>^ node)
        {
            BinaryTreeNode<T>^ result;
            BinaryTreeNode<T>^ temp;
            result = node->left;

            if (node->left->left != nullptr && node->left->right != nullptr)
            {
                temp = node->left->right;
                node->left->right = node;
                node->left = temp;

            }
            else if (node->left->left != nullptr)
            {
                node->left->right = node;
                node->left = nullptr;

            }
            else if (node->left->right != nullptr)
            {
                node->left->left = node;
                node->left = nullptr;
            }

            if (result->left != nullptr)
            {
                result->left->parent = result;
            }

            if (result->right != nullptr)
            {
                result->right->parent = result;
            }

            result->parent = nullptr;

            return result;
        }
    };
}