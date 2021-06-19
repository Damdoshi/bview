// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

void			centered_text(t_bunny_buffer	*pic,
				      const std::string	&str,
				      int		xo,
				      int		y,
				      int		h,
				      unsigned int	color)
{
  unsigned int		col[2] = {color, color};
  int			w = h / 4;
  int			l = (pic->width - w * str.size() * 1.33) / 2;

  for (size_t i = 0; i < str.size(); ++i)
    {
      int		x = i * w * 1.33 + l;
      const t_bunny_letter *letter;

      if (str[i] >= 'a' && str[i] <= 'z')
	letter = &gl_vector_font[str[i] - 'a'];
      else if (str[i] >= '0' && str[i] <= '9')
	letter = &gl_vector_font[str[i] - '0' + BFT_0];
      else if (str[i] == '!')
	letter = &gl_vector_font[BFT_EXCLAMATION];
      else if (str[i] == '/')
	letter = &gl_vector_font[BFT_SLASH];
      else
	continue ;
      for (int j = 0; j < letter->nb_edge; ++j)
	{
	  t_bunny_position	pos[2];

	  pos[0].x = w * letter->edge[j].x0 / 20.0 + x + xo;
	  pos[0].y = h * letter->edge[j].y0 / 20.0 + y;
	  pos[1].x = w * letter->edge[j].x1 / 20.0 + x + xo;
	  pos[1].y = h * letter->edge[j].y1 / 20.0 + y;
	  bunny_set_line(pic, &pos[0], &col[0]);
	}
    }
}

void			centered_texto(t_bunny_buffer	*pic,
				       const std::string &str,
				       int		y,
				       int		h)
{
  int			i;
  int			j;

  for (i = 0; i < 5; ++i)
    {
      for (j = 0; j < 5; ++j)
	{
	  centered_text(pic, str, -i, y - j, h, BLACK);
	  centered_text(pic, str, +i, y + j, h, BLACK);
	  centered_text(pic, str, -i, y + j, h, BLACK);
	  centered_text(pic, str, +i, y - j, h, BLACK);
	}
    }
  for (i = 0; i < 2; ++i)
    {
      for (j = 0; j < 2; ++j)
	{
	  centered_text(pic, str, -i, y - j, h, WHITE);
	  centered_text(pic, str, +i, y + j, h, WHITE);
	  centered_text(pic, str, -i, y + j, h, WHITE);
	  centered_text(pic, str, +i, y - j, h, WHITE);
	}
    }
  centered_text(pic, str, 0, y, h, WHITE);
}
