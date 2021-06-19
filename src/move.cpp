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
  if (prg.down_in == false || prg.cursor == prg.files.end())
    return (GO_ON);
  t_bunny_position	here = *bunny_get_mouse_position();
  t_bunny_position	diff =
    {
      here.x - prg.down_position.x,
      here.y - prg.down_position.y
    };

  if (bunny_get_keyboard()[BKS_LALT] || bunny_get_keyboard()[BKS_RALT])
    prg.cursor->rotation = prg.cursor->before_click_rot + diff.x + diff.y;
  else
    {
      prg.cursor->position.x = prg.cursor->before_click_pos.x + diff.x;
      prg.cursor->position.y = prg.cursor->before_click_pos.y + diff.y;
    }
  return (GO_ON);
}

