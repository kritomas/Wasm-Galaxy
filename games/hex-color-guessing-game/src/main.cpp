#include <iostream>

int sqr(int num)
{
	return num * num;
}

extern "C"
{
int csqr(int num)
{
	return sqr(num);
}
}

int main(int argc, char* argv[])
{
	std::cout << "Hello World!" << std::endl;
	return 0;
}