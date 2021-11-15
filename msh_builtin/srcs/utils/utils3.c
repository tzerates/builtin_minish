#include "../../includes/minishell.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	free_split_join(char **split, char *join)
{	
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(join);
}

void	init_token(t_env_l *env)
{
	char	**var_contents;
	int		i;
	int		j;

	env->token = malloc(sizeof(char **) * (nb_env(env->list) + 1));
	var_contents = get_env_content(env->list);
	i = 0;
	while (var_contents[i])
	{
		env->token[i] = ft_split(var_contents[i], ' ');
		i++;
	}
	env->token[i] = NULL;
	i = 0;
	while (var_contents[i])
	{
		free(var_contents[i]);
		i++;
	}
	free(var_contents);
}
