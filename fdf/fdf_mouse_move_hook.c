/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_move_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:29:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/06/11 16:13:42 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move_hook(int x, int y, void *param)
{
	t_event	*event;

	event = &((t_vars *)param)->event;
	if (0 == event->mouse_move)
	{
		event->mouse_pos = (t_point2d){x, y};
		event->mouse_move = 1;
	}
	else if ((event->mouse_pos.x + 20 < x || event->mouse_pos.x - 20 > x \
	|| event->mouse_pos.y + 20 < y || event->mouse_pos.y - 20 > y) \
	&& 1 == event->left_click)
	{
		if (event->mouse_pos.x + 20 < x)
			rotate_object((t_vars *)param, rotate_y, ((M_PI * 10) / 180));
		else if (event->mouse_pos.x - 20 > x)
			rotate_object((t_vars *)param, rotate_y, -((M_PI * 10) / 180));
		if (event->mouse_pos.y + 20 < y)
			rotate_object((t_vars *)param, rotate_x, -((M_PI * 10) / 180));
		else if (event->mouse_pos.y - 20 > y)
			rotate_object((t_vars *)param, rotate_x, ((M_PI * 10) / 180));
		event->mouse_pos = (t_point2d){x, y};
		draw_next_frame((t_vars *)param);
	}
	return (0);
}

int	mouse_button_press_hook(int button, int x, int y, void *param)
{
	t_event	*event;

	(void)x;
	(void)y;
	event = (t_event *)param;
	if (1 == button)
		event->left_click = 1;
	return (0);
}

int	mouse_button_release_hook(int button, int x, int y, void *param)
{
	t_event	*event;

	(void)x;
	(void)y;
	event = (t_event *)param;
	if (1 == button)
		event->left_click = 0;
	return (0);
}
