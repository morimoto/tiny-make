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
#include <stdio.h>
#include <std.h>
#include <lss2_err.h>
#include <lss2_spu2.h>
#include <lss2_cpu.h>

static void test_name(const char *name)
{
	printf("\n------- test ( %s )\n", name);
}

static void debug_test(void)
{
	test_name("debug");
	printf("If you find \"debug\" here, it is debug mode compile\n");
	pdebug("debug\n");
}

static void err_test(void)
{
	int i;

	test_name("error");
	for (i = 0; i < LSS2ERR_NUM; i++)
		if (IS_LSS2ERR(i))
			lss2_err(i);
}

static void version_test(void)
{
	u32 ver = lss2_get_wrapper_version();
	u32 extra = LSS2_EXTRA_VERSION(ver);

	test_name("version");

	printf("version: %ld.%ld.%ld",
	       LSS2_MAJOR_VERSION(ver),
	       LSS2_LEVEL_VERSION(ver),
	       LSS2_MINOR_VERSION(ver));

	if (extra)
		printf("-rc%ld", extra);

	printf(" (%08lx)\n", ver);
}

static void supported_cpu_test(void)
{
	int i;
	const char* name;

	test_name("supported_cpu");
	for (i = 0;; i++) {
		name = lss2_get_supported_cpu_name(i);
		if (!name)
			break;

		printf("%s\n", name);
	}
}

int main(int nargc, char *argv[])
{
	debug_test();
	err_test();
	version_test();
	supported_cpu_test();

	return 0;
}
