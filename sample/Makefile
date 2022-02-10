SUBDIR		= common platform
OBJ		+= test_platform.o
TARGET		= sample_program
LINCLUDE	+= ${TOP}/sample/platform/include

sample_program: ./builtin.o
	${ECHO} "$@"
	@$(CC) $(CFLAGS) $(INCLUDE) $(LFLAGS) -o $@ ./builtin.o
	@$(STRIP) $@
