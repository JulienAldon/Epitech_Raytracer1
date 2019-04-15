/*
** rotate.c for raytracer1 in /home/julien.aldon/delivery/Cours/C_Graphical_Prog/raytracer1
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Wed Mar  8 11:46:11 2017 Julien Aldon
** Last update Thu Mar 16 15:15:37 2017 Julien Aldon
*/

#include "../include/my.h"

sfVector3f	rx(sfVector3f to_rotate, float angles)
{
  sfVector3f	rot;
  
  rot.x = (to_rotate.x * 1) + (to_rotate.y * 0) + (to_rotate.z * 0);
  rot.y = (to_rotate.x * 0) + (cosf(angles) * to_rotate.y) +
    (-sinf(angles) * to_rotate.z);
  rot.z = (to_rotate.x * 0) + (sinf(angles) * to_rotate.y) +
    (cosf(angles) * to_rotate.z);
  return (rot);
}

sfVector3f	ry(sfVector3f to_rotate, float angles)
{
  sfVector3f	rot;
  
  rot.x = (to_rotate.x * cosf(angles)) + (to_rotate.y * 0) +
    (to_rotate.z * sinf(angles));
  rot.y = (to_rotate.y * 1) + (to_rotate.x * 0) + (to_rotate.z * 0);
  rot.z = (-sinf(angles) * to_rotate.x) + (cosf(angles) * to_rotate.z);
  return (rot);
}

sfVector3f	rz(sfVector3f to_rotate, float angles)
{
  sfVector3f	rot;

  rot.x = (to_rotate.x * cosf(angles)) + (-sinf(angles) * to_rotate.y) +
    (to_rotate.z * 0);
  rot.y = (cosf(angles) * to_rotate.y) + (sinf(angles) * to_rotate.x) +
    (to_rotate.z * 0);
  rot.z = (to_rotate.z * 1) + (to_rotate.x * 0) + (to_rotate.y * 0);
  return (rot);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	a;
  
  angles.x = (angles.x * M_PI) / 180;
  angles.y = (angles.y * M_PI) / 180;
  angles.z = (angles.z * M_PI) / 180;
  a = rx(to_rotate, angles.x);
  a = ry(a, angles.y);
  a = rz(a, angles.z);
  return (a);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	a;
  
  angles.x = (angles.x * M_PI) / 180;
  angles.y = (angles.y * M_PI) / 180;
  angles.z = (angles.z * M_PI) / 180;
  a = rz(to_rotate, angles.z);
  a = ry(a, angles.y);
  a = rx(a, angles.x);
  return (a);
}
