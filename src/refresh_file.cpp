// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		<string.h>
#include		<libgen.h>
#include		<sys/stat.h>
#include		<unistd.h>
#include		<dirent.h>
#include		"bview.hpp"

#include		"bview.hpp"

static bool		extension(const char	*str,
				  const char	*ext)
{
  if ((str = strstr(str, ext)) == NULL)
    return (false);
  if (strcmp(str, ext) == 0)
    return (true);
  return (false);
}

bool			refresh_files(bview		&prg,
				      char		**argv,
				      const std::string	&str)
{
  // Les formats supportés
  static const char	*ext[] =
    {
      ".png", ".jpg", ".jpeg", ".jfif", ".psd", ".tiff"
    };

  DIR			*dir;
  struct dirent		*ent;
  struct stat		st;

  if ((dir = opendir(str.c_str())) == NULL && errno == ENOTDIR)
    {
      char		buffer[str.size() + 1];
      char		*d;

      strncpy(&buffer[0], str.c_str(), str.size() + 1);
      d = dirname(&buffer[0]);
      if ((dir = opendir(d)) == NULL)
	{
	  fprintf(stderr, "%s: Cannot open directory %s. (%s)\n", argv[0], d, strerror(errno));
	  return (false);
	}
    }
  while ((ent = readdir(dir)) != NULL)
    {
      if (strcmp(ent->d_name, ".") == 0)
	continue ;
      if (strcmp(ent->d_name, "..") == 0)
	continue ;
      stat(ent->d_name, &st);
      if (S_ISDIR(st.st_mode))
	continue ;

      for (int i = 0; i < NBRCELL(ext); ++i)
	if (extension(ent->d_name, ext[i]))
	  {
	    prg.files.push_back(ent->d_name);
	    break ;
	  }
    }
  closedir(dir);
  return (true);
}

bool			refresh_files(bview		&prg,
				      char		**argv)
{
  std::string	cursor;

  // On sauvegarde le curseur, au cas ou la fonction soit appellée
  // pour rafraichir l'état du programme et non pour le lancer
  if (prg.cursor != prg.files.end())
    cursor = *prg.cursor;
  // On vire tout, on va tout recharger
  prg.files.clear();
  for (auto i = prg.original_path.begin(); i != prg.original_path.end(); ++i)
    if (refresh_files(prg, argv, *i) == false)
      return (false);
  // On restore le curseur
  if (cursor != "")
    {
      for (auto i = prg.files.begin(); i != prg.files.end(); ++i)
	if (*i == cursor)
	  {
	    prg.cursor = i;
	    break ;
	  }
    }
  // Pas de cursueur ==> c'est le chargement du programme
  // et il n'y a qu'un seul paramètre, on va donc chercher le fichier dans le
  // dossier chargé
  else if (prg.original_path.size() == 1)
    {
      for (auto i = prg.files.begin(); i != prg.files.end(); ++i)
	if (strstr(argv[1], i->c_str()) != NULL)
	  {
	    prg.cursor = i;
	    break ;
	  }
    }
  return (true);
}
