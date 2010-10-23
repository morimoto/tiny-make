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

#ifndef LSS2_CPU_H
#define LSS2_CPU_H

/*=====================================
 *
 *		struct
 *
 *=====================================*/
struct lss2_cpu {
	const char *name;
	void (*init)(struct lss2_cpu *cpu);
};

/*=====================================
 *
 *		function
 *
 *=====================================*/
const char* lss2_get_supported_cpu_name(int index);

#endif /* LSS2_CPU_H */
