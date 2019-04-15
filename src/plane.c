/*
** plane.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsRaytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Mon Feb 27 15:45:07 2017 Julien Aldon
** Last update Fri Mar 10 16:08:07 2017 Julien Aldon
*/

#include "../include/my.h"

float	intersect_plane(sfVector3f eye, sfVector3f dir)
{
  float	k;

  if (dir.z > 0 || dir.z < 0)
    k = dir.z / -eye.z;
  if (k < 0)
    k = -1;
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	norm;

  norm.x = 0;
  norm.y = 0;
  norm.z = upward == 1 ? 100 : -100;
  return (norm);
}
