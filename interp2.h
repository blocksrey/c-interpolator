#ifndef interp2_h
#define interp2_h

#include "interp_tools.h"

static i32 loop_p(i32 n, i32 x, i32 y) {
	return x%n + y%n*n;
}

static f32 interp2(f32 x, f32 y, f32 a, f32 b, f32 c, f32 d) {
	return a + (b - a)*x + (c - a)*y + (a - b - c + d)*x*y;
}

static f32 noise2(imap *map, f32 *v) {
	i32 x = FLRP(v[0]);
	i32 y = FLRP(v[1]);
	return interp2(
		remap(FRACT(v[0])),
		remap(FRACT(v[1])),
		map->edges[loop_p(map->total, x + 0, y + 0)],
		map->edges[loop_p(map->total, x + 1, y + 0)],
		map->edges[loop_p(map->total, x + 0, y + 1)],
		map->edges[loop_p(map->total, x + 1, y + 1)]
	);
}

#endif
