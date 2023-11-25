TARGET:= ussr_lib.so
TEST := test
DEBUG := ussr_dbg.so

ALLPROGS= $(TARGET) $(TEST) $(DEBUG)

.PHONY:	all clean

all: $(ALLPROGS)
progs: $(PROGRAMS)

$(TEST): 
	$(MAKE) -C src/ ../test

$(TARGET): 
	$(MAKE) -C src/ ../ussr_lib.so

$(DEBUG):
	$(MAKE) -C src/ ../ussr_dbg.so


clean:

	rm -f $(ALLPROGS) src/*.o src/*.d

.PHONY: clean
