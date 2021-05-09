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

# define			PICTURE_CACHE_SIZE		10

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
  }
  ~picture(void)
  {
    if (pic)
      bunny_delete_clipable(pic);
  }
};

struct				bview
{
  t_bunny_window		*win;

  // Les chemins passés en paramètre
  std::list<std::string>	original_path;

  // les fichiers du dossier ou est lancé le logiciel
  std::list<std::string>	files;
  std::list<std::string>::iterator cursor;

  // Un simple file pour eviter de charger/decharger les images sur simple parcours.
  // cela permet de garder en mémoire plusieurs des dernières images
  // une file suffit car le gestionnaire de la liblapin se chargera de maintenir
  // les images encore dans le conteneur vivante
  std::queue<picture>		pictures;
};

bool				refresh_files(bview		&prg,
					      char		**argv,
					      const std::string	&p);
bool				refresh_files(bview		&prg,
					      char		**argv);

#endif	//			__BVIEW_HPP__

