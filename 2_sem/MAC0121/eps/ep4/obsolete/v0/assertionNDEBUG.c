#define NDEBUG
#include <assert.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x = 7;
	assert (x == 5);

	printf("%d\n", x);

	return 0;
}