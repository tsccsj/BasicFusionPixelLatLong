# BasicFusionPixelLatLong

This is the code repository for the functionalities to calculate the latitude and the longitude values for different satallite instruments for TerraFusion(https://github.com/TerraFusion) project.  

It provides functionalities for three instruments: MODIS, ASTER and MISR

# Dependency
The functionalities for MISR depends on [HDFEOS2](http://hdfeos.org/software/library.php#HDF-EOS2) and [MISR Toolkit](https://eosweb.larc.nasa.gov/project/misr/tools/misr_toolkit) (MTK).  
There is no dependency for MODIS and ASTER

# Instruments
## MODIS
MODIS only provides the latitude and the longitude of each native pixels at 1000m resolution. Interpolation is thus necessary to get the coordinates at 500m and 250m resolution. Based on the co-registration arrangement of MODIS cells, a modified *spherical* bilinear interpolation is first used to get the coordinates of 500m-resolution pixels from the 1000m-resolution pixel coordinates. A similar procedure is conducted again to get the 250m-resolution pixel coordinates from 500m-resolution ones.  

## ASTER
In each ASTER L1T image, a 11 \* 11 grid of latitudes and longitudes are provided for uniformly-spaced line and sample locations. The (1,1), (1,11), (11,1) and (11,11) points in the 11 * 11 grids correspond to the pixel centers four cornering pixels of the image. The remaining points may not align with the native pixel centers when the number of lines and the number of samples are not multiples of ten. In order to get the latitude and longitude of a native pixel, its four neighboring points in the 11 * 11 grids are first identified. Then the latitude and longitude of that pixel is calculated using a modified *spherical* bilinear interpolation using the four neighboring coordinates. 

## MISR
The latitude and the longitude of MISR pixels can be calculate using MTK. MTK is a simplified programming interface to access MISR L1B2, L2, conventional and ancillary data products. Based on the resolution, path, block, line, and sample of each pixel, MTK provides functionalities to derive its latitude and longitude in WGS84.

# Spherical Bilinear Interpolation for MODIS and ASTER
Derivation coordinates of both MODIS and ASTER requires bilinear interpolation. Bilinear interpolation is a method to interpolated the value at a specific location based on the values of its four neighboring points from a rectilinear 2D grid. Counterintuitively, in this application, the latitudes and the longitudes are the values to be interpolated, while the input locations in the interpolation are the relative pixel counts (e.g, 0.25 pixels along line direction and 0.5 pixel along sample direction).  
Using the latitudes and longitudes as values in conventional bilinear interpolation is problematic on a sphere. The average of latitudes and longitudes of two points is different from the midpoint of these two locations. As a result, a pseudo bilinear interpolation based on spherical surface is used as an alternative. Rather than using a linear interpolation to get the latitudes and longitudes, the new latitudes and longitudes are calculated as the interpolation points along the great circle arc. 

