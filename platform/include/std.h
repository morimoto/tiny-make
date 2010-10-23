/*
 * Copyright (C) 2010 Renesas Solutions Corp.
 * Kuninori Morimoto <kuninori.morimoto.gx@renesas.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.0 of the License, or later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef STD_H
#define STD_H

/*
 * data size
 *
 * FIXME
 *
 * below settings should be controlled correctly
 */
typedef unsigned long	u32;
typedef unsigned short	u16;
typedef unsigned char	u8;

/*
 * array size macro
 */
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

/*
 * container
 */
#define container_of(type, member, ptr) \
	(type *)((unsigned long)ptr - (unsigned long)&(((type *)0)->member))

/*
 * debug print
 */
#ifdef _DEBUG
#define pdebug(format, arg...)					\
	fprintf(stderr, "%s :: %s (%d) > " format,		\
		__FILE__, __FUNCTION__, __LINE__, ##arg);
#else
#define pdebug(format, arg...)
#endif

#endif /* STD_H */
