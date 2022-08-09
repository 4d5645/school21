/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:20:40 by gdara             #+#    #+#             */
/*   Updated: 2022/03/08 14:20:40 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
** Get an array of pointers without part "PATH"
*/

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

/*
** From the array of pointers to environment variables get a part without "PATH"
** Get paths separated by ':'
** Check the accessibility of the file named by the path argument for the access
** permissions indicated by the mode argument (existence in our case)
*/

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*part_path;

	i = 0;
	paths = ft_split(get_path(envp), ':');
	while (*paths)
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		paths++;
	}
	i = 0;
	while (paths[i++])
		free(paths[i]);
	free(paths);
	return (0);
}
