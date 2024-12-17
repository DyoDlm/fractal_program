#include "fractals.h"
#include "get_next_line.h"
#include <stdio.h>

static void check_arguments(t_data *data, int i)
{
    if (data->rules[0] == '0' && i == 0)
    {
        data->s.disolvant = 1;
        free(data->rules);
        data->rules = NULL;
    }
    if (data->rules && i == 1)
    {
        data->s.julia_cx = ft_atof(data->rules);
        free(data->rules);
        data->rules = NULL;
    }
    if (data->rules && i == 2)
    {
        data->s.julia_cy = ft_atof(data->rules);
        free(data->rules);
        data->rules = NULL;
    }
}

static int  check_rules(t_data *data, char *line, int *iteration)
{
    int     i;
    size_t  len;

    len = getlen(line);
    i = *iteration;
    if (len >= 32)
        return (merrors(1), 1);
    data->rules = ft_strdup(line);
    if (!data->rules)
        return (merrors(8), 0);
    check_arguments(data, i);
    free(data->rules);
    *iteration += 1;
    mrules(((i) + 4));
    if (i > 7 || len == 1)
        return (0);
    return (1);
}

static int    intro(t_data *data)
{
    int     i;
    char    *line;

    i = 0;
    line = NULL;
    mrules(1);
    while (1)
    {
        line = get_next_line(0);
        if (line)
        {
            if (!check_rules(data, line, &i))
                return (mrules(2), free(line), i);
            if (ft_strlen(line) != 0)
                mrules(3);
            free(line);
        }
        if (i >= 3)
            break ;
    }
    return (mrules(2), i);
}

void init_data(t_data *data, char state)
{
    if (state == '0')
    {
        data->mlx = NULL;
        data->win = NULL;
    }
    data->mlx2 = NULL;
    data->win2 = NULL;
    data->s.HI = 1080;
    data->s.WI = 1520;
    data->s.size = 0;
    data->s.mpos = 0;
    data->s.zoom = 1.0;
    data->s.mx = 0;
    data->s.my = 0;
    data->s.log_i = 1;
    data->s.screen_mode = 0;
    data->s.color = WHITE;
    data->s.disolvant = 30;
    data->s.julia_cx = -0.7;
    data->s.julia_cy = 0.27015;
    data->rules = NULL;
    data->kimg = NULL;
    init_julia(data);
    init_newton(data);
    init_mandelbrot(data);
    init_control_screen(data);
}

int	main(int ac, char **av)
{
    t_data data;

    if (ac != 1)
        return (merrors(7), EXIT_FAILURE);
    (void)av;
    init_data(&data, '0');
    intro(&data);
    data.mlx = mlx_init();
    if (!data.mlx)
        return (EXIT_FAILURE);
    data.win = mlx_new_window(data.mlx, data.s.HI, data.s.WI, "WAW !");
    if (!data.win)
        return (free_to_go(&data, '0'), EXIT_FAILURE);
    display_home(&data);
    mlx_key_hook(data.win, key_handler, &data);
    mlx_mouse_hook(data.win, mouse_handler, &data); 
    mlx_hook(data.win, 17, 0, close_win, &data);
    mlx_hook(data.win, 6, 0, mouse_move, &data);
    mlx_loop(data.mlx);
    return (EXIT_SUCCESS);
}