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
  if (!prg.pictures.empty())
    {
      picture		&pic = prg.pictures.back();
      t_bunny_position	pos =
	{
	  (int)prg.win->buffer.width / 2,
	  (int)prg.win->buffer.height / 2
	};

      // Modification de position et de zoom...
      bunny_blit(&prg.win->buffer, pic, &pos);
    }
  // Interface
  //
  bunny_display(prg.win);
  return (GO_ON);
}

