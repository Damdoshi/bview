// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include	"bview.hpp"

void		bview::preload(int	l)
{
  std::list<presentation>::iterator it;
  int				i;

  i = -l;
  it = cursor;
  while (++i < 0)
    {
      pictures.emplace(*it);
      if (it == files.begin())
	it = --files.end();
      else
	--it;
      if (it == cursor)
	goto End;
    }
  it = cursor;
  while (--l >= 0)
    {
      pictures.emplace(*it);
      if (++it == files.end())
	it = files.begin();
      if (it == cursor)
	goto End;
    }
 End:
  pictures.emplace(*cursor);
}

