// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

void			bview_move_picture(presentation	&p,
					   int		x,
					   int		y)
{
  p.position.x += x;
  p.position.y += y;
}
