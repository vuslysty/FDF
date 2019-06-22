#include "fdf.h"
#include "mlx.h"
#include <sys/time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
	return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) /
											   1000.0f;
}

void	start_fps(t_fps *fps, t_fdf *fdf)
{
	if (fdf->param.fps)
		gettimeofday(&fps->t0, 0);
}

void	end_fps(t_fps *fps, t_fdf *fdf)
{
	char	*time;

	if (fdf->param.fps)
	{
		gettimeofday(&fps->t1, 0);
		fps->diff = 1000.0 / timedifference_msec(fps->t0, fps->t1);
		time = ft_itoa((int)fps->diff);
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0xFF0000, time);
		free(time);
	}
}