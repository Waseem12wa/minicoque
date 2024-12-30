#include "../../include/minishell.h"


char **split_quote(const char *line) 
{
    size_t len = strlen(line);
    char **tab = malloc((len + 1) * sizeof(char *));
    size_t j = 0, i = 0, start = 0;
    bool in_quotes = FALSE;
    char quote_char = '\0';

    while (i <= len) 
    {
        if (line[i] == '\'' || line[i] == '\"') 
        {
            if (in_quotes && line[i] == quote_char) 
            {
                tab[j++] = ft_strndup(&line[start], i - start + 1);
                start = i + 1;
                in_quotes = FALSE;
            } 
            else if (!in_quotes) 
            {
                if (i > start)
                    tab[j++] = ft_strndup(&line[start], i - start);
                quote_char = line[i];
                in_quotes = TRUE;
                start = i;
            }
        } 
        else if (!in_quotes && (line[i] == ' ' || line[i] == '\0')) 
        {
            if (i > start) 
                tab[j++] = ft_strndup(&line[start], i - start);
            start = i + 1; 
        }
        i++;
    }
    if (start < len)
        tab[j++] = ft_strndup(&line[start], i - start);
    tab[j] = NULL;
    return tab;
}