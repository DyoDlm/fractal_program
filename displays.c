#include "fractals.h"

void    display_home(t_data *data)
{
    char    text[51];
    int     color;

    color = RED;
    ft_memset(text, 0, 51);
    ft_memcpy(text, "Hi noob brother ! Click 's' to lauch fractal mode.", 50);
    text[50] = '\0';
    mlx_string_put(data->mlx, data->win, 100, 50, color, text);
    display_redirection(data);
}

void    display_mandelbrot(t_data *data)
{
    char    text[39];
    int     color;

    color = RED;
    ft_memset(text, 0, 39);
    ft_memcpy(text, "Right access to Mandelbrot's fractal !", 38);
    text[38] = '\0';
    mlx_string_put(data->mlx, data->win, 100, 50, color, text);
    ft_memset(text, 0, 39);
    ft_memcpy(text, "Type Enter to start visualisation", 33);
    text[34] = '\0';
    mlx_string_put(data->mlx, data->win, 100, 500, color, text);
    display_redirection(data);
}

void    display_julia(t_data *data)
{
    char    text[34];
    int     color;

    color = RED;
    ft_memset(text, 0, 34);
    ft_memcpy(text, "Right access to Julia's fractal !", 33);
    text[32] = '\0';
    mlx_string_put(data->mlx, data->win, 100, 50, color, text);
    ft_memset(text, 0, 34);
    ft_memcpy(text, "Type Enter to start visualisation", 33);
    mlx_string_put(data->mlx, data->win, 100, 500, color, text);
    display_redirection(data);
}

void    display_newton(t_data *data)
{
    char    text[35];
    int     color;

    color = RED;
    ft_memset(text, 0, 35);
    ft_memcpy(text, "Right access to Newton's fractal !", 34);
    text[34] = '\0';
    mlx_string_put(data->mlx, data->win, 100, 50, color, text);
    ft_memset(text, 0, 35);
    ft_memcpy(text, "Type Enter to start visualisation", 34);
    mlx_string_put(data->mlx, data->win, 100, 500, color, text);
    display_redirection(data);
}

void    display_exit_message(t_data *d)
{
    mlx_string_put(d->mlx, d->win, d->s.WI/4, d->s.HI/2 - 180, RED, "RESTARTED");
    display_redirection(d);
}