#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct lnk_list
{
    char            *content;
    struct lnk_list *next;
}t_list;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

t_list  *ft_lstnew(char *content);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_create_node(char *buffer, int size);
t_list  *ft_create_node_after_n(t_list *node);
t_list  *ft_lstclear(t_list **lst);
int     ft_get_n_position(char *buffer, int size);
int     ft_get_list_size_until_n(t_list *head);
char    *ft_list_to_string(t_list **head, int size);
char    *get_next_line(int fd);

#endif
