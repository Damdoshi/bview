// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

void			bview_message(bview &b,
				      const std::string	&str)
{
  b.message = str;
  b.mtime = bunny_get_current_time();
}
