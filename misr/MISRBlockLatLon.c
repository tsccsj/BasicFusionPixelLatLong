#include "MisrToolkit.h"
#include "MisrError.h"
#include <stdio.h>

void blockLatLon(int path, int resolution, int blockID, int maxLine, int maxSample, double * lat, double * lon) {

	int * blockArr;
	float * lineArr;
	float * sampleArr;

	if(NULL == (blockArr = (int *)malloc(maxLine * maxSample * sizeof(int)))) {
		printf("Out of memory when allocating blockArr\n");
		exit(1);
	}
	if(NULL == (lineArr = (float *)malloc(maxLine * maxSample * sizeof(float)))) {
		printf("Out of memory when allocating lineArr\n");
		exit(1);
	}
	if(NULL == (sampleArr = (float *)malloc(maxLine * maxSample * sizeof(float)))) {
		printf("Out of memory when allocating sampleArr\n");
		exit(1);
	}

	int i, j;
	for(i = 0; i < maxLine; i++) {
		for(j = 0; j < maxSample; j++) {
			blockArr[i * maxSample + j] = blockID;
			lineArr[i * maxSample + j] = i;
			sampleArr[i * maxSample + j] = j;
		}
	}
	
	if(MTK_SUCCESS != MtkBlsToLatLonAry(path, resolution, maxLine * maxSample, blockArr, lineArr, sampleArr, lat, lon)) {
		printf("Fail to extract lat lon\n");
		exit(1);
	}

	free(blockArr);
	free(lineArr);
	free(sampleArr);	
}


int main(int argc, char ** argv) {

	int path = 1;
	int resolution = 275;
	int block = 22;
	int maxLine = 512;
	int maxSample = 2048;

	double * lat;
	double * lon;

	if(NULL == (lat = (double *)malloc(maxLine * maxSample * sizeof(double)))) {
		printf("Out of memory when allocating lat\n");
		exit(1);
	}
	if(NULL == (lon = (double *)malloc(maxLine * maxSample * sizeof(double)))) {
		printf("Out of memory when allocating lon\n");
		exit(1);
	}


	blockLatLon(path, resolution, block, maxLine, maxSample, lat, lon);

	int i, j;
	for(i = 0; i < maxLine; i++) {
		for(j = 0; j < maxSample; j++) {
			printf("%d\t,%d\t,%lf\t,%lf\n", i, j, lat[i * maxSample + j], lon[i * maxSample + j]);
		}
	}

	free(lat);
	free(lon);

	return 0;
}
