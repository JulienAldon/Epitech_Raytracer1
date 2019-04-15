/*
1;4601;0c1;4601;0c** my_draw.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsRaytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Mon Feb 27 12:47:33 2017 Julien Aldon
** Last update Fri Mar 10 17:30:18 2017 Julien Aldon
*/

#include "my.h"
#include <stdio.h>

/*
** tag :
** - 0: sphere ; 1: plane ; 2: cylindre
*/

sfColor		my_color(float light_coef, int tag)
{
  int		red;
  int		blue;
  int		green;
  int		ambiant;
  sfColor	color;

  ambiant = 0;
  green = ambiant + (255 * light_coef);
  blue = ambiant + (255 * light_coef);
  red = ambiant + (255 * light_coef);
  if (tag == 0)
    color = my_color_fromRGB(red, 0, 0);
  else if (tag == 1)
    color = my_color_fromRGB(0, 0, blue);
  else if (tag == 2)
    color = my_color_fromRGB(0, green, 0);
  else if (tag == 3)
    color = my_color_fromRGB(0, green, 0);
  return (color);
}

int	gestion_k(t_draw *draw, t_my_framebuffer *f, sfVector2i pos)
{
  draw->sphere->color = my_color(draw->sphere->light_coef, 0);
  draw->plane->color = my_color(draw->plane->light_coef, 1);
  draw->cylinder->color = my_color(draw->cylinder->light_coef, 2);
  draw->cone->color = my_color(draw->cone->light_coef, 3);
  if (draw->sphere->k != -1)
    my_put_pixel(f, pos.x, pos.y, draw->sphere->color);
  else
    my_put_pixel(f, pos.x, pos.y, sfBlack);
  return (0);
}

sfVector3f	calc_intersection_point(sfVector3f eye, sfVector3f dir, float k)
{
  sfVector3f	intersection_point;

  intersection_point.x = eye.x + k * dir.x;
  intersection_point.y = eye.y + k * dir.y;
  intersection_point.z = eye.z + k * dir.z;
  return (intersection_point);
}

/*
** \/ POSITION DE LA LUMIERE DANS CETTE FONCTION \/
*/

sfVector3f	calc_light_vector(float k, sfVector3f eye, sfVector2i screen, sfVector2i pos)
{
  sfVector3f	light_vector;

  light_vector.x = LIGHT_POS_X - calc_intersection_point
    (eye, calc_dir_vector(500, screen, pos), k).x;
  light_vector.x = LIGHT_POS_Y - calc_intersection_point
    (eye, calc_dir_vector(500, screen, pos), k).y;
  light_vector.x = LIGHT_POS_Z - calc_intersection_point
    (eye, calc_dir_vector(500, screen, pos), k).z;
  return (light_vector);
}

void		draw_sphere(t_my_framebuffer *f, sfVector3f eye, t_draw *draw)
{
  sfVector2i	pos;
  sfVector2i	screen;
  float		rad;

  screen.x = SCREEN_WIDTH;
  screen.y = SCREEN_HEIGHT;
  pos.y = 0;
  rad = 30;
  while (pos.y != SCREEN_HEIGHT)
    {
      pos.x = 0;
      while (pos.x != SCREEN_WIDTH)
	{
	  eye.z = 0;
	  draw->sphere->k = intersect_sphere
	    (eye, calc_dir_vector(500, screen, pos), rad);
	  init_vector_light_s(eye, pos, screen, draw);
	  gestion_k(draw, f, pos);
	  pos.x ++;
	}
      pos.y ++;
    }
}
