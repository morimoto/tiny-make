# tiny-make-v0.1
###########################################
#
# settings from user
#
###########################################
-include .config

###########################################
#
# settings for system
#
###########################################
include sys.config

###########################################
#
# This Makefile is used from script/Makefile.XXX
# Below settings are not necessary for it.
#
###########################################
ifndef TOP
include ./script/Makefile.common

# make target
.PHONY : clean

all: depend.mk
	${MYMAKE} all -f ${TOP}/script/Makefile.build;

depend.mk:
	${MYMAKE} all -f ${TOP}/script/Makefile.depend;

clean:
	${MYMAKE} all -f ${TOP}/script/Makefile.clean;

endif # TOP
