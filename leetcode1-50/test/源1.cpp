n = input()
numoff=0

while (n>1)
{
	if (n % 2 == 0)
	{
		n = n / 2;
		numof = numoff + 1;
	}
	if (n % 2 != 0)
	{
		n = 3 * n + 1;
		numof = numoff + 1;
	}
}
print numoff