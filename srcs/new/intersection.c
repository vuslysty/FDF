#include "fdf.h"

//int 	intersection(t_point *a1, t_point *a2, t_point *b1, t_point *b2)
//{
//	int v1;
//	int v2;
//	int v3;
//	int v4;
//
//	v1 = (b2->x - b1->x) * (a1->y - b1->y) - (b2->y - b1->y) * (a1->x - b1->x);
//	v2 = (b2->x - b1->x) * (a2->y - b1->y) - (b2->y - b1->y) * (a2->x - b1->x);
//	v3 = (a2->x - a1->x) * (b1->y - a1->y) - (a2->y - a1->y) * (b1->x - a1->x);
//	v4 = (a2->x - a1->x) * (b2->y - a1->y) - (a2->y - a1->y) * (b2->x - a1->x);
//	return ((v1 * v2 < 0) && (v3 * v4 < 0));
//}