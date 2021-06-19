// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_key(t_bunny_event_state	state,
				  t_bunny_keysym	sym,
				  bview			&view);

extern "C"
t_bunny_response	bview_click(t_bunny_event_state	state,
				    t_bunny_mouse_button but,
				    bview		&view)
{
  if (state == GO_DOWN && but == BMB_MIDDLE)
    return (bview_key(GO_DOWN, BKS_SPACE, view));
  if (but == BMB_LEFT)
    {
      if (state == GO_DOWN)
	{
	  if (view.cursor == view.files.end())
	    return (GO_ON);
	  view.down_position = *bunny_get_mouse_position();
	  view.cursor->before_click_rot = view.cursor->rotation;
	  view.cursor->before_click_pos = view.cursor->position;
	  view.down_in = true;
	}
      else
	view.down_in = false;
    }
  return (GO_ON);
}

