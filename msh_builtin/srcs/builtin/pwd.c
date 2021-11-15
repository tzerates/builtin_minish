#include "../../includes/minishell.h"

void	builtin_pwd(int i, t_cmd *cmd, bool pipe)
{
	char	*buff;

	buff = NULL;
	buff = getcwd(buff, PATH_MAX_SHELL);
	g_err = 0;
	write (cmd[i].fdout, buff, ft_strlen(buff));
	write (cmd[i].fdout, "\n", 1);
	free(buff);
	if (pipe == true)
		exit(1);
}