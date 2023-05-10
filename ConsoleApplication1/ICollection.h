namespace Lab
{
	template<class T>
	public ref class ICollection 
	{
		void CopyTo(array<T>^ destination, int) {}

		int Count() { return 0; }
	};

}