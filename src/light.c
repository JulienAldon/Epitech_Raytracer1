/*
** light.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsRaytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Wed Mar  1 17:42:21 2017 Julien Aldon
** Last update Wed Mar 15 15:02:07 2017 Julien Aldon
*/

#include "../include/my.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	a;
  float b;
  float	c;
  float	d;

  a = light_vector.x * normal_vector.x + light_vector.y * normal_vector.y
    + light_vector.z * normal_vector.z;
  b = sqrt(pow(normal_vector.x, 2) + pow(normal_vector.y, 2)
	   + pow(normal_vector.z, 2));
  c = sqrt(pow(light_vector.x, 2) + pow(light_vector.y, 2)
	   + pow(light_vector.z, 2));
  if (b * c == 0)
    return (0);
  d = a / (b * c);
  if (d >= 0)
    return (d);
  return (0);
}
