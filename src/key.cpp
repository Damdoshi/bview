// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_key(t_bunny_event_state	state,
				  t_bunny_keysym	sym,
				  bview			&view)
{
  if (state == GO_DOWN)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  (void)view;
  return (GO_ON);
}

