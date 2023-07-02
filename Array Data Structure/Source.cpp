#include <iostream>
#include<array>
template<typename T, size_t S>
class Array
{

public:
	constexpr size_t Size() const { return S; }

	T& operator[](size_t index) 
	{ 
		return data[index];
	} //return by value
	const T& operator[](size_t index) const { return data[index]; }

	T* Data() { return data; }
	const T* Data() { return data; }
private:
	T data[S];
};
//understanding the array data structure over Vector (dynamic isnt needed is it)
int main()
{

	int size = 5;
	int arr[5]; // stack allocated array (size cannot be used here)

	int* dynArr = new int[size]; //Dynamic array (heap allocated)
	delete[] dynArr; // need to delete when its heap allocated... always

	//using custom Array Class
	size = 10;
	Array<int, 10> data;

	memset(&data[0], 0, data.Size() * sizeof(int));

	for (size_t i = 0; i < data.Size(); ++i)
	{
		std::cout << data[i] << std::endl;
	}
}