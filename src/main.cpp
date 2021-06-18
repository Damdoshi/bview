// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2009-2021
//
// bview: bunny picture viewer

#include		"bview.hpp"

extern "C"
{
  bunny_declare_context(bview);

  // Je n'ai pas actuellement une version de G++ assez avancée
  // pour utiliser .key = bview_key, etc...
  // Donc c'est a changer dès que j'aurai accès a une meilleure version.
  const t_bunny_context	gl_context =
    {
      bview_key,
      NULL,
      bview_click,
      bview_move,
      bview_wheel,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      bview_resize,
      bview_loop,
      bview_display,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    };
}

int			main(int		argc,
			     char		**argv)
{
  static bview		prg;
  const t_bunny_size	*siz;

  prg.buffer_size = 10;
  prg.slidelen = 2;
  prg.slideshow = false;
  siz = bunny_get_screen_resolution();
  //if ((prg.win = bunny_start_style(siz->x, siz->y, NO_BORDER, "bview")) == NULL)
  if ((prg.win = bunny_start(800, 600, false, "bview")) == NULL)
    {
      fprintf(stderr, "%s: Cannot open window.\n", argv[0]);
      return (EXIT_FAILURE);
    }
  bunny_move_window(prg.win, {0, 0});
  
  if (argc == 1)
    {
      argc = 2;
      argv[1] = (char*)"./";
    }

  for (int i = 1; i < argc; ++i)
    prg.original_path.push_back(argv[i]);
  prg.cursor = prg.files.end();

  prg.cursor = prg.files.begin();
  if (refresh_files(prg, argv) == false)
    return (EXIT_FAILURE);
  if (prg.cursor != prg.files.end())
    prg.preload(prg.buffer_size / 2);

  bunny_set_context(&gl_context);
  printf("%s slideshow\n", prg.slideshow ? "do" : "do not");
  bunny_loop(prg.win, 50, &prg);
  bunny_stop(prg.win);

  return (EXIT_SUCCESS);
}
