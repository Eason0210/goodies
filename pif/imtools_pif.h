/* --------------------------------------------------------------------------
 *  Date: April 16, 1998
 *
 *
 *  Copyright (c) 1995-1998, InnovMetric Software Inc.
 *
 *  ALL RIGHTS RESERVED. Permission to use, copy, modify,
 *  and distribute this software for any purpose and
 *  without fee is hereby granted.
 *
 *  IN NO EVENT WILL INNOVMETRIC SOFTWARE INC. BE LIABLE
 *  FOR (1) SPECIAL, INDIRECT, INCIDENTAL OR CONSEQUENTIAL
 *  DAMAGES, OR (2) ANY DAMAGES RESULTING FROM LOSS OF USE,
 *  OR LOSS OF DATA, OR LOSS OF PROFITS ARISING OUT OF OR
 *  IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE
 *  OR ANY INFORMATION PROVIDED HEREUNDER, WHETHER IN AN
 *  ACTION BASED ON CONTRACT OR TORT, INCLUDING NEGLIGENCE.
 * ------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
    WARNING - WARNING - WARNING - WARNING - WARNING

    It is assumed in this PIF programming library that
    the data type "long" represents a 32-bit integer
    number.
 * ------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * imtools_pif.h
 *
 * Version 2.0
 * ------------------------------------------------------------------------- */

#pragma once



