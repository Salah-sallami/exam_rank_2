#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    t_list *tmp = begin_list;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return i;

}