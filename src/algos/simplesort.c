/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:06:41 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/23 16:46:24 by fsarkoh          ###   ########.fr       */
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
		return (0);
	if (!(stackget(a, ilarge) > stackget(a, ismall)))
		return (0);
	if (!(stackget(a, ismall) < stackget(a, imid)))
		return (0);
	return (1);
}

static void	sort3(t_stack *a, t_stack *b)
{
	if (iscase(a, BOTTOM, TOP, MID))
		exec(SA, a, b);
	if (iscase(a, TOP, BOTTOM, MID))
		exec(RA, a, b);
	if (iscase(a, MID, TOP, BOTTOM))
		exec(RRA, a, b);
	if (iscase(a, TOP, MID, BOTTOM))
	{
		exec(SA, a, b);
		exec(RRA, a, b);
	}
	if (iscase(a, MID, BOTTOM, TOP))
	{
		exec(SA, a, b);
		exec(RA, a, b);
	}
}

void	simplesort(t_stack *a, t_stack *b)
{
	sort3(a, b);
}
