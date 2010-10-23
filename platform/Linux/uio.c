/************************************************************************

 Copyright (C) 2009 Renesas Solutions Corp.

 This code is LGPL license

 Kuninori Morimoto <morimoto.kuninori@renesas.com>

************************************************************************/
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "uio.h"
/************************************************************************


                        struct / define


************************************************************************/

#define MAXNAMELEN 256
#ifdef _DEBUG
#define perr(a...) printf("uio: " a)
#else
#define perr(a...)
#endif

/************************************************************************

                      local function

                      device / memory

************************************************************************/
static int read_file(char *fname, char *buf, int maxlen)
{
	FILE *fp;

	fp = fopen(fname, "r");
	if (!fp)
		return -1;

	fgets(buf, maxlen, fp);
	fclose(fp);

	return (int)strlen(buf);
}

static int open_device(const char *name, struct uio_device *udp)
{
	char fname[MAXNAMELEN], buf[MAXNAMELEN];
	char *tmp;
	int uio_id;

	uio_id = -1;
	do {
		uio_id++;
		snprintf(fname, MAXNAMELEN, "/sys/class/uio/uio%d/name", uio_id);
		if (read_file(fname, buf, MAXNAMELEN) < 0) {
			perr("no %s uio\n", name);
			return -1;
		}

	} while (strncmp(name, buf, strlen(name)));

	tmp = strchr(buf, '\n');
	if (tmp)
		*tmp = '\0';

	udp->name = strdup(buf);
	udp->path = strdup(fname);
	udp->path[strlen(udp->path) - 5] = '\0';

	snprintf(buf, MAXNAMELEN, "/dev/uio%d", uio_id);
	udp->fd = open(buf, O_RDWR | O_SYNC);

	if (udp->fd < 0) {
		perr("can not open %s\n", buf);
		return -1;
	}

	return 0;
}

static void close_device(struct uio_device *udp)
{
	if (!udp)
		return;

	if (udp->name)
		free(udp->name);

	if (udp->path)
		free(udp->path);

	if (udp->fd)
		close(udp->fd);

	udp->name = NULL;
	udp->path = NULL;
	udp->fd   = 0;
}

static int setup_map(struct uio_device *udp, int nr, struct uio_map *ump)
{
	char fname[MAXNAMELEN], buf[MAXNAMELEN];

	snprintf(fname, MAXNAMELEN, "%s/maps/map%d/addr", udp->path, nr);
	if (read_file(fname, buf, MAXNAMELEN) <= 0) {
		perr("can not read %s\n", fname);
		return -1;
	}

	ump->addr = strtoul(buf, NULL, 0);

	snprintf(fname, MAXNAMELEN, "%s/maps/map%d/size", udp->path, nr);
	if (read_file(fname, buf, MAXNAMELEN) <= 0) {
		perr("can not read %s\n", fname);
		return -1;
	}

	ump->size = strtoul(buf, NULL, 0);
	ump->iomem = mmap(0, ump->size,
			  PROT_READ | PROT_WRITE,
			  MAP_SHARED,
			  udp->fd,
			  nr * getpagesize());

	if (ump->iomem == MAP_FAILED) {
		perr("mmap failed\n");
		return -1;
	}

	return 0;
}

static void close_map(struct uio_map *ump)
{
	if (!ump)
		return;

	if (ump->iomem)
		munmap(ump->iomem, ump->size);

	ump->iomem = NULL;
	ump->size  = 0;
}

/************************************************************************

                      global function

                      uio open / close

************************************************************************/
void uio_close(struct uio *uio)
{
	close_device(&uio->dev);
	close_map(&uio->mmio);
	close_map(&uio->mem);
}

int uio_open(struct uio *uio, const char *name)
{
	int ret = 0;

	ret = open_device(name, &uio->dev);
	if (ret < 0) {
		perr("device open error\n");
		return ret;
	}

	ret = setup_map(&uio->dev, 0, &uio->mmio);
	if (ret < 0) {
		perr("MMIO setup error\n");
		return ret;
	}

	ret = setup_map(&uio->dev, 1, &uio->mem);
	if (ret < 0) {
		perr("memory setup error\n");
		return ret;
	}

	uio->dev.lock = 0;

	return ret;
}

/************************************************************************

                      global function

                        read / write

************************************************************************/
u32 uio_read32(struct uio_map *ump, u32 ofs)
{
	volatile u32 *reg = ump->iomem;

	return reg[ofs / 4];
}

u16 uio_read16(struct uio_map *ump, u32 ofs)
{
	volatile u16 *reg = ump->iomem;

	return reg[ofs / 2];
}

u8 uio_read8(struct uio_map *ump, u32 ofs)
{
	volatile u8 *reg = ump->iomem;

	return reg[ofs];
}

void uio_write32(struct uio_map *ump, u32 val, u32 ofs)
{
	volatile u32 *reg = ump->iomem;

	reg[ofs / 4] = val;
}

void uio_write16(struct uio_map *ump, u16 val, u32 ofs)
{
	volatile u16 *reg = ump->iomem;

	reg[ofs / 2] = val;
}

void uio_write8(struct uio_map *ump, u8 val, u32 ofs)
{
	volatile u8 *reg = ump->iomem;

	reg[ofs] = val;
}

/************************************************************************


                      global function

                       interrupt

************************************************************************/
int uio_wait_interrupt(struct uio *uio)
{
	int event_cnt = 0;

	if (!uio)
		return -1;

	if (uio->dev.lock) {
		/* Wait for an interrupt */
		uio->dev.lock = 0;
		read(uio->dev.fd, &event_cnt, sizeof(int));
	}

	return event_cnt;
}

int uio_allow_interrupt(struct uio *uio)
{
	int enable = 1;

	if (!uio)
		return -1;

	if (!uio->dev.lock) {
		/* allow interrupt again */
		write(uio->dev.fd, &enable, sizeof(int));
		uio->dev.lock = 1;
	}

	return 0;
}
