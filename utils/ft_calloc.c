#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_s;

	total_s = count * size;
	ptr = malloc(total_s);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_s);
	return (ptr);
}
