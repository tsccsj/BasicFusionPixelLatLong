## Please have hdfeos and mtk installed and run
## source hdfeoslibs/bin/hdfeos_env.sh
## . Mtk-src-1.4.3/bin/Mtk_c_env.sh
## before compiling

CFLAGS := $(MTK_CFLAGS)
LDFLAGS := $(MTK_LDFLAGS)

All: MISRLatLon MISRBlockLatLon

MISRLatLon: MISRLatLon.o
	$(CC) -o $@ $^ $(LDFLAGS)
MISRBlockLatLon: MISRBlockLatLon.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean: 
	rm *.o MISRLatLon MISRBlockLatLon 

