#include "get_next_line.h"

t_list  *ft_create_node_after_n(t_list *node)
{
    int size;
    int n;

    size = 0;
    n = -1;
    while (node->content[size] != '\0')
    {
        if (node->content[size] == '\n' && n < 0)
            n = size;
        size++;
    }
    if (n > -1 && n < size - 1)
        return (ft_create_node(node->content + n + 1, size - n - 1));
    return (NULL);
}

int ft_get_n_position(char *buffer, int size)
{
    int j;

    j = 0;
    if (size == -1)
    {
        while (buffer[j] != '\0')
        {
            if (buffer[j] == '\n')
                return (j);
            j++;
        }
    }
    else
    {
        while (j < size)
        {
            if (buffer[j] == '\n')
                return (j);
            j++;
        }
    }
    return (-1);
}

int ft_get_list_size_until_n(t_list *head)
{
    int size;
    int i;

    size = 0;
    while (head != NULL)
    {
        i = 0;
        while (head->content[i] != '\0')
        {
            size++;
            if (head->content[i] == '\n')
                break;
            i++;
        }
        head = head->next;
    }
    return (size);
}

char *ft_list_to_string(t_list **head, int size)
{
    char    *result;
    int     j;
    int     i;
    t_list  *temp;

    if (!*head)
        return (NULL);
    temp = *head;
    result = (char *)malloc((size + 1) * sizeof(char));
    if (!result)
        return (NULL);
    result[size] = '\0';
    j = 0;
    while (temp != NULL)
    {
        i = 0;
        while (temp->content[i] != '\0' && j < size)
            result[j++] = temp->content[i++];
        temp = temp->next;
    }
    *head = ft_lstclear(head);
    return (result);
}

char    *get_next_line(int fd)
{
    static t_list   *head;
    char            *buffer;
    int             bytes_read;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    if (head && ft_get_n_position(head->content, -1) != -1)
        return (ft_list_to_string(&head, ft_get_list_size_until_n(head)));
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    buffer[BUFFER_SIZE] = '\0';
    bytes_read = BUFFER_SIZE;
    while (bytes_read == BUFFER_SIZE)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
        {
            ft_lstadd_back(&head, ft_create_node(buffer, bytes_read));
            if (ft_get_n_position(buffer, bytes_read) != -1)
                break;
        }
    }
    free(buffer);
    return (ft_list_to_string(&head, ft_get_list_size_until_n(head)));
}
/*
int main(void)
{
    int fd = open("read_file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("%s", line);
    free(line);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
*/