#include "MisrToolkit.h"
#include "MisrError.h"
#include <stdio.h>

int main(int argc, char ** argv) {

	int path = 1;
	int resolution = 275;
	int block = 22;
	double line = 511; //Min: 0 Max: 511
	double sample = 2047;  //Min: 0: Max: 2047

	double lat, lon;

	if(MTK_SUCCESS != MtkBlsToLatLon(path, resolution, block, line, sample, &lat, &lon)) {
		printf("Fail to extract lat lon\n");
		exit(1);
	}
	printf("Lat: %lf\t Lon: %lf\n", lat, lon);
	return 0;
}
