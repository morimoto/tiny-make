#! /bin/sh
#===============================
#
# create-tiny-make
#
#===============================
TNAME=`head -n 1 Makefile | cut -d' ' -f2`
TLIST=" script\
	Makefile\
	sample.sys.config\
	"

tar -jcf ${TNAME}.tar.bz2 ${TLIST}