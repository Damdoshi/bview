// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

bool			bview_toggle_fullscreen(bview	&v)
{
  t_bunny_size		siz = *bunny_get_screen_resolution();

  if (v.win)
    {
      if (v.win->buffer.width != siz.x || v.win->buffer.height != siz.y)
	{
	  bunny_stop(v.win);
	  if ((v.win = bunny_start_style(siz.x, siz.y, NO_BORDER, "bview")) == NULL)
	    {
	      fprintf(stderr, "bview: Cannot re-open window.\n");
	      return (false);
	    }
	  return (true);
	}
    }

  if (v.cursor == v.files.end())
    {
      siz.x *= 0.33;
      siz.y *= 0.33;
    }
  else
    {
      siz.x *= 0.8;
      siz.y *= 0.8;
      t_bunny_picture	*pic = v.pictures.back();

      v.cursor->zoom.x = 1.0;
      v.cursor->zoom.y = 1.0;
      if (siz.x < pic->buffer.width)
	{
	  v.cursor->zoom.x = ((double)siz.x) / pic->buffer.width;
	  v.cursor->zoom.y = v.cursor->zoom.x;
	}
      if (siz.y < pic->buffer.height * v.cursor->zoom.y)
	{
	  v.cursor->zoom.y = ((double)siz.y) / pic->buffer.height;
	  v.cursor->zoom.x = v.cursor->zoom.y;
	}

      siz.x = pic->buffer.width * v.cursor->zoom.x;
      siz.y = pic->buffer.height * v.cursor->zoom.y;
    }
  if (v.win)
    bunny_stop(v.win);
  if ((v.win = bunny_start(siz.x, siz.y, false, "bview")) == NULL)
    {
      fprintf(stderr, "bview: Cannot re-open window.\n");
      return (false);
    }
  return (true);
}
