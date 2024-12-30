#include "../../include/minishell.h"

void add_token(char **result, int *j, char *start, char *end) 
{
    int len;
    
    len = end - start + 1;
    result[*j] = ft_calloc(len + 1, sizeof(char));
    ft_strlcpy(result[*j], start, len);
    result[*j][len] = '\0';
    (*j)++;
}

char **split_sep(char **input, const char *separators) 
{
    char *str;
    char **result;
    int j;
    char *start;
    char *end;
    bool in_quotes;
    
    if (!input || !*input || !separators)
        return NULL;
    str = *input;
    result = ft_calloc(ft_strlen(str), sizeof(char *));
    if (!result) 
        return NULL;
    j = 0;
    start = str;
    in_quotes = FALSE;

    while (*start) {
        if (*start == '\'' || *start == '\"') 
        {
            in_quotes = !in_quotes;
        }
        if (!in_quotes && ft_strchr(separators, *start)) 
        {
            if (start > str) 
            {
                char *end = start - 1;
                while (end > str && *end == ' ') 
                    end--;
                add_token(result, &j, str, end);
            }
            str = start + 1;
        }
        start++;
    }
    if (str < &str[ft_strlen(str)]) 
    {
        while (*str == ' ') 
            str++;
        end = str + ft_strlen(str) - 1;
        while (end > str && *end == ' ') 
            end--;
        if (str <= end) {
            add_token(result, &j, str, end);
        }
    }
    result[j] = NULL;
    return result;
}
void	free_split(char **tab)
{
    int	i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}