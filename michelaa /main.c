#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main ()
{
	int fd;
	int ret;
	char	*str;

	fd = open("/Users/jfabi/Desktop/cursus_42/copia/43_no_nl", O_RDONLY | O_APPEND);
	ret = get_next_line(fd, &str);
	while (ret > 0)
	{
		printf("Valore di ritorno: %d\n", ret);
		printf("%s\n", str);
		ret =  get_next_line(fd, &str);
	}
		printf("Valore di ritorno: %d\n", ret);
		printf("%s\n", str);
	return (0);
}
