using namespace Lab;

namespace Lab
{
	template<class T>
	void WriteListSequence(ListSequence<T>^ listSequence, void(*writer)(T))
	{
		Console::WriteLine("List Sequence:");
		
		if (listSequence->First == nullptr)
		{
			throw gcnew IndexOutOfRangeException();
		}
		Item<T>^ currentItem = listSequence->First;
		while (currentItem != nullptr)
		{
			T value = currentItem->value;
			writer(value);
			currentItem = currentItem->next;
		};
		Console::WriteLine();
	}
}