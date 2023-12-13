includedir=$(prefix)/include

build:

install: $(includedir)/aVec.H

$(includedir)/aVec.H: aVec.H
	mkdir -p $(includedir)
	cp aVec.H $(includedir)

uninstall:
	- rm -f $(includedir)/aVec.H

clean:
