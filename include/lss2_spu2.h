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
#ifndef LSS2_SPU2_H
#define LSS2_SPU2_H

/*=====================================
 *
 *		define
 *
 *=====================================*/
/*
 * version
 */
#define LSS2_VERSION(major, level, minor, extra)\
	(((0xFF & major) << 24) |\
	 ((0xFF & level) << 16) |\
	 ((0xFF & minor) <<  8) |\
	 ((0xFF & extra) <<  0))

#define LSS2_MAJOR_VERSION(version) ((version >> 24) & 0xFF)
#define LSS2_LEVEL_VERSION(version) ((version >> 16) & 0xFF)
#define LSS2_MINOR_VERSION(version) ((version >>  8) & 0xFF)
#define LSS2_EXTRA_VERSION(version) ((version >>  0) & 0xFF)

/*=====================================
 *
 *		function
 *
 *=====================================*/
unsigned int lss2_get_wrapper_version(void);

#endif /* LSS2_SPU2_H */
