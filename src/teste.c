#include "../include/shell.h"

void ft_printtokens(t_shell *mshell)
{
	t_token	*temp;

	temp = mshell->firsttoken;

	while (temp)
	{
		printf("TOKEN:%s\n", temp->token);
		temp = temp->next;
	}
	return ;
}

void ft_freetokens(t_shell *mshell)
{
	t_token	*temp;
	t_token	*temp2;

	temp = mshell->firsttoken;
	while (temp)
	{
		free(temp->token);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	return ;
}