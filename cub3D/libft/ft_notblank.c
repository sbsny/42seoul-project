/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notblank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunglee <sunglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:28:01 by sunglee           #+#    #+#             */
/*   Updated: 2023/02/06 13:28:03 by sunglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_notblank(int c)
{
	if (c > ' ' && c <= '~')
		return (1);
	return (0);
}
