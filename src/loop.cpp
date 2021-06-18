// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_loop(bview		&prg)
{
  if (bunny_get_keyboard()[BKS_LCONTROL] || bunny_get_keyboard()[BKS_RCONTROL])
    {
      int		x = 0;
      int		y = 0;

      if (bunny_get_keyboard()[BKS_LEFT])
	x -= bunny_get_delay() * 300;
      if (bunny_get_keyboard()[BKS_RIGHT])
	x += bunny_get_delay() * 300;
      if (bunny_get_keyboard()[BKS_UP])
	y -= bunny_get_delay() * 300;
      if (bunny_get_keyboard()[BKS_DOWN])
	y += bunny_get_delay() * 300;

      bview_move_picture(*prg.cursor, x, y);
    }
  if (bunny_get_keyboard()[BKS_LALT] || bunny_get_keyboard()[BKS_RALT])
    {
      double		rot = 0;

      if (bunny_get_keyboard()[BKS_LEFT])
	rot = -bunny_get_delay() * 180;
      if (bunny_get_keyboard()[BKS_RIGHT])
	rot = +bunny_get_delay() * 180;
      bview_turn_picture(*prg.cursor, rot);
    }

  if (prg.slideshow)
    {
      double		now = bunny_get_current_time();

      if (now - prg.slidestart >= prg.slidelen)
	{
	  prg.move_right();
	  prg.slidestart = now;
	}
    }
  return (GO_ON);
}

