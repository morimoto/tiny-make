# tiny-make-v0.1
###########################################
# You can get tiny-make from
#	https://github.com/morimoto/tiny-make.git
#	https://gitlab.com/morimoto.kuninori/tiny-make.git
###########################################
#
# settings from user
#
###########################################
-include .config

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
