/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:10:40 by gdara             #+#    #+#             */
/*   Updated: 2022/03/08 14:10:40 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
** Close open files and pipe ends
*/

static void	close_all(t_data *data, int *fd)
{
	close(data->in);
	close(data->out);
	close(fd[0]);
	close(fd[1]);
}

/*
** From the input get the names of the commands
** Find the right path to the command.
** If it is zero, the command was not found. If non-zero, execute execve
*/

static void	execution(char *argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*path;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (path == 0)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
		error("\033[31mProblems with execution\e[0m\n");
	}
	if (execve(path, cmd, envp) == -1)
		error("\033[31mProblems with execution\e[0m\n");
}

/*
** Assign child1 to execute cmd1:
** dup2 close stdin, data->in becomes the new stdin
** dup2 close stdout, fd[1] becomes the new stdout
*/

static void	child_one(t_data *data, int *fd, char **argv, char **envp)
{
	dup2(data->in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_all(data, fd);
	execution(argv[2], envp);
	error("\033[31mProblems with child_one\e[0m\n");
}

/*
** Assign child2 to execute cmd2:
** dup2 close stdout, data->out becomes the new stdout
** dup2 close stdin, fd[0] becomes the new stdin
*/

static void	child_two(t_data *data, int *fd, char **argv, char **envp)
{
	dup2(data->out, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close_all(data, fd);
	execution(argv[3], envp);
	error("\033[31mProblems with child_one\e[0m\n");
}

/*
** With one child and one parent process, pipex will work,
** but it is not super protected. 
** Since the two processes happen at the same time, if one segfaults, 
** the error will be sent to the other.
** If instead we divide the workload on different children, 
** the parent can just wait for the job 
** to be done and supervise the children’s status.
*/

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		fd[2];

	if (argc == 5)
	{
		data.in = open(argv[1], O_RDONLY);
		data.out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		if (data.in == -1 || data.out == -1)
			error("\033[31mCan't open\e[0m\n");
		if (pipe(fd) < 0)
			error("\033[31mThe pipe broke\e[0m\n");
		data.parent1 = fork();
		if (data.parent1 == 0)
			child_one(&data, fd, argv, envp);
		data.parent2 = fork();
		if (data.parent2 == 0)
			child_two(&data, fd, argv, envp);
		close_all(&data, fd);
		waitpid(data.parent1, NULL, 0);
		waitpid(data.parent2, NULL, 0);
		return (0);
	}
	else
		error("\033[31mWrong count of argumens\e[0m\n");
}
