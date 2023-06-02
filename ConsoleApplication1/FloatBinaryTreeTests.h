#include <cassert> 

using namespace Lab;

namespace Lab
{
	ref class FloatBinaryTreeTests
	{
	private:

		static void Insert1Test()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			assert(*(tree->GetValue()) == 1.0);
			assert(*(tree->GetRight()->GetValue()) == 2.0);
		}

		static void Insert2Test()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			assert(*(tree->GetValue()) == 4.0);
			assert(*(tree->GetLeft()->GetValue()) == 3.0);
		}

		static void Balance1Test()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			assert(*(tree->GetValue()) == 2.0);
			assert(*(tree->GetLeft()->GetValue()) == 1.0);
			assert(*(tree->GetRight()->GetValue()) == 3.0);
		}

		static void Balance2Test()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			assert(*(tree->GetValue()) == 3.0);
			assert(*(tree->GetLeft()->GetValue()) == 2.0);
			assert(*(tree->GetRight()->GetValue()) == 4.0);
		}

		static void Balance3Test()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(5.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(7.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			assert(*(tree->GetValue()) == 4.0);
			assert(*(tree->GetLeft()->GetValue()) == 3.0);
			assert(*(tree->GetLeft()->GetLeft()->GetValue()) == 2.0);
			assert(*(tree->GetRight()->GetValue()) == 5.0);
			assert(*(tree->GetRight()->GetRight()->GetValue()) == 7.0);
		}

		static BinaryTreeNode<Single>^ CreateTree1()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			return tree;
		}

		static BinaryTreeNode<Single>^ CreateTree2()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(1.0f, SingleComparer);
			return tree;
		}

		static BinaryTreeNode<Single>^ CreateTree3()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(5.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(6.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(7.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(8.0f, SingleComparer);
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(9.0f, SingleComparer);
			tree = tree->InsertNode(10.0f, SingleComparer);
			return tree;
		}

		static BinaryTreeNode<Single>^ CreateTree4()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(8.0f, SingleComparer);
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(5.0f, SingleComparer);
			tree = tree->InsertNode(6.0f, SingleComparer);
			tree = tree->InsertNode(7.0f, SingleComparer);
			tree = tree->InsertNode(9.0f, SingleComparer);
			tree = tree->InsertNode(10.0f, SingleComparer);
			return tree;
		}

		static void Remove1Test()
		{
			BinaryTreeNode<Single>^ tree = CreateTree1();
			tree->Remove(1.0f, SingleComparer);
			ArraySequence<Single>^ ar = tree->ToArray();
			assert(ar->GetSize() == 3);
			assert(ar->Contains(2.0f, SingleComparer) == true);
			assert(ar->Contains(3.0f, SingleComparer) == true);
			assert(ar->Contains(4.0f, SingleComparer) == true);
		}

		static void Remove2Test()
		{
			BinaryTreeNode<Single>^ tree = CreateTree2();
			tree->Remove(1.0f, SingleComparer);
			ArraySequence<Single>^ ar = tree->ToArray();
			assert(ar->GetSize() == 3.0);
			assert(ar->Contains(2.0f, SingleComparer) == true);
			assert(ar->Contains(3.0f, SingleComparer) == true);
			assert(ar->Contains(4.0f, SingleComparer) == true);
		}

		static void Remove3Test()
		{
			BinaryTreeNode<Single>^ tree = CreateTree3();
			for (Single i = 1; i <= 10; i++)
			{
				tree->Remove(i, SingleComparer);
				ArraySequence<Single>^ ar = tree->ToArray();
				assert(ar->GetSize() == 10 - i);
				for (Single j = i + 1; j <= 10; j++)
				{
					assert(ar->Contains(j, SingleComparer) == true);
				}
			}
		}

		static void Remove4Test()
		{
			BinaryTreeNode<Single>^ tree = CreateTree4();
			for (Single i = 1; i <= 10; i++)
			{
				tree->Remove(i, SingleComparer);
				ArraySequence<Single>^ ar = tree->ToArray();
				assert(ar->GetSize() == 10 - i);
				for (Single j = i + 1; j <= 10; j++)
				{
					assert(ar->Contains(j, SingleComparer) == true);
				}
			}
		}

		static void Remove5Test()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(5.0f, SingleComparer);
			assert(*(tree->GetValue()) == 3.0);
			tree->Remove(3.0f, SingleComparer);
			assert(*(tree->GetValue()) == 4.0);
			assert(*(tree->GetLeft()->GetValue()) == 2.0);
			assert(*(tree->GetLeft()->GetParent()->GetValue()) == 4.0);
			assert(*(tree->GetLeft()->GetLeft()->GetValue()) == 1.0);
			assert(*(tree->GetLeft()->GetLeft()->GetParent()->GetValue()) == 2.0);
		}

		static void FindTest()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(5.0f, SingleComparer);
			tree = tree->InsertNode(6.0f, SingleComparer);
			BinaryTreeNode<Single>^ result;
			result = tree->Find(2.0f, SingleComparer);
			assert(*(result->GetValue()) == 2.0);
			result = tree->Find(1.0f, SingleComparer);
			assert(*(result->GetValue()) == 1.0);
			result = tree->Find(4.0f, SingleComparer);
			assert(*(result->GetValue()) == 4.0);
			result = tree->Find(3.0f, SingleComparer);
			assert(*(result->GetValue()) == 3.0);
			result = tree->Find(5.0f, SingleComparer);
			assert(*(result->GetValue()) == 5.0);
			result = tree->Find(6.0f, SingleComparer);
			assert(*(result->GetValue()) == 6.0);
		}

		static void ReduceTest()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(5.0f, SingleComparer);
			tree = tree->InsertNode(6.0f, SingleComparer);

			Single^ result;

			result = tree->Reduce(FloatMin);
			assert(*result == 1.0);

			result = tree->Reduce(FloatMax);
			assert(*result == 6.0);
		}

		static void MapTest()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);

			tree->Map(FloatIncrement, SingleComparer);
			assert(*(tree->GetValue()) == 3.0);
			assert(*(tree->GetLeft()->GetValue()) == 2.0);
			assert(*(tree->GetRight()->GetValue()) == 5.0);
		}

		static void WhereTest()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(-1.0f, SingleComparer);
			tree = tree->InsertNode(-2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(-5.0f, SingleComparer);
			tree = tree->InsertNode(6.0f, SingleComparer);

			tree = tree->Where(FloatPositive, SingleComparer);
			assert(*(tree->GetValue()) == 4.0);
			assert(*(tree->GetLeft()->GetValue()) == 3.0);
			assert(*(tree->GetRight()->GetValue()) == 6.0);
		}

		void static GetSubTreeTest()
		{
			BinaryTreeNode<Single>^ tree = gcnew BinaryTreeNode<Single>();
			tree = tree->InsertNode(1.0f, SingleComparer);
			tree = tree->InsertNode(2.0f, SingleComparer);
			tree = tree->InsertNode(4.0f, SingleComparer);
			tree = tree->InsertNode(3.0f, SingleComparer);
			tree = tree->InsertNode(5.0f, SingleComparer);
			tree = tree->InsertNode(6.0f, SingleComparer);

			BinaryTreeNode<Single>^ node = tree->Find(2.0, SingleComparer);
			BinaryTreeNode<Single>^ newTree = node->GetSubTree(node, SingleComparer);

			assert(*(newTree->GetValue()) == 2.0);
			assert(*(newTree->GetLeft()->GetValue()) == 1.0);
			assert(*(newTree->GetRight()->GetValue()) == 3.0);
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