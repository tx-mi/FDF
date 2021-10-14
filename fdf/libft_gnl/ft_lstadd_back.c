#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_el;

	if (*lst)
	{
		last_el = ft_lstlast(*lst);
		last_el->next = new;
	}
	else
		*lst = new;
}
