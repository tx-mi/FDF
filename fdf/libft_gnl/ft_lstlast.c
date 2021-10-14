#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_el;

	if (!lst)
		return (NULL);
	last_el = lst;
	while (last_el->next)
		last_el = last_el->next;
	return (last_el);
}
