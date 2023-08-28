/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:42:05 by pvilchez          #+#    #+#             */
/*   Updated: 2023/07/25 19:32:43 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpipex.h"

void	f_child(char **argv, int *pipex_fd)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	dup2(pipex_fd[1], 1);
	dup2(fd_in, 0);
	close(pipex_fd[0]);
	char *argv1[] = {"comando1", NULL};
	execve(argv1[0], argv1, NULL);
	perror(argv[2]);
	exit(1);
}

void	f_parent(char **argv, int *pipex_fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
	{
		perror(argv[4]);
		exit(1);
	}
	dup2(pipex_fd[0], 0);
	close(pipex_fd[0]);
	dup2(fd_out, 1);
	close(fd_out);
	char *argv2[] = {"comando2", NULL};
	execve(argv2[0], argv2, NULL);
	perror(argv[3]);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipex_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_printf("Usage: %s file1 command1 command2 file2\n", argv[0]);
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
		f_child(argv, pipex_fd);
	waitpid(pid, NULL, 0);
	f_parent(argv, pipex_fd);
	return (0);
}
