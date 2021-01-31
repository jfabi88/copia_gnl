#include "get_next_line.h"

void	ft_cambio(char *line)
{
	*line = "ross";
}

int	main()
{
	char	*line;

	line = malloc(5);
	ft_cambio(line);
	printf("la linea e %s\n", line);
}
