# include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (argc < 2)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(argv[i])
		{
			while (argv[i][j])
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
			j = 0;
		}
		std::cout << std::endl;
	}
}