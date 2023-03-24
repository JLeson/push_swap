/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:46:25 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/24 15:48:45 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#define TOP 2
#define MID 1
#define BOTTOM 0

static int	iscase(t_stack *a, int ilarge, int imid, int ismall)
{
	if (!(stackget(a, ilarge) > stackget(a, imid)))
		return (FALSE);
	if (!(stackget(a, ilarge) > stackget(a, ismall)))
		return (FALSE);
	if (!(stackget(a, ismall) < stackget(a, imid)))
		return (FALSE);
	return (TRUE);
}

void	minisort(t_stack *a, t_stack *b)
{
	if (iscase(a, BOTTOM, TOP, MID))
		exec(SA, a, b);
	else if (iscase(a, TOP, BOTTOM, MID))
		exec(RA, a, b);
	else if (iscase(a, MID, TOP, BOTTOM))
		exec(RRA, a, b);
	else if (iscase(a, TOP, MID, BOTTOM))
	{
		exec(SA, a, b);
		exec(RRA, a, b);
	}
	else if (iscase(a, MID, BOTTOM, TOP))
	{
		exec(SA, a, b);
		exec(RA, a, b);
	}
}
