/*
** init.c for raytracer1 in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/bsRaytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Wed Mar  1 13:01:18 2017 Julien Aldon
** Last update Fri Mar 10 17:14:21 2017 Julien Aldon
*/

#include "my.h"
#include <stdio.h>

t_draw		*init_form()
{
  t_draw	*draw;

  if (!(draw = malloc(sizeof(t_draw))))
    return (NULL);
  if (!(draw->sphere = malloc(sizeof(t_form))))
    return (NULL);
  if (!(draw->plane = malloc(sizeof(t_form))))
    return (NULL);
  if (!(draw->cylinder = malloc(sizeof(t_form))))
    return (NULL);
  if (!(draw->cone = malloc(sizeof(t_form))))
    return (NULL);
  draw->sphere->color = sfRed;
  draw->plane->color = sfBlue;
  draw->cone->color = sfYellow;
  draw->cylinder->color = sfGreen;
  return (draw);
}

t_form		*sort_draw_k(t_draw *draw, int size)
{
  t_form	**draw_k;
  t_form      	*petit;
  int		i;

  if (!(draw_k = malloc(sizeof(t_form *) * (3 + 1))))
    return (NULL);
  //draw_k[0] = draw->plane;
  draw_k[0] = draw->sphere;
  draw_k[1] = draw->cylinder;
  draw_k[2] = draw->cone;
  i = 0;
  petit = draw_k[0];
  while (i < size)
    {
      if (draw_k[i]->k < petit->k && draw_k[i]->k != -1)
	petit = draw_k[i];
      i ++;
    }
  if (petit->k == -1)
    return (NULL);
  return (petit);
}
