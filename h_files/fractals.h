/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:21:04 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 16:15:34 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "keys.h"

# define BUF 32		// REGLES ET PARAMETRAGES PREDEFINIS

# define GREEN 0x00FF00	
# define RED 0xFF0000
# define BLUE 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define STEP 0.2		// DEPLACEMENT IMAGE

typedef struct s_cmx_derviation
{
	double	fi_one;
	double	fr_one;
	double	fr_two;
	double	fi_two;
	double	incr_re;
	double	incr_im;
}	t_derive;

typedef struct s_key_screen_mouse
{
	double	zoom;
	double	mx;
	double	my;
	double	julia_cx;
	double	julia_cy;
	int		log_i;
	int		screen_mode;
	int		wi;
	int		hi;
	int		size;
	int		mpos;
	int		color;
	int		disolvant;
}	t_ksm;

typedef struct s_info
{
	char	**content;
}	t_info;

typedef struct s_control_screen
{
	t_info		info;
	void		*img;
	char		*a;
	int			b;
	int			l;
	int			e;
	int			state;
}	t_cs;

typedef struct s_building
{
	double	tp;
	double	tp2;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		x;
	int		y;
}	t_build;

typedef struct s_fractal
{
	void	*img;
	char	*a;
	int		b;
	int		l;
	int		e;
	int		mi;
	int		pindex;
}	t_frt;

typedef struct s_fractals
{
	t_frt	m;
	t_frt	j;
	t_frt	n;
}	t_fractals;

typedef struct s_data
{
	t_fractals	f;
	t_ksm		s;
	t_cs		cs;
	void		*mlx;
	void		*win;
	void		*mlx2;
	void		*win2;
	void		*kimg;
	char		*rules;
}	t_data;

///////////////////////////////
// LOGIC AND BASIC FUNCTIONS//
//////////////////////////////

//	MATH
double	pw(double n, int degree);
void	id2(double n1, char op, double n2, double *res);
void	id3(double n1, char op, double n2, double *res);

//	UTILS (LIBFT FLEX)
void	ft_putstr(const char *str);
size_t	getlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *ptr, int c, size_t n);
int		ft_atoi(const char *str);
double	ft_atof(const char *s);
void	*ft_mempcpy(void *dst, const void *src, size_t p, size_t len);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_dtoa(double value, int precision);
size_t	ft_isfloat(char *str, size_t len);

//	MESSAGES
void	merrors(int sig);
void	mrules(int sig);

///////////////////////////////////
//	GRAPHIC MANAGEMENT FUNCTIONS//
//////////////////////////////////

//	DATA SET LOGICS
void	init_data(t_data *data, char state);
void	init_build(t_build *data);
void	init_julia(t_data *data);
void	init_newton(t_data *data);
void	init_mandelbrot(t_data *data);
void	init_control_screen(t_data *data);
int		close_win(void *param);
void	free_to_go(t_data *data, char state);
void	free_lines(t_data *data);
void	check_screen_mode(t_data *d, int key);

//	SCREEN MONITORING
int		get_info(t_data *cs);
int		clear_info(t_data *cs);
int		actualise_info(t_data *cs);
int		convert_info(t_data *cs);
void	free_info(t_data *cs);

//	CONTROL STRUCTURES
int		key_handler(int keycode, t_data *data);
void	handle_key_handlers(int keycode, t_data *data);
int		mouse_move(int x, int y, t_data *data);
int		mouse_handler(int button, int x, int y, t_data *data);

//	PIXELS MANAGEMENT
void	build_fractal_img(t_data *d, t_build *b);
void	replace_image(void **img, void *mlx, int wi, int hi);
void	fractal_mod(t_data *data);
void	print_image(t_data *d, int bdoor);

//	FRACTAL'S TOOLS
void	compute_czxy(t_data *d, t_build *b, int *i);
int		check_limits(t_data *d, t_build *b, int *i);
int		paint_x_axis(t_data *data, t_build *b, int *i);
void	map_pixel(t_data *d, t_build *b, int color);

//  DISPLAYS
void	display_mandelbrot(t_data *data);
void	display_julia(t_data *data);
void	display_newton(t_data *data);
void	display_exit_message(t_data *data);
void	display_redirection(t_data *data);
void	display_home(t_data *data);
void	display_control_screen(t_data *cs);
void	display_monitoring(t_data *cs);

#endif
