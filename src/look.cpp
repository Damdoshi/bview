// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

std::list<presentation>::iterator bview::look(int	l)
{
  std::list<presentation>::iterator it = cursor;

  if (cursor == files.end())
    return (files.end());
  if (l < 0)
    while (++l)
      ++it;
  else if (l > 0)
    while (--l)
      --it;
  return (it);
}

