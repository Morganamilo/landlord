ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

CC		= gcc
LINK		= gcc 

SRCDIR		= src
OBJDIR		= obj
TARGETDIR	= bin

INC		= 
LIB		= 

TARGET		= landlord

SOURCES		= $(wildcard $(SRCDIR)/*.c)
HEADERS		= $(wildcard $(SRCDIR)/*.h)
OBJECTS		= $(SOURCES:src/%.c=obj/%.o)

.PHONY: all install uninstall clean

all: $(TARGETDIR)/$(TARGET)

$(TARGETDIR)/$(TARGET): $(OBJECTS) | $(TARGETDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(CFLAGS) $(INC) -c -o $@ $<

$(TARGETDIR)/$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

$(OBJDIR):
	mkdir $(OBJDIR)

$(TARGETDIR):
	mkdir $(TARGETDIR)

install: $(TARGETDIR)/$(TARGET)
	install -Dm755 $(TARGETDIR)/$(TARGET) $(PREFIX)/bin/$(TARGET)

uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)

clean:
	rm -rf $(OBJDIR)
	rm -rf ${TARGETDIR}
