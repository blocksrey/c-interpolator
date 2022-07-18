#ifndef interp_tools_h
#define interp_tools_h

#include "libMaths/maths.h"
#include <stdio.h>
#include <stdlib.h>

static f32 remap(f32 x) {
	return 2*(x < 0.5f ? x*x : 0.5f - (x - 1)*(x - 1));
}

typedef struct {
	i32 total;
	f32 *edges;
} imap;

static usize imap_size = sizeof(imap);
static usize f32_size = sizeof(f32);

static imap *imap_new(i32 len, i32 dim) {
	i32 total = RNDP(POW((f32)len, (f32)dim));

	imap *map = malloc(imap_size + f32_size*total);

	map->total = total;
	map->edges = (f32 *)malloc(f32_size*total);

	for (i32 i = total; i--;)
		map->edges[i] = (f32)(1.*RAND()/RAND_MAX);

	return map;
}

#endif
