libdir=$(prefix)/lib

CPPFLAGS=-Wall -g -fPIC -std=c++11
CPP=g++

AVEC_SRC=aVec.C
AVEC_OBJ=$(AVEC_SRC:.C=.o)

build: libaVec.a libaVec.so

libaVec.a: $(AVEC_OBJ)
	ar rc $@ $^

libaVec.so: $(AVEC_OBJ)
	$(CPP) -shared -Wl,-soname,$@ -o $@ $^

install: $(libdir)/libaVec.a $(libdir)/libaVec.so

$(libdir)/libaVec.a $(libdir)/libaVec.so: libaVec.a libaVec.so
	cp libaVec.a libaVec.so $(libdir)

uninstall:
	- rm -f $(libdir)/libaVec.a $(libdir)/libaVec.so

clean:
	- rm -f libaVec.a libaVec.so $(AVEC_OBJ)
