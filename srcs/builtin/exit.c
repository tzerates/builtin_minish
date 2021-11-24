/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:37:31 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/11/24 01:48:25 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	get_arg_size(int i, t_cmd *cmd)
{
	int	size;

	size = 0;
	while (cmd[i].arg[size])
		size++;
	return (size);
}

void	builtin_exit(int i, t_cmd *cmd, int pipe, t_env_l *env)
{
	int		size;

	size = get_arg_size(i, cmd);
	if (size == 1)
	{
		printf("%s\n", cmd[i].builtin);
		exit_free_env(env, 0);
	}
	if (size > 2 && ft_str_isdigit(cmd[i].arg[1]) == 1)
	{
		write (2, "exit\nToo many arguments\n", 25);
		retval = 1;
		return ;
	}
	if (pipe == 0)
		printf("%s\n", cmd[i].builtin);
	if (ft_str_isdigit(cmd[i].arg[1]) == 0 || cmd[i].arg[1][0] == '\0')
	{
		printf("exit: %s: Numeric argument required\n", cmd[i].arg[1]);
		exit_free_env(env, ft_atoi(cmd[i].arg[1]));
	}
	if (cmd[i].arg[1][0] == '-')
		exit_free_env(env, 255 - (ft_atoi(cmd[i].arg[1]) * -1) + 1);
	else
		exit_free_env(env, ft_atoi(cmd[i].arg[1]));
}
