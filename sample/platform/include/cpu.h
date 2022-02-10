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
#ifndef CPU_H
#define CPU_H

#include <lss2_cpu.h>
#include <std.h>

/*=====================================
 *
 *		define
 *
 *=====================================*/
#define INSTALL_CPU(xname)			\
	const struct lss2_cpu cpu_##xname = {	\
		.name	= #xname,		\
		.init	= init,			\
	};

#define CPU_EXTERN(name) extern const struct lss2_cpu cpu_##name;
#define CPU_DEFINE(name) &cpu_##name,
#define CPU_LIST_SIZE   const static int cpulistsize = ARRAY_SIZE(cpulist)


#endif /* CPU_H */
