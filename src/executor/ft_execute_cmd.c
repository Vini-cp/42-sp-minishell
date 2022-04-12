/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:36:14 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/12 03:55:54 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_execute_cmd()
{
	//save in/out
 	int tmpin=dup(0);
 	int tmpout=dup(1);
 
 	//set the initial input 
 	int fdin;
 	if (infile)
	{
 		fdin = open(infile, O_READ); 
	}
	else
	{
		// Use default input
		fdin=dup(tmpin);
	}

	int ret;
	int fdout;
	for	(i=0; i<numsimplecommands; i++)
	{
		//redirect input
		dup2(fdin, 0);
		close(fdin);
		//setup output
		if (i == numsimplecommands - ­1)
		{
			// Last simple command 
			if(outfile)
			{
				fdout=open(outfile,â€¦â€¦);
			}
			else
			{
				// Use default output
				fdout=dup(tmpout);
			}
		}
		else
		{
			// Not last
			//simple command
			//create pipe
			int fdpipe[2];
			pipe(fdpipe);
			fdout=fdpipe[1];
			fdin=fdpipe[0];
		}// if/else
		// Redirect output
		fdout=open(outfile,â€¦â€¦);
		dup2(fdout,1);
		close(fdout);
		
		// Create child process
		ret=fork(); 
		if (ret==0)
		{
			execvp(scmd[i].args[0], scmd[i].args);
			perror(â€œexecvpâ€);
			_exit(1);
		}
	}
	//restore in/out defaults
	dup2(tmpin,0);
	dup2(tmpout,1);
	close(tmpin);
	close(tmpout);

	if (!background)
	{
		// Wait for last command
		waitpid(ret, NULL);
	}
}
