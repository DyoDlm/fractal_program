#include "fractals.h"

void    display_redirection(t_data *d)
{
    char    prop1[41];
    char    prop2[36];
    char    prop3[37];
    char    prop4[46];
    int     color;

    color = RED;
    ft_memset(prop1, 0, 41);
    ft_memset(prop2, 0, 36);
    ft_memset(prop3, 0, 37);
    ft_memset(prop4, 0, 46);
    ft_memcpy(prop1, "To see Mandelbrot's fractal, type : '1'", 39);
    prop1[40] = '\0';
    ft_memcpy(prop2, "To see Julia's fractal, type : '2'", 34);
    prop2[35] = '\0';
    ft_memcpy(prop3, "To see Newton's fractal, type : '3'", 35);
    prop3[36] = '\0';
    ft_memcpy(prop4, "To see some great looking person, type : '4'", 44);
    prop4[45] = '\0';
    mlx_string_put(d->mlx, d->win, d->s.WI/4, d->s.HI/2 - 130, color, prop1);
    mlx_string_put(d->mlx, d->win, d->s.WI/4, d->s.HI/2 - 110, color, prop2);
    mlx_string_put(d->mlx, d->win, d->s.WI/4, d->s.HI/2 - 80, color, prop3);
    mlx_string_put(d->mlx, d->win, d->s.WI/4, d->s.HI/2 - 50, color, prop4);
}

int    get_info(t_data *cs)
{
    ft_memcpy(cs->cs.info.content[0], &"ZOOM             :   ", 21);
    ft_memcpy(cs->cs.info.content[1], &"SCREEN MODE      :   ", 21);
    ft_memcpy(cs->cs.info.content[2], &"COLOR SCALE      :   ", 21);
    ft_memcpy(cs->cs.info.content[3], &"BITS PER PIXEL   :   ", 21);
    ft_memcpy(cs->cs.info.content[4], &"LINE LENGHT      :   ", 21);
    ft_memcpy(cs->cs.info.content[5], &"ENDIAN           :   ", 21);
    ft_memcpy(cs->cs.info.content[6], &"BITS PER PIXEL   :   ", 21);
    ft_memcpy(cs->cs.info.content[7], &"LINE LENGHT      :   ", 21);
    ft_memcpy(cs->cs.info.content[8], &"ENDIAN           :   ", 21);
    ft_memcpy(cs->cs.info.content[11], &"BITS PER PIXEL   :   ", 21);
    ft_memcpy(cs->cs.info.content[12], &"LINE LENGHT      :   ", 21);
    ft_memcpy(cs->cs.info.content[13], &"ENDIAN           :   ", 21);
    ft_memcpy(cs->cs.info.content[15], &"text", 4);
    ft_memcpy(cs->cs.info.content[9], &"CX FOR JULIA     :   ", 21);
    ft_memcpy(cs->cs.info.content[10], &"CY FOR JULIA     :   ", 21);
    ft_memcpy(cs->cs.info.content[14], &"NB OF ITERATIONS :   ", 21);
    return (1);
}

void    display_monitoring(t_data *cs)
{
    mlx_string_put(cs->mlx2, cs->win2, 5, 15, RED, "GENERAL");
    mlx_string_put(cs->mlx2, cs->win2, 5, 35, RED, cs->cs.info.content[0]);
    mlx_string_put(cs->mlx2, cs->win2, 5, 55, RED, cs->cs.info.content[1]);
    mlx_string_put(cs->mlx2, cs->win2, 5, 75, RED, cs->cs.info.content[2]);
    mlx_string_put(cs->mlx2, cs->win2, 5, 115, RED, "MANDELBROT");
    mlx_string_put(cs->mlx2, cs->win2, 5, 135, RED, cs->cs.info.content[3]);
    mlx_string_put(cs->mlx2, cs->win2, 5, 155, RED, cs->cs.info.content[4]);
    mlx_string_put(cs->mlx2, cs->win2, 5, 175, RED, cs->cs.info.content[5]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 15, RED, "JULIA");
    mlx_string_put(cs->mlx2, cs->win2, 300, 35, RED, cs->cs.info.content[6]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 55, RED, cs->cs.info.content[7]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 75, RED, cs->cs.info.content[8]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 95, RED, cs->cs.info.content[9]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 115, RED, cs->cs.info.content[10]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 165, RED, "OFFSET");
    mlx_string_put(cs->mlx2, cs->win2, 300, 185, RED, cs->cs.info.content[11]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 205, RED, cs->cs.info.content[12]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 225, RED, cs->cs.info.content[13]);
    mlx_string_put(cs->mlx2, cs->win2, 300, 245, RED, cs->cs.info.content[15]);
    mlx_string_put(cs->mlx2, cs->win2, 5, 195, RED, cs->cs.info.content[14]);
}

void    display_control_screen(t_data *cs)
{
    int i;

    i = 0;
    if (!cs->mlx2)
    {
        cs->mlx2 = mlx_init();
	    if (!cs->mlx2)
            return ;
	    cs->win2 = mlx_new_window(cs->mlx2, 540, 360, "CONTROL SCREEN");
	    if (!cs->win2)
            return ;
    }
    cs->cs.info.content = malloc(17 * sizeof(char *));
    while (i < 17)
        cs->cs.info.content[i++] = NULL;
    if (!cs->cs.info.content)
        return ;
    if (!clear_info(cs))
        return ; // maybe some stringput ?
    get_info(cs);
    convert_info(cs);
    mlx_clear_window(cs->mlx2, cs->win2);
    display_monitoring(cs);
    free_info(cs);
}