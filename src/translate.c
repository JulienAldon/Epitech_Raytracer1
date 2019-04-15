/*
** translate.c for raytracer in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/raytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Wed Mar  8 11:42:16 2017 Julien Aldon
** Last update Fri Mar 10 11:43:19 2017 Julien Aldon
*/

#include "../include/my.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translation)
{
  sfVector3f	a;

  a.x = translation.x + to_translate.x;
  a.y = translation.y + to_translate.y;
  a.z = translation.z + to_translate.z;
  return (a);
}