#ifdef __cplusplus
extern "C"
{
#endif // ifdef __cplusplus


/* -------------------------------------------------------------------------
 * INCLUDE FILES AND DEFINITIONS
 * ------------------------------------------------------------------------- */
#ifndef IMTOOLS_DLL
#define IMTOOLS_DLL __declspec( dllimport )
#endif  /* IMTOOLS_DLL */

/* --- Type of parameterization --- */
#define PIF_PLANAR          0
#define PIF_CYLINDRICAL     1

/* --- Type of 3-D data --- */
#define PIF_INTERPOLATED    0
#define PIF_RAW             1
#define PIF_POLYGONAL       2

/* --- Type of color data --- */
#define PIF_GREY_LEVEL      1
#define PIF_RGB_COLORS      3
#define PIF_RGBA_COLORS     4

/* --- Error codes returned by the PIF library routines --- */
#define PIF_NO_ERROR         0
#define PIF_INVALID_FLAG    -1
#define PIF_INVALID_STRING  -2
#define PIF_WRITE_ERROR     -3


/* -------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 * ------------------------------------------------------------------------- */
/* *************************************************************************
   pif_file_allocate:   First invoked routine. It allocates space and
                        initializes the file structure.

   pif_file_free:       Last invoked routine. It frees the allocated space.

   pif_file_write:      Writes the PIF file.
************************************************************************* */

/* -------------------------------------------------------------------------
 * Allocates space for a pif_file_t structure and initializes
 *              the header part of a PIF file. By default, there are no
 *              comments, no scaling factors, no color information and the
 *              transformation matrix is an identity matrix.
 *
 * Parameters:  None
 *
 * Returns:     A pointer to the allocated block.
 *              A NULL pointer is returned if malloc has failed.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void* pif_file_allocate( void );

/* -------------------------------------------------------------------------
 * Frees the space occupied by the pif_file_t structure.
 *
 * Parameters:  ptr:    Pointer to the allocated structure.
 *
 * Returns:     Nothing.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_file_free( void* ptr );

/* -------------------------------------------------------------------------
 * Writes the specified 3-D image in a file.
 *
 * Parameters:  ptr:        Pointer to the file structure.
 *              filename:   Name under which the 3-D image will be saved.
 *
 * Returns:     PIF_NO_ERROR or,
 *              PIF_WRITE_ERROR if an error has occurred.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL int pif_file_write( void* ptr, const char* filename );




/* *************************************************************************
   pif_header_comments:             Places a string in the header block.

   pif_header_camera_position:      Defines an optional camera position.

   pif_header_optional_scaling:     Defines optional scaling factors
                                    for a raw or polygonal 3-D image.

   pif_header_matrix_DCS_to_ICS:    Specifies a 4x4 matrix that
                                    transforms the DCS into the ICS

   pif_header_matrix_ICS_to_DCS:    Specifies a 4x4 matrix that
                                    transforms the ICS into the DCS

   pif_header_matrix_DCS_z_axis:    Specifies the z_axis of the ICS
                                    in the DCS. A 4x4 matrix is
                                    automatically generated.
************************************************************************* */

/* -------------------------------------------------------------------------
 * Places a string containing user comments in the header.
 *
 * Parameters:  ptr:        Pointer to the file structure.
 *              comments:   A string containing user comments.
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_header_comments( void* ptr, const char* comments );

/* -------------------------------------------------------------------------
 * Defines the camera position.
 *
 * Parameters:  ptr:        Pointer to the file structure.
 *              camera_x:   X coordinate of the camera.
 *              camera_y:   Y coordinate of the camera.
 *              camera_z:   Z coordinate of the camera.
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_header_camera_position(
    void* ptr,
    float camera_x,
    float camera_y,
    float camera_z );

/* -------------------------------------------------------------------------
 * Defines scaling factors for a raw or polygonal data types.
 *
 * Parameters:  ptr:        Pointer to the file structure.
 *              i_scale:    Scaling factor for the i coordinate.
 *              j_scale:    Scaling factor for the j coordinate.
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_header_optional_scaling(
    void*  ptr,
    double i_scale,
    double j_scale );

/* -------------------------------------------------------------------------
 * Specifies a 4x4 matrix transforming the Data Coordinate
 *              System into the Intermediate Coordinate system.
 *
 * Parameters:  ptr:    Pointer to the file structure.
 *              matrix: Vector containing the 16 matrix elements.
 *                      The elements are specified from left to
 *                      right and from top to bottom:
 *
 *                      m1  m2  m3  m4
 *                      m5  m6  m7  m8
 *                      m9  m10 m11 m12
 *                      m13 m14 m15 m16
 *
 *                      The matrix premultiplies the points
 *                      to be transformed.
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_header_matrix_DCS_to_ICS( void* ptr, double* matrix );

/* -------------------------------------------------------------------------
 * Specifies a 4x4 matrix transforming the Intermediate
 *              Coordinate System into the Data Coordinate system.
 *
 * Parameters:  ptr:    Pointer to the file structure.
 *              matrix: Vector containing the 16 matrix elements.
 *                      The elements are specified from left to
 *                      right and from top to bottom:
 *
 *                      m1  m2  m3  m4
 *                      m5  m6  m7  m8
 *                      m9  m10 m11 m12
 *                      m13 m14 m15 m16
 *
 *                      The matrix premultiplies the points
 *                      to be transformed.
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_header_matrix_ICS_to_DCS( void* ptr, double* matrix );

/* -------------------------------------------------------------------------
 * Specifies a 4x4 matrix transforming vector (vx,vy,vz),
 *              defined in the DCS, into vector (0,0,1), defined in the ICS.
 *
 * Parameters:  ptr:        Pointer to the file structure.
 *              vx,vy,vz:   Vector orthogonal to the parameterization plane,
 *                          defined in the Data Coordinate System. This
 *                          vector is the z axis of the Intermediate
 *                          Coordinate System.
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL void pif_header_matrix_DCS_z_axis(
    void*  ptr,
    double vx,
    double vy,
    double vz );




/* *************************************************************************
   pif_3D_data_interpolated:    Specifies an interpolated 3-D image.

   pif_3D_data_raw:             Specifies a raw 3-D image in the form of an
                                array of (x,y,z) coordinates.

   pif_3D_data_polygonal:       Specifies a raw 3-D image in the form
                                of an external polygonal file.
************************************************************************* */

/* -------------------------------------------------------------------------
 * Specifies an interpolated 3-D image.
 *
 * Parameters:  ptr:            Pointer to the file structure.
 *              param_flag:     Flag indicating the type of parameterization.
 *                              Can be PIF_PLANAR or PIF_CYLINDRICAL.
 *              invalid_point:  An array element having this value
 *                              is not a valid data point.
 *              array_width:    Width of the 2-D array.
 *              array_height:   Height of the 2-D array.
 *              i_scale:        Scaling factor for the i coordinate.
 *              j_scale:        Scaling factor for the j coordinate.
 *              surface_data:   A 2-D array of single-precision floating
 *                              point numbers containing the interpolated
 *                              3-D image. The array elements are written
 *                              from left to right and from bottom to top.
 *
 * Returns:     PIF_NO_ERROR or,
 *              PIF_INVALID_FLAG if the param_flag is not valid.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL int pif_3D_data_interpolated(
    void*  ptr,
    long   param_flag,
    double invalid_point,
    long   array_width,
    long   array_height,
    double i_scale,
    double j_scale,
    float* surface_data );

/* -------------------------------------------------------------------------
 * Specifies a raw 3-D image in the form of an array of (x,y,z)
 *              coordinates.
 *
 * Parameters:  ptr:            Pointer to the file structure.
 *              param_flag:     Flag indicating the type of parameterization.
 *                              Can be PIF_PLANAR or PIF_CYLINDRICAL.
 *              invalid_point:  A point whose z coordinate has this value
 *                              is not a valid data point.
 *              array_width:    Width of the 2-D array.
 *              array_height:   Height of the 2-D array.
 *              surface_data:   A 2-D array of (x,y,z) coordinates
 *                              containing the raw 3-D image. Each
 *                              array element consists of three single-
 *                              precision floating point numbers. The array
 *                              elements are written from left to right and
 *                              from bottom to top.
 *
 * Returns:     PIF_NO_ERROR or,
 *              PIF_INVALID_FLAG if the param_flag is not valid.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL int pif_3D_data_raw(
    void*  ptr,
    long   param_flag,
    double invalid_point,
    long   array_width,
    long   array_height,
    float* surface_data );

/* -------------------------------------------------------------------------
 * Specifies a raw 3-D image in the form of an external
 *              polygonal file.
 *
 * Parameters:  ptr:            Pointer to the file structure.
 *              param_flag:     Flag indicating the type of parameterization.
 *                              Can be PIF_PLANAR or PIF_CYLINDRICAL.
 *              filename:       String that specifies the path of an external
 *                              polygonal file. Its length should not exceed
 *                              511 bytes.
 *              file_format:    String that specifies the polygonal file
 *                              format. Its length should not exceed
 *                              511 bytes.
 *
 * Returns:     PIF_NO_ERROR or,
 *              PIF_INVALID_FLAG if the param_flag is not valid or,
 *              PIF_INVALID_STRING if a string is longer than 511 bytes.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL int pif_3D_data_polygonal(
    void*       ptr,
    long        param_flag,
    const char* filename,
    const char* file_format );




/* *************************************************************************
   pif_color_data:  Specifies an array of color data for interpolated
                    or raw images.
************************************************************************* */

/* -------------------------------------------------------------------------
 * Specifies an array of color data for interpolated or raw
 *              images.
 *
 * Parameters:  ptr:        Pointer to the file structure.
 *              color_flag: A flag specifying the type of color
 *                          information. Its value can be
 *                          PIF_GREY_LEVEL,PIF_RGB_COLORS or PIF_RGBA_COLORS.
 *              color_data: A 2-D array of color components corresponding
 *                          to the surface data array. If grey levels are
 *                          specified, one byte specifies the grey level of
 *                          each data point. If RGB colors are specified,
 *                          three bytes specifie the R,G and B components
 *                          of each data point. If RGBA colors are specified,
 *                          four bytes specify the R,G,B and A components
 *                          of each data point.
 *
 * Returns:     PIF_NO_ERROR or,
 *              PIF_INVALID_FLAG if the color_flag is not valid
 *              or the data is contained in a polygonal file.
 * ------------------------------------------------------------------------- */
IMTOOLS_DLL int pif_color_data(
    void*          ptr,
    long           color_flag,
    unsigned char* color_data );


#ifdef __cplusplus
}
#endif
