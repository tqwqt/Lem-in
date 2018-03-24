#include <stdlib.h>

void	leak()
{
	char *leaks;

	leaks = malloc(100);
}

void	ex()
{
	int i = 0;
	while(2)
		i = i;
	exit(7);
}
int		main(void)
{	
	int i;

	i = 0;
	leak();
	ex();
	return(0);
}
