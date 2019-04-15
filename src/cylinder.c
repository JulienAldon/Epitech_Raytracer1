/*
** cylinder.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/raytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Fri Mar  3 13:30:58 2017 Julien Aldon
** Last update Thu Mar 16 16:03:35 2017 Julien Aldon
*/

#include "../include/my.h"

float		solve_equation_cy(float a, float b, float c)
{
  float		delta;
  float		s1;
  float		s2;

  delta = pow(b, 2) - (4 * a * c);
  if (delta > 0)
    {
      s1 = (-b - sqrt(delta)) / (2 * a);
      s2 = (-b + sqrt(delta)) / (2 * a);
      if (s1 > 0 && s2 < 0)
	return (s1);
      else if (s1 < 0 && s2 > 0)
	return (s2);
      else if (s1 < 0 && s2 < 0)
	return (-1);
      s1 = s2 < s1 ? s2 : s1;
    }
  else if (delta == 0)
    s1 = (-b / (2 * a) < 0) ? (-1) : (-b / (2 * a));
  else if (delta < 0)
    return (-1);
  return (s1);
}

float		intersect_cylinder(sfVector3f eye, sfVector3f dir, float radius)
{
  float		a;
  float		b;
  float		c;
  
  a = pow(dir.x, 2) + pow(dir.y, 2);
  b = 2 * (eye.x * dir.x + eye.y * dir.y);
  c = pow(eye.x, 2) + pow(eye.y, 2) - pow(radius, 2);
  return (solve_equation_cy(a, b, c));
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	d;

  d.x = intersection_point.x;
  d.y = intersection_point.y;
  d.z = 0;
  return (d);
}
