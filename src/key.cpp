// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		<sstream>
#include		"bview.hpp"

extern "C"
t_bunny_response	bview_wheel(int			wheelid,
				    int			delta,
				    bview		&prg);

extern "C"
t_bunny_response	bview_key(t_bunny_event_state	state,
				  t_bunny_keysym	sym,
				  bview			&view)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);

  if (sym == BKS_F1)
    {
      if (view.cursor != view.files.end())
	bview_message(view, view.cursor->file);
    }
  if (sym == BKS_F5)
    {} // REFRESH
  else if (sym == BKS_ADD)
    {
      std::stringstream ss;

      view.slidelen += 0.25;
      ss << "slide delay " << view.slidelen;
      bview_message(view, ss.str());
    }
  else if (sym == BKS_SUBTRACT)
    {
      std::stringstream ss;
      
      if ((view.slidelen -= 0.25) < 0.25)
	view.slidelen = 0.25;
      ss << "slide delay " << view.slidelen;
      bview_message(view, ss.str());
    }
  else if (sym == BKS_RETURN)
    {
      if (bunny_get_keyboard()[BKS_LALT] || bunny_get_keyboard()[BKS_RALT])
	bview_toggle_fullscreen(view);
      else if (bunny_get_keyboard()[BKS_LCONTROL] || bunny_get_keyboard()[BKS_RCONTROL])
	bview_reset(view);
      else
	{
	  view.slidestart = bunny_get_current_time();
	  view.slideshow = !view.slideshow;
	}
    }
  else if (sym == BKS_F11)
    bview_toggle_fullscreen(view);
  
  if (bunny_get_keyboard()[BKS_LCONTROL] || bunny_get_keyboard()[BKS_RCONTROL])
    {
      
    }
  else if (bunny_get_keyboard()[BKS_LSHIFT] || bunny_get_keyboard()[BKS_RSHIFT])
    {
      if (view.cursor == view.files.end())
	return (GO_ON);
      if (sym == BKS_LEFT || sym == BKS_RIGHT)
	bview_multiply_scale(*view.cursor, -1, 1);
      if (sym == BKS_UP || sym == BKS_DOWN)
	bview_multiply_scale(*view.cursor, 1, -1);
    }
  else if (bunny_get_keyboard()[BKS_LALT] || bunny_get_keyboard()[BKS_RALT])
    {
      if (view.cursor == view.files.end())
	return (GO_ON);
      if (sym == BKS_UP)
	bview_turn_picture(*view.cursor, -90);
      else if (sym == BKS_DOWN)
	bview_turn_picture(*view.cursor, +90);
    }
  else
    {
      if (sym == BKS_LEFT)
	view.move_left();
      else if (sym == BKS_RIGHT)
	view.move_right();
      else if (sym == BKS_UP)
	bview_wheel(0, 1, view);
      else if (sym == BKS_DOWN)
	bview_wheel(0, -1, view);
      else if (sym == BKS_SPACE)
	{
	  if (view.cursor == view.files.end())
	    return (GO_ON);
	  view.cursor->fitted = (presentation::DisplayType)(view.cursor->fitted + 1);
	  if (view.cursor->fitted == presentation::TRUE_RES)
	    {
	      t_bunny_picture *pic = view.pictures.back();

	      if (pic->buffer.width < view.win->buffer.width &&
		  pic->buffer.height < view.win->buffer.height)
		view.cursor->fitted = (presentation::DisplayType)(view.cursor->fitted + 1);
	    }
	  if (view.cursor->fitted >= presentation::MANUAL)
	    view.cursor->fitted = presentation::FULLFIT;

	  std::stringstream ss;

	  if (view.cursor->fitted == presentation::TRUE_RES)
	    ss << "true resolution";
	  else if (view.cursor->fitted == presentation::FULLFIT)
	    ss << "contain";
	  else if (view.cursor->fitted == presentation::COVER)
	    ss << "cover";
	  bview_message(view, ss.str());	  
	}
    }
  return (GO_ON);
}

