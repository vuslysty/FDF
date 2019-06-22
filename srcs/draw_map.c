#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"

#define L_UP 	fdf->corner[0].z
#define L_DOWN	fdf->corner[2].z
#define R_UP 	fdf->corner[1].z
#define R_DOWN 	fdf->corner[3].z

#define CURR_THREAD fdf->t[mth->thread_index] == mth->curr_thread

void	draw_from_left_up(t_fdf *fdf, t_mthread *mth, int x, int y)
{
	while (++mth->d < fdf->map->cols + fdf->map->rows)
	{
		x = mth->d;
		y = 0;
		if (x >= fdf->map->cols)
		{
			y = x - (fdf->map->cols - 1);
			x = fdf->map->cols - 1;
		}
		while (x >= 0 && y < fdf->map->rows)
		{
			if (x < fdf->map->cols && y < fdf->map->rows)
			{
				mth->thread_index = ++mth->count % 4;
				if (x != fdf->map->cols - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y][x + 1], fdf);
				if (y != fdf->map->rows - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y + 1][x], fdf);
			}
			x--;
			y++;
		}
	}
}

void	draw_from_right_up(t_fdf *fdf, t_mthread *mth, int x, int y)
{
	while (++mth->d < fdf->map->cols + fdf->map->rows)
	{
		x = (fdf->map->cols - 1) - mth->d;
		y = 0;
		if (x < 0)
		{
			y = -x;
			x = 0;
		}
		while (x < fdf->map->cols && y < fdf->map->rows)
		{
			if (x >= 0 && y < fdf->map->rows)
			{
				mth->thread_index = ++mth->count % 4;
				if (x != 0 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y][x - 1], fdf);
				if (y != fdf->map->rows - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y + 1][x], fdf);
			}
			x++;
			y++;
		}
	}
}

void	draw_from_left_down(t_fdf *fdf, t_mthread *mth, int x, int y)
{
	while (++mth->d < fdf->map->cols + fdf->map->rows)
	{
		x = mth->d;
		y = fdf->map->rows - 1;
		if (x < 0)
		{
			y = y - (x - (fdf->map->cols - 1));
			x = fdf->map->cols - 1;
		}
		while (x >= 0 && y >= 0)
		{
			if (x < fdf->map->cols && y < fdf->map->rows)
			{
				mth->thread_index = ++mth->count % 4;
				if (x != fdf->map->cols - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y][x + 1], fdf);
				if (y != fdf->map->rows - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y + 1][x], fdf);
			}
			x--;
			y--;
		}
	}
}

void	draw_from_right_down(t_fdf *fdf, t_mthread *mth, int x, int y)
{
	while (++mth->d < fdf->map->cols + fdf->map->rows)
	{
		x = (fdf->map->cols - 1) - mth->d;
		y = fdf->map->rows - 1;
		if (x < 0)
		{
			y = y + x;
			x = 0;
		}
		while (x < fdf->map->cols && y >= 0)
		{
			if (x >= 0 && y < fdf->map->rows)
			{
				mth->thread_index = ++mth->count % 4;
				if (x != fdf->map->cols - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y][x + 1], fdf);
				if (y != fdf->map->rows - 1 && CURR_THREAD)
					line_clip_and_draw(fdf->map->rot[y][x],
							fdf->map->rot[y + 1][x], fdf);
			}
			x++;
			y--;
		}
	}
}

void	*draw_map(void *param)
{
	t_fdf *fdf = (t_fdf*)param;

	t_mthread	mthread;

	mthread.count = -1;
	mthread.curr_thread = pthread_self();
	mthread.d = -1;

	if (L_UP <= L_DOWN && L_UP <= R_DOWN && L_UP <= R_UP)
		draw_from_left_up(fdf, &mthread, 0, 0);
	else if (R_UP <= L_UP && R_UP <= R_DOWN && R_UP <= L_DOWN)
		draw_from_right_up(fdf, &mthread, 0, 0);
	else if (L_DOWN <= L_UP && L_DOWN <= R_DOWN && L_DOWN <= R_UP)
		draw_from_left_down(fdf, &mthread, 0, 0);
	else
		draw_from_right_down(fdf, &mthread, 0, 0);
	return (NULL);
}