/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/21 16:56:17 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_rotateplayer(int32_t mouse_x, t_prog *prog)
{
	int	ret;

	ret = 0;
	prog->player.dir += SENSIVITY * (mouse_x - prog->mouse_x);
	if (prog->player.dir >= M_PI * 2 || prog->player.dir <= -M_PI * 2)
		prog->player.dir = 0;
	if (prog->mouse_x != mouse_x)
		ret = 1;
	prog->mouse_x = mouse_x;
	c3d_refresh(prog);
	return (ret);
}

int	c3d_moveplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	x = prog->player.x + spd * cos(prog->player.dir);
	y = prog->player.y + spd * sin(prog->player.dir);
	if (correct_pos(x, y, spd, prog))
	{
		puts("Correct pos");
		prog->player.x = x;
		prog->player.y = y;
		return (1);
	}
	if (correct_pos(x, prog->player.y, spd, prog)) // on teste avec l'ancien y
	{
		if (spd * sin(prog->player.dir) < 0) // si on essaie de monter
		{
			puts("Je veux aller en haut");
			prog->player.y = (int) prog->player.y + PLAYER_SCALE * 0.5; //on colle le perso sous le mur du haut
		}
		else // si on essaie de descendre
		{
			puts("Je veux aller en bas");
			prog->player.y = (int) prog->player.y + 1 - PLAYER_SCALE * 0.5; // on colle le perso au dessus du mur du bas
		}
		prog->player.x = x; // slide sur x
		return (1);
	}
	if (correct_pos(prog->player.x, y, spd, prog)) // on teste avec l'ancien x
	{
		if (spd * cos(prog->player.dir) < 0) // si on essaie d'aller a gauche
			prog->player.x = (int) prog->player.x + PLAYER_SCALE * 0.5; // on colle le perso apres le mur de gauche
		else // si on essaie d'aller a droite
			prog->player.x = (int) prog->player.x + 1 - PLAYER_SCALE * 0.5; // on colle le perso avant le mur de droite
		prog->player.y = y; // slide sur y
		return (1);
	}
	return (1);
}
