###########################################
#
# version
#
###########################################
MAJORVERSION	= 0
LEVELVERSION	= 0
MINORVERSION	= 1
EXTRAVERSION	= 1

###########################################
#
# settings from user
#
###########################################
-include .config

ifndef PLATFORM
PLATFORM = dummy
endif

ifndef ARCH
ARCH = dummy
endif

###########################################
#
# necessary variable
#
###########################################
SUBDIR	+= common platform

###########################################
#
# This Makefile is used from script/Makefile.XXX
# Below settings are not necessary for it.
#
###########################################
ifndef TOP
include ./script/Makefile.common

# variable export
export MAJOR_VERSION = ${MAJORVERSION}
export LEVEL_VERSION = ${LEVELVERSION}
export MINOR_VERSION = ${MINORVERSION}
export EXTRA_VERSION = ${EXTRAVERSION}
export PLATFORM
export ARCH

# make target
.PHONY : clean

all: depend.mk
	${MYMAKE} all -f ${TOP}/script/Makefile.build;
	${MYMAKE} all -C sample -f ${TOP}/script/Makefile.build;

depend.mk:
	${MYMAKE} all -f ${TOP}/script/Makefile.depend;
	${MYMAKE} all -C sample -f ${TOP}/script/Makefile.depend;

clean:
	${MYMAKE} all -f ${TOP}/script/Makefile.clean;
	${MYMAKE} all -C sample -f ${TOP}/script/Makefile.clean;

endif # TOP