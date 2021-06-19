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
  if (prg.cursor == prg.files.end())
    return (GO_ON);
  while (delta > 0)
    {
      prg.cursor->zoom.x = prg.cursor->zoom.y *= 0.9;
      prg.cursor->fitted = presentation::MANUAL;
      delta -= 1;
    }
  while (delta < 0)
    {
      prg.cursor->zoom.x = prg.cursor->zoom.y *= 1.1;
      prg.cursor->fitted = presentation::MANUAL;
      delta += 1;
    }
  return (GO_ON);
}

