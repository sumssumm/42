#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	child_signal(int sig)
{
	if (sig == SIGTERM)
	{
		printf("Child: I got SIGTERM\n");
		exit(0);
	}
	else
	{
		printf("Child: I got other signal\n");
		exit(1);
	}
}

void	parent_signal(int sig)
{
	pid_t	ret;

	if (sig != SIGCHLD)
		exit(1);
	ret = waitpid(-1, NULL, WNOHANG);
	printf("Parent: Child successfully terminated\n");
	exit(0);
}

int	main(void)
{
	int		i;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		signal(SIGTERM, child_signal);
		while (1)
			;
	}
	else
	{
		signal(SIGCHLD, parent_signal);
		i = 5;
		while (i--)
		{
			printf("Parent: Signal will be sent in %d seconds\n", i + 1);
			usleep(1000 * 1000);
		}
		if (kill(pid, SIGTERM) == -1)
			return (1);
		while (1)
			;
	}
	return (0);
}