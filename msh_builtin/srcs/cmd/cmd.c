#include "../../includes/minishell.h"

void	exec_builtin(int i, t_cmd *cmd, t_env_l *env, bool pipe)
{
	int		len;

	if (cmd[i].fdin == -1)
		return ;
	len = ft_strlen(cmd[i].builtin);
	if (ft_strncmp(cmd[i].builtin, "echo", len + 1) == 0)
		builtin_echo(i, cmd, pipe);
	else if (ft_strncmp(cmd[i].builtin, "cd", len + 1) == 0)
		builtin_cd(i, cmd, pipe, env);
	else if (ft_strncmp(cmd[i].builtin, "pwd", len + 1) == 0)
		builtin_pwd(i, cmd, pipe);
	else if (ft_strncmp(cmd[i].builtin, "export", len + 1) == 0)
		builtin_export(i, cmd, env, pipe);
	else if (ft_strncmp(cmd[i].builtin, "unset", len + 1) == 0)
		builtin_unset(i, cmd, env, pipe);
	else if (ft_strncmp(cmd[i].builtin, "env", len + 1) == 0)
		builtin_env(i, cmd, env, pipe);
	else if (ft_strncmp(cmd[i].builtin, "exit", len + 1) == 0)
		builtin_exit(i, cmd, pipe, env);
	else
		execpath(i, cmd, env, pipe);
}

void	parse_cmd_array(t_cmd *cmd, t_env_l *env, int nb_cmd)
{
	int		i;
	int		nb_pipe;

	i = 0;
	while (i < nb_cmd)
	{
		nb_pipe = 0;
		if (cmd[i].pipe == true)
		{
			while (cmd[i + nb_pipe].pipe == true)
				nb_pipe++;
			if (nb_pipe == 1 && cmd[i + 1].builtin != NULL)
				i = single_pipe(i, cmd, env);
			else if (nb_pipe > 1)
				i = multi_pipe(i, cmd, env, nb_pipe);
			if (i >= nb_cmd)
				break ;
		}
		exec_builtin(i, cmd, env, false);
		i++;
	}
}