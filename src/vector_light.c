/*
** vector_light.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/raytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Thu Mar  9 15:12:31 2017 Julien Aldon
** Last update Fri Mar 10 11:54:10 2017 Julien Aldon
*/

#include "my.h"

void	init_vector_light_s(sfVector3f eye, sfVector2i pos,
			    sfVector2i screen, t_draw *draw)
{
  sfVector3f    s;
  sfVector3f    dir;

  dir = calc_dir_vector(500, screen, pos);
  s = get_normal_sphere(calc_intersection_point(eye, dir, draw->sphere->k));
  draw->sphere->light_vector = calc_light_vector
    (draw->sphere->k, eye, screen, pos);
  draw->sphere->light_coef = get_light_coef(draw->sphere->light_vector, s);
}

void	init_vector_light_p(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw)
{
  sfVector3f    p;

  p = get_normal_plane(pos.x);
  draw->plane->light_vector = calc_light_vector
    (draw->plane->k, eye, screen, pos);
  draw->plane->light_coef = get_light_coef(draw->plane->light_vector, p);
}

void	init_vector_light_cy(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw)
{
  sfVector3f    dir;
  sfVector3f    c;

  dir = calc_dir_vector(500, screen, pos);
  c = get_normal_cylinder(calc_intersection_point(eye, dir, draw->cylinder->k));
  draw->cylinder->light_vector = calc_light_vector
    (draw->cylinder->k, eye, screen, pos);
  draw->cylinder->light_coef = get_light_coef(draw->cylinder->light_vector, c);
}

void	init_vector_light_c(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw)
{
  sfVector3f    dir;
  sfVector3f    co;

  dir = calc_dir_vector(500, screen, pos);
  co = get_normal_cone(calc_intersection_point(eye, dir, draw->cone->k), RADC);
  draw->cone->light_vector = calc_light_vector
    (draw->sphere->k, eye, screen, pos);
  draw->cone->light_coef = get_light_coef(draw->cone->light_vector, co);
}

sfColor		my_color_fromRGB(int r, int g, int b)
{
  sfColor	color;

  if (r > 255)
    r = r % 255;
  if (g > 255)
    g = g % 255;
  if (r > 255)
    b = b % 255;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  return (color);
}
