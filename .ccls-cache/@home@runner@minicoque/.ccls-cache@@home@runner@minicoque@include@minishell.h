/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:35:05 by grouger           #+#    #+#             */
/*   Updated: 2024/10/08 14:46:05 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void starting_message(void);

// GNL
char *ft_strjoin(char *s1, char *s2, int b_read);
int ft_strlen(const char *str);
char *ft_strchr(const char *str, char c);
char *get_next_line(int fd);
char *get_line(char *stash);
char *ft_free(char *stash, char *buffer, char *str);
char *ft_substr(char const *s, int start, int len);
char *ft_strdup(const char *s);

typedef struct s_token {
  char *str;
  int type;
  struct s_token *prev;
  struct s_token *next;
} t_token;

// typedef struct s_data {

#define INPUT 1 "<"
#define HEREDOC 2 //"<<"
#define TRUNC 3   //">"
#define APPEND 4  //">>"
#define PIPE 5    //"|"
#define CMD 6     //"|"
#define ARG 7     //"|"

// Reset
#define Reset \033[0m

// Regular Colors
#define Black '\033[0;30m'
#define Red '\033[0;31m'
#define Green '\033[0;32m'
#define Yellow '\033[0;93m'
#define Blue '\033[0;34m'
#define Purple '\033[0;35m'
#define Cyan \033[0;36m
#define White '\033[0;37m'

// Bold
#define BBlack '\033[1;30m'
#define BRed '\033[1;31m'
#define BGreen '\033[1;32m'
#define BYellow '\033[1;33m'
#define BBlue '\033[1;34m'
#define BPurple '\033[1;35m'
#define BCyan '\033[1;36m'
#define BWhite '\033[1;37m'

// Background
#define On_Black '\033[40m'
#define On_Red '\033[41m'
#define On_Green '\033[42m'
#define On_Yellow '\033[43m'
#define On_Blue '\033[44m'
#define On_Purple '\033[45m'
#define On_Cyan '\033[46m'
#define On_White '\033[47m'

#endif