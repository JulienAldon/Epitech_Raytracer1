/*
** calc_dir_vector.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsRaytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Mon Feb 27 13:08:18 2017 Julien Aldon
** Last update Fri Mar 10 11:42:00 2017 Julien Aldon
*/

#include "../include/my.h"

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f	ray;

  ray.x = dist_to_plane;
  ray.y = (screen_size.x / 2) - screen_pos.x;
  ray.z = (screen_size.y / 2) - screen_pos.y;
  return (ray);
}
