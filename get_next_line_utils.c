#include "get_next_line.h"

t_list  *ft_lstnew(char *content)
{
    t_list  *node;

    node = malloc(sizeof(t_list) * 1);
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;
    if (!lst)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    last = *lst;
    while (last->next)
        last = last->next;
    last->next = new;
}

t_list  *ft_lstclear(t_list **lst)
{
    t_list *temp;
    t_list *head;
    t_list *node;

    if (!lst)
        return (NULL);
    head = *lst;
    while (head != NULL)
    {
        temp = head->next;
        if (temp == NULL)
            node = ft_create_node_after_n(head);
        free(head->content);
        free(head);
        head = temp;
    }
    return (node);
}

t_list  *ft_create_node(char *buffer, int size)
{
    t_list *node;
    char *content;
    content = (char *)malloc((size + 1) * sizeof(char));
    if (!content)
        return (NULL);
    content[size] = '\0';
    while (--size >= 0)
    {
        content[size] = buffer[size];
    }
    node = ft_lstnew(content);
    if (!node)
    {
        free(content);
        return (NULL);
    }
    return (node);
}