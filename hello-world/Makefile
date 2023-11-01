CC := gcc
CFLAGS := -O2 -D UNICODE -D _UNICODE -D _WIN32_IE=0x0500 -D WINVER=0x0500 -Wall # -g -pg
LDFLAGS := -Wl,--subsystem,windows -lgdi32 -lwinmm -lmsimg32 -static-libgcc # -g -pg
OBJFILES := main.o

.PHONY: all clean

all: hello-world

hello-world: $(OBJFILES)
	$(CC) -o $@ $< $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $? $(CFLAGS)

clean:
	rm -f $(OBJFILES) hello-world.exe
