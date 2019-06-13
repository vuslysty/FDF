#include "fdf.h"

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

t_out_code		compute_out_code(t_point *p, t_fdf *fdf)
{
	t_out_code	code;

	code = INSIDE;
	if (p->x < 0)
		code |= LEFT;
	else if (p->x >= fdf->w_size.x)
		code |= RIGHT;
	if (p->y < 0)
		code |= BOTTOM;
	else if (p->y >= fdf->w_size.y)
		code |= TOP;
	return (code);
}

void			compute_clip_point(t_point *a, t_point *b, t_fdf *fdf,
									t_clipping *cl)
{
	if (cl->out & TOP)
	{
		cl->x = a->x + (b->x - a->x) * (double)(fdf->w_size.y - 1 - a->y) / (b->y - a->y);
		cl->y = fdf->w_size.y - 1;
	}
	else if (cl->out & BOTTOM)
	{
		cl->x = a->x + (b->x - a->x) * (double)(0 - a->y) / (b->y - a->y);
		cl->y = 0;
	}
	else if (cl->out & RIGHT)
	{
		cl->y = a->y + (b->y - a->y) * (double)(fdf->w_size.x - 1 - a->x) / (b->x - a->x);
		cl->x = fdf->w_size.x - 1;
	}
	else if (cl->out & LEFT)
	{
		cl->y = a->y + (b->y - a->y) * (double)(0 - a->x) / (b->x - a->x);
		cl->x = 0;
	}
}

void			set_point_to_new(t_point *a, t_point *b, t_fdf *fdf,
								 t_clipping *cl)
{
	t_point	new_p;
	t_point	delta;

	delta.x = ABS(b->x - a->x);
	delta.y = ABS(b->y - a->y);
	new_p.x = cl->x;
	new_p.y = cl->y;
	if (cl->out == cl->code0)
	{
		new_p.color = get_color(new_p, *b, *a, delta);
		*a = new_p;
		cl->code0 = compute_out_code(a, fdf);
	}
	else
	{
		new_p.color = get_color(new_p, *a, *b, delta);
		*b = new_p;
		cl->code1 = compute_out_code(b, fdf);
	}
}

void			init_lclip(t_point *a, t_point *b, t_fdf *fdf, t_clipping *cl)
{
	cl->accept = 0;
	cl->code0 = compute_out_code(a, fdf);
	cl->code1 = compute_out_code(b, fdf);
}

void	line_clip_and_draw(t_point a, t_point b, t_fdf *fdf)
{
	t_clipping	lclip;

	init_lclip(&a, &b, fdf, &lclip);
	while (1)
	{
		if (!(lclip.code0 | lclip.code1))
		{
			lclip.accept = 1;
			break ;
		}
		else if (lclip.code0 & lclip.code1)
			break ;
		else
		{
			lclip.out = lclip.code0 ? lclip.code0 : lclip.code1;
			compute_clip_point(&a, &b, fdf, &lclip);
			set_point_to_new(&a, &b, fdf, &lclip);
		}
	}
	if (lclip.accept)
		draw_gradient_line(&a, &b, fdf, a);
}