/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:25:58 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/03 14:18:52 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int str)
{
	if (str >= 48 && str <= 57)
		return (1);
	else
		return (0);
}