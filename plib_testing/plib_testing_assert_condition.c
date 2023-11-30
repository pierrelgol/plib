#include "../plib.h"
#include <stdio.h>

int plib_testing_assert_condition(int condition, char *name)
{
	fprintf(stdout, "%16s : %s\n", name, (condition == 1 ? "pass" : "fail"));
	return (condition);
}
