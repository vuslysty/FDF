#include <fdf.h>
#include "graphic.h"

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MAX_P2(a, b) ((a.y > b.y) ? (a) : (b))
#define MIN_P2(a, b) ((a.y < b.y) ? (a) : (b))

#define MAX_P3(a, b, c) MAX_P2(MAX_P2(a, b), MAX_P2(b, c))
#define MID_P3(a, b, c) MAX_P2(MIN_P2(a, b), MIN_P2(a, c))
#define MIN_P3(a, b, c) MIN_P2(MIN_P2(a, b), MIN_P2(b, c))


void VID_HLine(int x1, int x2, int y, char c)
{
	int		x;

	if (c)
		;

	for(x=x1; x<=x2; x++)
		put_pixel(&fdf, x, y, 0xFF0000); //add *fdf ^
}


void		polygon_triangle(t_2d p[3], char c)
{
	t_2d	p1d, p2d, p3d;
	int		xd1, yd1, xd2, yd2, i;
	int		lx, rx;

	p1d = MIN_P3(p[0],p[1],p[2]);
	p2d = MID_P3(p[1],p[2],p[0]);
	p3d = MAX_P3(p[2],p[0],p[1]);

	if (p[1].y < p[0].y)
	{
		p1d = MIN_P3(p[1], p[0], p[2]);
		p2d = MID_P3(p[0], p[2], p[1]);
	}

	xd1 = p2d.x - p1d.x;
	yd1 = p2d.y - p1d.y;
	xd2 = p3d.x - p1d.x;
	yd2 = p3d.y - p1d.y;

	if(yd1)
	{
		i = p1d.y - 1;
		while (++i <= p2d.y)
		{
			lx = p1d.x + ((i - p1d.y) * xd1) / yd1;
			rx = p1d.x + ((i - p1d.y) * xd2) / yd2;

			if(lx != rx)
				VID_HLine(MIN(lx,rx), MAX(lx,rx), i, c);
		}
	}

	xd1 = p3d.x-p2d.x;
	yd1 = p3d.y-p2d.y;

	if (yd1)
	{
		i = p2d.y - 1;
		while (++i < p3d.y)
		{
			lx = p1d.x + ((i - p1d.y) * xd2) / yd2;
			rx = p2d.x + ((i - p2d.y) * xd1) / yd1;

			if (lx != rx)
				VID_HLine(MIN(lx,rx), MAX(lx,rx), i, c);
		}
	}
}

void		polygon_draw(t_poligon_2d *polygon)
{
	t_2d	p[3];
	int		i;

	p[0] = polygon->points[0];
	i = 1;
	while (i < polygon->points_count - 1)
	{
		p[1] = polygon->points[i];
		p[2] = polygon->points[i + 1];
		//add function POLY_Triangle
		polygon_triangle(p, 0xff);
		i++;
	}
}



