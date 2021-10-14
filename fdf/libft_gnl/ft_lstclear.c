#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_el;

	if (lst)
	{
		while (*lst)
		{
			tmp_el = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp_el;
		}
	}
}
