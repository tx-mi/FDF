#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*curr_el;

	if (!lst)
		return (0);
	size = 1;
	curr_el = lst->next;
	while (curr_el)
	{
		curr_el = curr_el->next;
		size++;
	}
	return (size);
}
