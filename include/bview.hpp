// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#ifndef				__BVIEW_HPP__
# define			__BVIEW_HPP__
# include			<lapin.h>
# include			<list>
# include			<queue>
# ifdef				DEBUG
#  undef			DEBUG
#  define			DEBUG(a)			(a)
#  include			<iostream>
# else
#  define			DEBUG(a)
# endif

# define			PICTURE_CACHE_SIZE		10

void				centered_text(t_bunny_buffer	*pic,
					      const std::string	&str,
					      int		xo,
					      int		y,
					      int		h,
					      unsigned int	color);
void				centered_texto(t_bunny_buffer	*pic,
					       const std::string &str,
					       int		y,
					       int		h);

struct				picture
{
  t_bunny_picture		*pic;

  operator t_bunny_picture * (void)
  {
    return (pic);
  }
  picture(const std::string	&str)
  {
    if ((pic = bunny_load_picture(str.c_str())))
      {
	pic->origin.x = pic->buffer.width / 2;
	pic->origin.y = pic->buffer.height / 2;
      }
    else
      {
	if ((pic = bunny_new_picture(1920, 320)) == NULL)
	  {
	    fprintf(stderr, "bview: Cannot create error buffer.\n");
	    exit(EXIT_FAILURE);
	  }
	bunny_clear(&pic->buffer, BLACK);
	centered_texto(&pic->buffer, "cannot open", 0, pic->buffer.height / 3);
	centered_texto(&pic->buffer, str, 2 * pic->buffer.height / 3, pic->buffer.height / 3);
      }
  }
  ~picture(void)
  {
    if (pic)
      bunny_delete_clipable(pic);
  }
};

struct				presentation
{
  enum				DisplayType
    {
      FULLFIT,
      TRUE_RES,
      COVER,
      MANUAL
    };
  std::string			file;
  t_bunny_accurate_position	zoom;
  t_bunny_position		origin;
  t_bunny_position		position;
  double			rotation;
  DisplayType			fitted;

  double			before_click_rot;
  t_bunny_position		before_click_pos;

  operator			std::string (void) const
  {
    return (file);
  }

  const char			*c_str(void) const
  {
    return (file.c_str());
  }

  bool				operator==(const presentation &p) const
  {
    return (file == p.file);
  }

  presentation			&operator=(const presentation &b)
  {
    file = b.file;
    memcpy(&this->zoom, &b.zoom, sizeof(*this) - sizeof(this->file));
    return (*this);
  }
  
  presentation(const std::string &str)
    : file(str),
      zoom({1, 1}),
      origin({0, 0}),
      position({0, 0}),
      rotation(0),
      fitted(FULLFIT)
  {}
  ~presentation(void)
  {}
};

struct				bview
{
  t_bunny_window		*win;

  // Les chemins passés en paramètre
  std::list<std::string>	original_path;

  // les fichiers du dossier ou est lancé le logiciel
  std::list<presentation>	files;
  std::list<presentation>::iterator cursor;

  // Un simple file pour eviter de charger/decharger les images sur simple parcours.
  // cela permet de garder en mémoire plusieurs des dernières images
  // une file suffit car le gestionnaire de la liblapin se chargera de maintenir
  // les images encore dans le conteneur vivante
  std::queue<picture>		pictures;
  // Le nombre max d'image dans pictures
  size_t			buffer_size;

  t_bunny_position		down_position;
  bool				down_in;

  double			slidestart;
  bool				slideshow;
  double			slidelen;

  std::string			message;
  t_bunny_time			mtime;
  
  void				move_left(void);
  void				move_right(void);
  std::list<presentation>::iterator look(int			i = 0);
  void				preload(int			i = 0);

  bview(void)
  {
    cursor = files.end();
  }
};

bool				refresh_files(bview		&prg,
					      char		**argv,
					      const std::string	&p);
bool				refresh_files(bview		&prg,
					      char		**argv);
void				bview_move_picture(presentation	&p,
						   int		x,
						   int		y);
void				bview_turn_picture(presentation	&p,
						   double	rot);
void				bview_multiply_scale(presentation &p,
						     double	x,
						     double	y);
bool				bview_toggle_fullscreen(bview	&p);
void				bview_reset(bview		&b);

void				bview_message(bview		&b,
					      const std::string	&str);

#endif	//			__BVIEW_HPP__

