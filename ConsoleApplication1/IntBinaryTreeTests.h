#include <cassert> 

using namespace Lab;

namespace Lab
{
	ref class IntBinaryTreeTests
	{
	private:

		static void Insert1Test()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			assert(*(tree->GetValue()) == 1);
			assert(*(tree->GetRight()->GetValue()) == 2);
		}

		static void Insert2Test()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			assert(*(tree->GetValue()) == 4);
			assert(*(tree->GetLeft()->GetValue()) == 3);
		}
		
		static void Balance1Test()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			assert(*(tree->GetValue()) == 2);
			assert(*(tree->GetLeft()->GetValue()) == 1);
			assert(*(tree->GetRight()->GetValue()) == 3);
		}

		static void Balance2Test()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			assert(*(tree->GetValue()) == 3);
			assert(*(tree->GetLeft()->GetValue()) == 2);
			assert(*(tree->GetRight()->GetValue()) == 4);
		}

		static void Balance3Test()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(7, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			assert(*(tree->GetValue()) == 4);
			assert(*(tree->GetLeft()->GetValue()) == 3);
			assert(*(tree->GetLeft()->GetLeft()->GetValue()) == 2);
			assert(*(tree->GetRight()->GetValue()) == 5);
			assert(*(tree->GetRight()->GetRight()->GetValue()) == 7);
		}

		static BinaryTreeNode<Int32>^ CreateTree1()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			return tree;
		}

		static BinaryTreeNode<Int32>^ CreateTree2()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(1, IntComparer);
			return tree;
		}

		static BinaryTreeNode<Int32>^ CreateTree3()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(6, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(7, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(8, IntComparer);
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(9, IntComparer);
			tree = tree->InsertNode(10, IntComparer);
			return tree;
		}

		static BinaryTreeNode<Int32>^ CreateTree4()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(8, IntComparer);
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(6, IntComparer);
			tree = tree->InsertNode(7, IntComparer);
			tree = tree->InsertNode(9, IntComparer);
			tree = tree->InsertNode(10, IntComparer);
			return tree;
		}

		static void Remove1Test()
		{
			BinaryTreeNode<Int32>^ tree = CreateTree1();
			tree->Remove(1, IntComparer);
			ArraySequence<Int32>^ ar = tree->ToArray();
			assert(ar->GetSize() == 3);
			assert(ar->Contains(2, IntComparer) == true);
			assert(ar->Contains(3, IntComparer) == true);
			assert(ar->Contains(4, IntComparer) == true);
		}

		static void Remove2Test()
		{
			BinaryTreeNode<Int32>^ tree = CreateTree2();
			tree->Remove(1, IntComparer);
			ArraySequence<Int32>^ ar = tree->ToArray();
			assert(ar->GetSize() == 3);
			assert(ar->Contains(2, IntComparer) == true);
			assert(ar->Contains(3, IntComparer) == true);
			assert(ar->Contains(4, IntComparer) == true);
		}

		static void Remove3Test()
		{
			BinaryTreeNode<Int32>^ tree = CreateTree3();
			for (int i = 1; i <= 10; i++)
			{
				tree->Remove(i, IntComparer);
				ArraySequence<Int32>^ ar = tree->ToArray();
				assert(ar->GetSize() == 10 - i);
				for (int j = i + 1; j <= 10; j++)
				{
					assert(ar->Contains(j, IntComparer) == true);
				}
			}
		}

		static void Remove4Test()
		{
			BinaryTreeNode<Int32>^ tree = CreateTree4();
			for (int i = 1; i <= 10; i++)
			{
				tree->Remove(i, IntComparer);
				ArraySequence<Int32>^ ar = tree->ToArray();
				assert(ar->GetSize() == 10 - i);
				for (int j = i + 1; j <= 10; j++)
				{
					assert(ar->Contains(j, IntComparer) == true);
				}
			}
		}

		static void Remove5Test()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(5, IntComparer);
			assert(*(tree->GetValue()) == 3);
			tree->Remove(3, IntComparer);
			assert(*(tree->GetValue()) == 4);
			assert(*(tree->GetLeft()->GetValue()) == 2);
			assert(*(tree->GetLeft()->GetParent()->GetValue()) == 4);
			assert(*(tree->GetLeft()->GetLeft()->GetValue()) == 1);
			assert(*(tree->GetLeft()->GetLeft()->GetParent()->GetValue()) == 2);
		}

		static void FindTest()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(6, IntComparer);

			BinaryTreeNode<Int32>^ result;
			
			result = tree->Find(2, IntComparer);
			assert(*(result->GetValue()) == 2);
			result = tree->Find(1, IntComparer);
			assert(*(result->GetValue()) == 1);
			result = tree->Find(4, IntComparer);
			assert(*(result->GetValue()) == 4);
			result = tree->Find(3, IntComparer);
			assert(*(result->GetValue()) == 3);
			result = tree->Find(5, IntComparer);
			assert(*(result->GetValue()) == 5);
			result = tree->Find(6, IntComparer);
			assert(*(result->GetValue()) == 6);
		}

		static void ReduceTest()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(6, IntComparer);

			Int32^ result;
				
			result = tree->Reduce(IntMin);
			assert(*result == 1);
			
			result = tree->Reduce(IntMax);
			assert(*result == 6);
		}

		static void MapTest()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			
			tree->Map(IntIncrement, IntComparer);
			assert(*(tree->GetValue()) == 3);
			assert(*(tree->GetLeft()->GetValue()) == 2);
			assert(*(tree->GetRight()->GetValue()) == 5);
		}

		static void WhereTest()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(6, IntComparer);

			tree = tree->Where(IntEven, IntComparer);
			assert(*(tree->GetValue()) == 4);
			assert(*(tree->GetLeft()->GetValue()) == 2);
			assert(*(tree->GetRight()->GetValue()) == 6);
		}

		void static GetSubTreeTest()
		{
			BinaryTreeNode<Int32>^ tree = gcnew BinaryTreeNode<Int32>();
			tree = tree->InsertNode(1, IntComparer);
			tree = tree->InsertNode(2, IntComparer);
			tree = tree->InsertNode(4, IntComparer);
			tree = tree->InsertNode(3, IntComparer);
			tree = tree->InsertNode(5, IntComparer);
			tree = tree->InsertNode(6, IntComparer);

			BinaryTreeNode<Int32>^ node = tree->Find(2, IntComparer);
			BinaryTreeNode<Int32>^ newTree = node->GetSubTree(node, IntComparer);

			assert(*(newTree->GetValue()) == 2);
			assert(*(newTree->GetLeft()->GetValue()) == 1);
			assert(*(newTree->GetRight()->GetValue()) == 3);
		}

	public:
		static void Run()
		{
			Insert1Test();
			Insert2Test();
			Balance1Test();
			Balance2Test();
			Balance3Test();
			Remove1Test();
			Remove2Test();
			Remove3Test();
			Remove4Test();
			Remove5Test();
			FindTest();
			ReduceTest();
			MapTest();
			WhereTest();
			GetSubTreeTest();
		}
	};
}