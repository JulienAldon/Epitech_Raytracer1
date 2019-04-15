/*
1;4600;0c** main.c for bs_Wireframe in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsmy_put_pixel
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Mon Dec  5 10:20:23 2016 Julien Aldon
** Last update Fri Mar 10 17:21:19 2017 Julien Aldon
*/

#include "my.h"

sfUint8                 *create_pixel_buffer(int width, int height)
{
  int                   i;
  sfUint8               *pixels;

  pixels = malloc(width * height * 4 * sizeof(sfUint8));
  if (!pixels)
    return (0);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}

t_window	*my_window_create(int width, int height, char *title)
{
  t_window	*window;

  if (!(window = malloc(sizeof(t_window))))
    return (NULL);
  if (!(window->framebuffer = malloc(sizeof(t_my_framebuffer))))
    return (NULL);
  window->mode.width = width;
  window->mode.height = height;
  window->mode.bitsPerPixel = 32;
  window->framebuffer->width = width;
  window->framebuffer->height = height;
  if (!(window->window = sfRenderWindow_create(window->mode,
					       title, sfClose, NULL)))
    return (NULL);
  window->sprite = sfSprite_create();
  window->texture = sfTexture_create(width, height);
  window->framebuffer->pixels = create_pixel_buffer(width, height);
  sfSprite_setTexture(window->sprite, window->texture, sfTrue);
  return (window);
}

void		my_window_destroy(t_window *window)
{
  if (window)
    {
      sfRenderWindow_destroy(window->window);
      sfTexture_destroy(window->texture);
      sfSprite_destroy(window->sprite);
      free(window->framebuffer->pixels);
      free(window->framebuffer);
    }
}

void		my_refresh_window(t_window *window, int width, int height)
{
  sfEvent	event;

  sfTexture_updateFromPixels(window->texture,
			     window->framebuffer->pixels, width, height, 0, 0);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
  sfRenderWindow_display(window->window);
  while (sfRenderWindow_pollEvent(window->window, &event))
    if (event.type == sfEvtClosed ||
	(event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape))
      sfRenderWindow_close(window->window);
}

int		main()
{
  t_window	*window;
  t_draw	*draw;
  sfVector3f	eye;

  eye.x = -100;
  eye.y = 0;
  eye.z = 0;
  window = my_window_create(SCREEN_WIDTH, SCREEN_HEIGHT, "RAYTRACER 1");
  if ((draw = init_form()) == NULL)
    return (84);
  while (sfRenderWindow_isOpen(window->window))
    {
      sfRenderWindow_clear(window->window, sfBlack);
      draw_sphere(window->framebuffer, eye, draw);
      my_refresh_window(window, SCREEN_WIDTH, SCREEN_HEIGHT);
    }
  my_window_destroy(window);
  return (0);
}
