// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_wheel(int			wheelid,
				    int			delta,
				    bview		&prg)
{
  (void)wheelid;
  (void)delta;
  (void)prg;
  return (GO_ON);
}

