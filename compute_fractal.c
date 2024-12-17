#include "fractals.h"

static void paint_nova(t_data *d, t_build *b)
{
    double module;

    if (d->s.screen_mode == 3)
    {
        // Méthode Newton-Raphson : z_{n+1} = z_n - f(z) / f'(z)
        b->tp = b->zx; // Sauvegarde temporaire de zx
        b->tp2 = b->zy;

        // Calcul de f(z) = z^3 - 1
        double fz_re = b->zx * b->zx * b->zx - 3 * b->zx * b->zy * b->zy - 1;
        double fz_im = 3 * b->zx * b->zx * b->zy - b->zy * b->zy * b->zy;

        // Calcul de f'(z) = 3z^2
        double fz_deriv_re = 3 * (b->zx * b->zx - b->zy * b->zy);
        double fz_deriv_im = 6 * b->zx * b->zy;

        // Division complexe : f(z) / f'(z)
        double denom = fz_deriv_re * fz_deriv_re + fz_deriv_im * fz_deriv_im;
        if (denom == 0.0) // Évite division par zéro
            return ;
        double correction_re = (fz_re * fz_deriv_re + fz_im * fz_deriv_im) / denom;
        double correction_im = (fz_im * fz_deriv_re - fz_re * fz_deriv_im) / denom;

        // Nouvelle valeur de z : z_{n+1} = z_n - correction
        b->zx = b->zx - correction_re;
        b->zy = b->zy - correction_im;

        // Vérifie convergence vers une racine
        module = correction_re * correction_re + correction_im * correction_im;
        if (module < 0.000001) // Tolérance de convergence
            return ;
    }
}

void    compute_czxy(t_data *d, t_build *b, int *i)
{
    if (d->s.screen_mode == 1)
    {
        b->cx = ((b->x - d->s.WI / 2.0) * 4.0 / d->s.WI) * d->s.zoom + d->s.mx;
        b->cy = ((b->y - d->s.HI / 2.0) * 4.0 / d->s.HI) * d->s.zoom + d->s.my;
        b->zx = 0;
        b->zy = 0;
    }
    if (d->s.screen_mode == 3)
    {
        b->zx = 1.5 * (b->x - d->s.WI / 2) / (0.5 * d->s.zoom * d->s.WI) + d->s.mx;
        b->zy = (b->y - d->s.HI / 2) / (0.5 * d->s.zoom * d->s.HI) + d->s.my;
    }
    if (d->s.screen_mode == 2)
    {
        b->zx = 1.5 * (b->x - d->s.WI / 2) / (0.5 * d->s.zoom * d->s.WI) + d->s.mx;
        b->zy = (b->y - d->s.HI / 2) / (0.5 * d->s.zoom * d->s.HI) + d->s.my;
    }
    if (d->s.screen_mode == 4)
    {
        b->zx = 0;
        b->zy = 0;
    }
    *i = 0;
}

int    check_limits(t_data *d, t_build *b, int *i)
{
    if (b->zx * b->zx + b->zy * b->zy < 4.0  && *i < d->f.m.mi)
        return (1);
    return (0);
}

void    paint_x_axis(t_data *d, t_build *b, int *i)
{
    if (d->s.screen_mode == 1)
    {
        b->tp = b->zx * b->zx - b->zy * b->zy + b->cx;
        b->zy = 2.0 * b->zx * b->zy + b->cy;
        b->zx = b->tp;
    }
    if (d->s.screen_mode == 2)
    {
        b->tp = b->zx * b->zx - b->zy * b->zy + d->s.julia_cx;
        b->zy = 2.0 * b->zx * b->zy + d->s.julia_cy;
        b->zx = b->tp;
    }
    if (d->s.screen_mode == 3)
        paint_nova(d, b);
    if (d->s.screen_mode == 4)
        (void)b;
    *i += 1;
}

void    map_pixel(t_data *d, t_build *b, int color)
{
    int ok;

    ok = 0;
    if (b->x >= 0 && b->x < d->s.WI && b->y >= 0 && b->y < d->s.HI)
        ok = 1;
    if (ok != 1)
        return ;
    if (d->s.screen_mode == 1)
    {
        d->f.m.pindex = b->y * d->f.m.l + b->x * (d->f.m.b / 8);
        *(int *)(d->f.m.a + d->f.m.pindex) = color;
    }
    if (d->s.screen_mode == 2)
    {
        d->f.j.pindex = b->y * d->f.j.l + b->x * (d->f.j.b / 8);
        *(int *)(d->f.j.a + d->f.j.pindex) = color;
    }
    if (d->s.screen_mode == 3 || d->s.screen_mode == 4)
    {
        d->f.n.pindex = b->y * d->f.n.l + b->x * (d->f.n.b / 8);
        *(int *)(d->f.n.a + d->f.n.pindex) = color;
    }
}