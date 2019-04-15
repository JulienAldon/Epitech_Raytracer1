/*
** intersect_sphere.c for bsraytrace in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsRaytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Mon Feb 27 11:03:50 2017 Julien Aldon
** Last update Fri Mar 10 11:43:06 2017 Julien Aldon
*/

#include "../include/my.h"

float	intersect_sphere(sfVector3f eye, sfVector3f dir, float radius)
{
  float	delta;
  float	a;
  float	b;
  float	c;
  float	s1;
  float	s2;

  a = pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2);
  b = 2 * (eye.x * dir.x + eye.y * dir.y + eye.z * dir.z);
  c = pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2) - pow(radius, 2);
  delta = pow(b, 2) - 4 * a * c;
  if (delta > 0)
    {
      s1 = (-b - sqrt(delta)) / (2 * a);
      s2 = (-b + sqrt(delta)) / (2 * a);
      if (s1 < 0 && s2 > 0)
	return (s2);
      else if (s1 > 0 && s2 < 0)
	return (s1);
      else if (s1 < 0 && s2 < 0)
	return (-1);
      s1 = s2 < s1 ? s2 : s1;
    }
  else if (delta == 0)
    s1 = -b / (2 * a);
  else if (delta < 0)
    return (-1);
  return (s1);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return(intersection_point);
}
