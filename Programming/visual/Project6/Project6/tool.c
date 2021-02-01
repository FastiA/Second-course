int main()
{
	int base = 1;
	int finish = 2;
	int result = 1;

	for (int i = 1; i < finish; i++)
	{
		result += base;
	}

	printf("%i", result);
}