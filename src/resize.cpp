// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_resize(const t_bunny_window	*win,
				     const t_bunny_position	*siz,
				     bview			*v)
{
  (void)v;
  bunny_resize_window((t_bunny_window*)win, *siz);
  return (GO_ON);
}
