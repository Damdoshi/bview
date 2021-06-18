// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

void			bview_multiply_scale(presentation	&p,
					     double		x,
					     double		y)
{
  p.zoom.x *= x;
  p.zoom.y *= y;
}
