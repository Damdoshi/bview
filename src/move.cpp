// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_move(const t_bunny_position	*off,
				   bview			&prg)
{
  (void)off;
  (void)prg;
  return (GO_ON);
}

