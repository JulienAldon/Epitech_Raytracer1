/*
1;4600;0c1;4600;0c** my_put_pixel.c for C_Graphical_Prog in /home/julien.aldon/delivery/cours/C_Graphical_Prog
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Mon Nov 14 09:38:01 2016 Julien Aldon
** Last update Thu Dec  8 13:36:36 2016 Julien Aldon
*/

#include "my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x < 0 || x >= framebuffer->width || y < 0 || y >= framebuffer->height)
    return ;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4] = color.r;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = color.a;
}
