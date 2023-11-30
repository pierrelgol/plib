
#include "../plib.h"

char	*plib_testing_fstring_generator(char *around, char *inside, int length)
{
	char	*result;
	int	i;
	int	ch;

	result = plib_memory_alloc(length + 1, sizeof(char));
	i = 0;
	while (i < length)
	{
		if (i < (length /3) || i > ((length / 3) * 2))
		{
			ch = rand() % 255;
			while (around[ch] == 0)
				ch = rand() % 255;
			result[i++] = ch;
		}
		else
		{
			ch = rand() % 255;
			while (inside[ch] == 0)
				ch = rand() % 255;
			result[i++] = ch;
		}
	}
	return (result);
}

