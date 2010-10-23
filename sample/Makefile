OBJ		+= test_platform.o
TARGET		= test_platform
LINCLUDE	+= ${TOP}/sample.platform/include

test_platform: test_platform.o ../builtin.o
	${ECHO} "$@"
	@$(CC) $(CFLAGS) $(INCLUDE) $(LFLAGS) -o $@ test_platform.o ../builtin.o
	@$(STRIP) $@
