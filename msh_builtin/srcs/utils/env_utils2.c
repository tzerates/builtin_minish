#include "../../includes/minishell.h"

void	envdup_plus(char **env_list, char **tmp, char *plus)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		env_list[i] = ft_strdup(tmp[i]);
		i++;
	}
	env_list[i] = ft_strdup(plus);
	i++;
	env_list[i] = NULL;
}

void	envdup_without(char **env_list, char **tmp, int without)
{
	int	i;

	i = 0;
	while (i < without)
	{
		tmp[i] = ft_strdup(env_list[i]);
		i++;
	}
	while (env_list[i + 1])
	{
		tmp[i] = ft_strdup(env_list[i + 1]);
		i++;
	}
	tmp[i] = NULL;
}

int	check_equal(char *var_name, char **env_list)
{
	int	i;

	i = 0;
	while (env_list[i])
	{
		if (ft_strcmp(var_name, env_list[i]) == 0)
		{
			if (ft_strclen(env_list[i], '=') == -1)
				return (-1);
		}
		else if (ft_strncmp(var_name, env_list[i], ft_strlen(var_name)) == 0)
		{
			if (ft_strclen(env_list[i], '=') > 0
				&& ft_strclen(env_list[i], '=') == (int)ft_strlen(env_list[i]))
				return (-2);
		}
		i++;
	}
	return (1);
}

void	display_env(t_cmd cmd, char **var_names
	, char **var_contents, t_env_l *env)
{
	int	i;
	int	equal;

	i = 0;
	while (var_names[i])
	{
		equal = 0;
		write(cmd.fdout, "declare -x ", 11);
		write(cmd.fdout, var_names[i], ft_strlen(var_names[i]));
		if (check_equal(var_names[i], env->list) == -1)
			equal = -1;
		else if (check_equal(var_names[i], env->list) == -2)
			equal = -2;
		if (equal != -1)
		{
			write(cmd.fdout, "=", 1);
			write(cmd.fdout, "\"", 1);
			write(cmd.fdout, var_contents[i], ft_strlen(var_contents[i]));
			write(cmd.fdout, "\"", 1);
		}
		write(cmd.fdout, "\n", 1);
		i++;
	}
}