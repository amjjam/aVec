CPPFLAGS=-Wall -g -fPIC -std=c++11
CPP=g++

AVEC_SRC=aVec.C
AVEC_OBJ=$(AVEC_SRC:.C=.o)

build: libaVec.a libaVec.so

libaVec.a: $(AVEC_OBJ)
	ar rc $@ $^

libaVec.so: $(AVEC_OBJ)
	$(CPP) -shared -Wl,-soname,$@ -o $@ $^

install:
	mkdir -p /opt/amj/lib
	mkdir -p /opt/amj/include
	cp libaVec.a /opt/amj/lib
	cp libaVec.so /opt/amj/lib
	cp ../include/aVec.H /opt/amj/include

uninstall:
	- rm -f /opt/amj/lib/libaVec.a /opt/amj/lib/libaVec.so \
	/opt/amj/include/aVec.H

clean:
	- rm -f libaVec.a libaVec.so $(AVEC_OBJ)
