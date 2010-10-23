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
#ifndef LSS2_ERR_H
#define LSS2_ERR_H

#include <stdio.h>

enum lss2_err {
	LSS2ERR_NONE = 0, /* none */
#define LSS2ERR_DEF
#include <lss2_err.def>
	LSS2ERR_NUM
};

#define lss2_err(err) __lss2_err(err, __FILE__, __FUNCTION__, __LINE__)
#define IS_LSS2ERR(err) (err)

const char* lss2_get_err_string(enum lss2_err err);
void __lss2_err(enum lss2_err err, const char *file,
		const char *func, int line);

#endif /* LSS2_ERR_H */
