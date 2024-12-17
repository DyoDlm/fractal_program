#include "fractals.h"

/*
void    build_random_fimg(t_data *d)
{
    int     i;
    int     color;
    t_build b;

    init_build(&b);
    replace_image(&d->f.n.img, d->mlx, d->s.WI, d->s.HI);
    d->f.n.a = mlx_get_data_addr(d->f.n.img, &d->f.n.b, &d->f.n.l, &d->f.n.e);
    while (b.y < d->s.HI)
    {
        b.x = 0;
        while (b.x < d->s.WI)
        {
            compute_czxy(d, &b, &i);
            while (check_limits(d, &b, &i))
                paint_x_axis(d, &b, &i);
            if (i == d->f.m.mi)
                color = BLACK;
            else
                color = d->s.color * i / d->s.disolvant;
            map_pixel(d, &b, color);
            b.x += 1;
        }
        b.y += 1;
    }
}

void    build_mandelbrot_img(t_data *d)
{
    int     i;
    int     color;
    t_build b;

    init_build(&b);
    replace_image(&d->f.m.img, d->mlx, d->s.WI, d->s.HI);
    d->f.m.a = mlx_get_data_addr(d->f.m.img, &d->f.m.b, &d->f.m.l, &d->f.m.e);
    while (b.y < d->s.HI)
    {
        b.x = 0;
        while (b.x < d->s.WI)
        {
            compute_czxy(d, &b, &i);
            while (check_limits(d, &b, &i))
                paint_x_axis(d, &b, &i);
            if (i == d->f.m.mi)
                color = BLACK;
            else
                color = d->s.color * i / d->s.disolvant;
            map_pixel(d, &b, color);
            b.x += 1;
        }
        b.y += 1;
    }
}

void    build_julia_img(t_data *d)
{
    int     i;
    int     color;
    t_build b;

    init_build(&b);
    replace_image(&d->f.j.img, d->mlx, d->s.WI, d->s.HI);
    d->f.j.a = mlx_get_data_addr(d->f.j.img, &d->f.j.b, &d->f.j.l, &d->f.j.e);
    while (b.y < d->s.HI)
    {
        b.x = 0;
        while (b.x < d->s.WI)
        {
            compute_czxy(d, &b, &i);
            while (check_limits(d, &b, &i))
                paint_x_axis(d, &b, &i);
            if (i == d->f.m.mi)
                color = BLACK;
            else
                color = d->s.color * i / d->s.disolvant;
            map_pixel(d, &b, color);
            b.x += 1;
        }
        b.y += 1;
    }
}

void    build_newton_img(t_data *d)
{
    int     i;
    int     color;
    t_build b;

    init_build(&b);
    replace_image(&d->f.n.img, d->mlx, d->s.WI, d->s.HI);
    d->f.n.a = mlx_get_data_addr(d->f.n.img, &d->f.n.b, &d->f.n.l, &d->f.n.e);
    while (b.y < d->s.HI)
    {
        b.x = 0;
        while (b.x < d->s.WI)
        {
            compute_czxy(d, &b, &i);
            while (check_limits(d, &b, &i))
                paint_x_axis(d, &b, &i);
            if (i == d->f.m.mi)
                color = BLACK;
            else
                color = d->s.color * i / d->s.disolvant;
            map_pixel(d, &b, color);
            b.x += 1;
        }
        b.y += 1;
    }
}*/