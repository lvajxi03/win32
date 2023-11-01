CC := g++
RC := windres
CFLAGS := -O0 -D UNICODE -D _UNICODE -D _WIN32_IE=0x0500 -D WINVER=0x0500 -Wall # -g -pg
LDFLAGS := -Wl,--subsystem,windows -lgdi32 -lwinmm -lmsimg32 -static-libgcc # -g -pg
OBJFILES := main.o res.o

.PHONY: all clean

all: bitmap-paint

bitmap-paint: $(OBJFILES)
	$(CC) -o $@ $? $(LDFLAGS)

res.o: app.rc resources.h
	$(RC) -I. -o $@ -i $<

%.o: %.cc
	$(CC) -o $@ -c $? $(CFLAGS)

clean:
	rm -f $(OBJFILES) bitmap-paint.exe
