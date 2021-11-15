#ifndef UTILS_H
# define UTILS_H 

# include "minishell.h"

// UTILS1

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int	    ft_strclen(const char *str, char c);
size_t	ft_strlen(const char *str);

// UTILS2

int	    ft_isascii(int c);
int	    ft_str_isdigit(char *str);
int	    ft_strcmp(char *s1, char *s2);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int	    ft_atoi(const char *nptr);

// UTILS3

int     ft_isalnum(int c);
void	free_split_join(char **split, char *join);
void	init_token(t_env_l *env);

// ENV_UTILS1

void	free_token(t_env_l *env);
void	envdup(char **env_list, char **tmp);
void	envdup_n_change(char **tmp, char **env_list, char *change, int exist);
void	change_env_var(t_env_l *env, int len, int exist, char *change);
void	add_env_var(t_env_l *env, int len, char *add);

//ENV_UTILS2

void	envdup_plus(char **env_list, char **tmp, char *plus);
void	envdup_without(char **env_list, char **tmp, int without);
int	    check_equal(char *var_name, char **env_list);
void	display_env(t_cmd cmd, char **var_names);

//ENV_UTILS3
char	*ft_getenv(char *var_name, char **env_list);
int	    count_arg(t_cmd cmd);
int	    nb_env(char **env_list);
void	free_env(int nb_env, char **env_list);

#endif