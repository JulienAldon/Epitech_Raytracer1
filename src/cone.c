/*
** cone.c for raytracer1 in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/raytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Wed Mar  8 15:39:34 2017 Julien Aldon
** Last update Thu Mar 16 15:52:08 2017 Julien Aldon
*/

#include "../include/my.h"

float		solve_equation_cone(float a, float b, float c)
{
  float		delta;
  float		s1;
  float		s2;
  
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
    s1 = (-b / (2 * a) < 0) ? (-1) : (-b / (2 * a));
  else if (delta < 0)
    return (-1);
  return (s1);
}

float		intersect_cone(sfVector3f eye, sfVector3f dir, float angle)
{
  sfVector3f	a;

  angle = (angle * 2 * M_PI) / 360;
  a.x = pow(dir.x, 2) + pow(dir.y, 2) - pow(tan(angle), 2) * pow(dir.z, 2);
  a.y = 2 * (dir.x * eye.x + dir.y * eye.y - pow(tan(angle), 2) * dir.z * eye.z);
  a.z = pow(eye.x, 2) + pow(eye.y, 2) - pow(eye.z, 2) * pow(tan(angle), 2);
  return (solve_equation_cone(a.x, a.y, a.z));
}

sfVector3f	get_normal_cone(sfVector3f intersection, float semiangle)
{
  sfVector3f	a;

  semiangle = (2 * semiangle * M_PI) / 360;
  a.x = intersection.x;
  a.y = intersection.y;
  a.z = - tan(semiangle) * intersection.z;
  return (a);
}
