// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_click(t_bunny_event_state	state,
				    t_bunny_mouse_button but,
				    bview		&view)
{
  if (state == GO_DOWN)
    return (GO_ON);
  (void)but;
  (void)view;
  return (GO_ON);
}

