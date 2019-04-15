
/*
** my.h for projet in /home/julien.aldon/delivery/test/prep_my_repo
** 
** Made by Julien Aldon
** Login   <julien.aldon@epitech.net>
** 
** Started on  Wed Dec  7 11:38:52 2016 Julien Aldon
** Last update Fri Mar 10 11:25:10 2017 Julien Aldon
*/

#ifndef MY_H_
# define MY_H_

#include "config.h"
# include <SFML/System/Vector2.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_window
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*texture;
  t_my_framebuffer	*framebuffer;
}			t_window;

typedef struct		s_form
{
  sfVector3f		light_vector;
  float			light_coef;
  sfColor		color;
  float			k;
}			t_form;

typedef struct		s_draw
{
  t_form		*sphere;
  t_form		*plane;
  t_form		*cylinder;
  t_form		*cone;
}			t_draw;

t_my_framebuffer        *my_framebuffer_create(int width, int height);

/*
** init.c
*/

t_draw		*init_form();
void   		init_vector_light(sfVector3f eye, sfVector2i pos, sfVector2i screen, t_draw *draw);
t_form		*sort_draw_k(t_draw *draw, int size);

/*
** vector_light.c
*/

void    init_vector_light_s(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw);
void    init_vector_light_p(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw);
void    init_vector_light_cy(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw);
void    init_vector_light_c(sfVector3f eye, sfVector2i pos,
                            sfVector2i screen, t_draw *draw);
sfColor         my_color_fromRGB(int r, int g, int b);

/*
** my_put_pixel.c
*/

void	     	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color);

/*
** calc_dir_vector.c
*/

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size, sfVector2i screen_pos);

/*
** light.c
*/

float 		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);

/*
** sphere.c
*/

float	      	intersect_sphere(sfVector3f eye, sfVector3f dir, float radius);
sfVector3f	get_normal_sphere(sfVector3f intersection_point);

/*
** plane.c
*/

float		intersect_plane(sfVector3f eye, sfVector3f dir);
sfVector3f	get_normal_plane(int upward);

/*
** cylinder.c
*/

float		intersect_cylinder(sfVector3f eye, sfVector3f dir, float radius);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);

/*
** cone.c
*/

float		intersect_cone(sfVector3f eye, sfVector3f dir, float angle);
sfVector3f	get_normal_cone(sfVector3f intersection, float semiangle);

/*
** translate.c
*/

sfVector3f	translate(sfVector3f to_translate, sfVector3f translation);

/*
** my_draw.c
*/

void	        draw_sphere(t_my_framebuffer *f, sfVector3f eye, t_draw *draw);
sfVector3f      calc_light_vector(float k, sfVector3f eye, sfVector2i screen, sfVector2i pos);
sfVector3f      calc_intersection_point(sfVector3f eye, sfVector3f dir, float k);
int		gestion_k(t_draw *draw, t_my_framebuffer *f, sfVector2i pos);
sfColor         my_color(float light_coef, int tag);

/*
** main.c
*/

sfUint8		*create_pixel_buffer(int width, int height);

#endif /* !TMP_H_ */
