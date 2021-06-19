// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
t_bunny_response	bview_display(bview		&prg)
{
  // On remplit l'écran de la couleur issu de la configuration
  // ou de noir, en attendant qu'il y ai de la configuration...
  bunny_clear(&prg.win->buffer, BLACK);
  if (!prg.pictures.empty() && prg.cursor != prg.files.end())
    {
      t_bunny_picture	*pic = prg.pictures.back();
      t_bunny_position	pos =
	{
	  (int)(prg.win->buffer.width / 2) + prg.cursor->position.x,
	  (int)(prg.win->buffer.height / 2) + prg.cursor->position.y
	};

      if (prg.cursor->fitted == presentation::FULLFIT)
	{
	  prg.cursor->zoom.x = 1.0;
	  prg.cursor->zoom.y = 1.0;
	  if (prg.win->buffer.width < pic->buffer.width)
	    {
	      prg.cursor->zoom.x = ((double)prg.win->buffer.width) / pic->buffer.width;
	      prg.cursor->zoom.y = prg.cursor->zoom.x;
	    }
	  if (prg.win->buffer.height < pic->buffer.height * prg.cursor->zoom.y)
	    {
	      prg.cursor->zoom.y = ((double)prg.win->buffer.height) / pic->buffer.height;
	      prg.cursor->zoom.x = prg.cursor->zoom.y;
	    }
	}
      else if (prg.cursor->fitted == presentation::TRUE_RES)
	{
	  prg.cursor->zoom.x = 1.0;
	  prg.cursor->zoom.y = 1.0;
	}
      else if (prg.cursor->fitted == presentation::COVER)
	{
	  prg.cursor->zoom.x = 1.0;
	  prg.cursor->zoom.y = 1.0;
	  if (prg.win->buffer.width > pic->buffer.width)
	    {
	      prg.cursor->zoom.x = ((double)prg.win->buffer.width) / pic->buffer.width;
	      prg.cursor->zoom.y = prg.cursor->zoom.x;
	    }
	  if (prg.win->buffer.height > pic->buffer.height * prg.cursor->zoom.y)
	    {
	      prg.cursor->zoom.y = ((double)prg.win->buffer.height) / pic->buffer.height;
	      prg.cursor->zoom.x = prg.cursor->zoom.y;
	    }
	}

      // Modification de position et de zoom...
      pic->scale.x = prg.cursor->zoom.x;
      pic->scale.y = prg.cursor->zoom.y;
      pic->rotation = prg.cursor->rotation;
      pic->origin.x = (double)pic->buffer.width / 2 - prg.cursor->origin.x;
      pic->origin.y = (double)pic->buffer.height / 2 - prg.cursor->origin.y;
      bunny_blit(&prg.win->buffer, pic, &pos);
    }
  // Interface
  if (bunny_get_keyboard()[BKS_LALT] || bunny_get_keyboard()[BKS_RALT] ||
      bunny_get_keyboard()[BKS_LSHIFT] || bunny_get_keyboard()[BKS_RSHIFT] ||
      bunny_get_keyboard()[BKS_LCONTROL] || bunny_get_keyboard()[BKS_RCONTROL])
    {

    }
  // Message
  if (bunny_get_current_time() - prg.mtime < 2)
    {
      centered_texto(&prg.win->buffer, prg.message,
		     prg.win->buffer.height * 0.45,
		     prg.win->buffer.height * 0.1);
    }
  bunny_display(prg.win);
  return (GO_ON);
}

