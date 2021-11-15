#ifndef CMD_H
# define CMD_H

# include "minishell.h"

typedef struct s_cmd
{
	char	*builtin;
	char	**arg;
	bool	pipe;
	int		fdout;
	int		fdin;
}				t_cmd;

typedef struct s_env_l
{
	char	**list;
	char	***token;
}				t_env_l;

void		parse_cmd_array(t_cmd *cmd, t_env_l *env, int nb_cmd);
void		exec_builtin(int i, t_cmd *cmd, t_env_l *env, bool pipe);
int			single_pipe(int i, t_cmd *cmd, t_env_l *env);
static void	set_pipe(int i, t_cmd *cmd, t_env_l *env, int fds[3]);
int			multi_pipe(int i, t_cmd *cmd, t_env_l *env, int nb_pipe);



#endif