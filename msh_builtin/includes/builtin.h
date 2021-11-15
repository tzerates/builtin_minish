#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

void		execpath(int index, t_cmd *cmd, t_env_l *env, bool pipe);
void		execpath_pipe(t_cmd *cmd, int i, t_env_l *env);
void		builtin_echo(int index, t_cmd *cmd, bool pipe);
void		builtin_cd(int index, t_cmd *cmd, bool pipe, t_env_l *env);
void		builtin_pwd(int index, t_cmd *cmd, bool pipe);
void		builtin_export(int index, t_cmd *cmd, t_env_l *env, bool pipe);
void		builtin_unset(int index, t_cmd *cmd, t_env_l *env, bool pipe);
void		builtin_env(int index, t_cmd *cmd, t_env_l *env, bool pipe);
void		builtin_exit(int index, t_cmd *cmd, bool pipe, t_env_l *env);

#endif