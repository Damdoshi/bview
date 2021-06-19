// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

void			bview::move_right(void)
{
  if (down_in || cursor == files.end())
    return ;
  if (++cursor == files.end())
    cursor = files.begin();
  pictures.emplace(*cursor);
  if (pictures.size() >= buffer_size)
    pictures.pop();
}
