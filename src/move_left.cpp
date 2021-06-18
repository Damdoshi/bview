// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

void			bview::move_left(void)
{
  if (down_in)
    return ;
  if (cursor == files.begin())
    cursor = --files.end();
  else
    --cursor;
  pictures.emplace(*cursor);
  if (pictures.size() >= buffer_size)
    pictures.pop();
}
