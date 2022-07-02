/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:19:00 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/02 19:24:41 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//-------------------------------------------------- heredoc main function creation
void    heredoc_first(t_shell *shell)
{
	int files_number;

	files_number = file_number(shell->data);
	create_files(files_number);
	
}
//--------------------------------------- count number of files we have
int file_number(t_data *data)
{
   t_data *backup;
   int pipe;
   int count = 0;
   int only;

   pipe = 0;
   only = 0;
   backup = data;
   while(backup)
   {
		if(pipe == 0 && backup->token == PIPE)
		{
			only = 0;
			pipe = 1;
		}
		if(pipe == 1 && backup->token == PIPE)
			pipe = 0;
		if(backup->token == HEREDOC && pipe == 0)
		{
			if(only == 0)
			{
				only = 1;
				count++;
			}
		}
	   backup = backup->next;
   }  
   return (count);
}
//-----------------------------------------------
void create_files(int number)
{
	int i;
	char *name;
	char *num;

	i = 1;
	name = NULL;
	num = NULL;
	while(i <= number)
	{
		num = ft_itoa(i);
		name = ft_strjoin("/tmp/.", num);
		open(name, O_RDWR | O_CREAT | O_TRUNC, 0666);
		free(name);
		free(num);
		i++;
	}
}