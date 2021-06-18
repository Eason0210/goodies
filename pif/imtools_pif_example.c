/* --------------------------------------------------------------------------
 *	Date: April 16, 1998					 
 *									 
 *									 
 *	Copyright (c) 1995-1998, InnovMetric Software Inc.			 	
 *									 
 *	ALL RIGHTS RESERVED. Permission to use, copy, modify,		 
 *	and distribute this software for any purpose and		 
 *	without fee is hereby granted.					 
 *									 
 *	IN NO EVENT WILL INNOVMETRIC SOFTWARE INC. BE LIABLE		 
 *	FOR (1) SPECIAL, INDIRECT, INCIDENTAL OR CONSEQUENTIAL		 
 *	DAMAGES, OR (2) ANY DAMAGES RESULTING FROM LOSS OF USE,		 
 *	OR LOSS OF DATA, OR LOSS OF PROFITS ARISING OUT OF OR		 
 *	IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE	 
 *	OR ANY INFORMATION PROVIDED HEREUNDER, WHETHER IN AN 		 
 *	ACTION BASED ON CONTRACT OR TORT, INCLUDING NEGLIGENCE.		 
 * ------------------------------------------------------------------------- */
 
/* --------------------------------------------------------------------------
	WARNING - WARNING - WARNING - WARNING - WARNING 

	It is assumed in this PIF programming library that
	the data type "long" represents a 32-bit integer
	number.     
 * ------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * imtools_pif_example.c
 *
 * This file shows how to use the PIF library (imtools.dll, imtools.lib,
 * imtools_pif.h) in order to generate 3-D image files in the PIF format.
 *
 * Version 2.0
 * ------------------------------------------------------------------------- */
 
   
/* -------------------------------------------------------------------------
 * INCLUDE FILES AND DEFINITIONS
 * ------------------------------------------------------------------------- */   
#include "imtools_pif.h"


/* -------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 * ------------------------------------------------------------------------- */
void	create_interpolated_PIF_file(void);
void	create_raw_PIF_file(void);
void	create_polygonal_PIF_file(void);



void main(int argc, char **argv)
{
	create_interpolated_PIF_file();
	create_raw_PIF_file();
	create_polygonal_PIF_file();
}



/* -------------------------------------------------------------------------
 * Creates an interpolated PIF file.
 *
 * Parameters:  None
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
void 	create_interpolated_PIF_file(void)
{
	int 	c1,c2;
	void *	pif_file;
	float 	mat_z[24];
	unsigned char 	mat_RGB[72];


	/* --- Two 6x4 array of z and RGB values are created. --- */
	for (c1=0; c1< 4; c1++)
    {
		for (c2=0; c2< 6; c2++)
		{
			mat_z[c1*6+c2]= (float)(1.0+(float)(c1)*0.2);
  			mat_RGB[3*(c1*6+c2)]=   128;
  			mat_RGB[3*(c1*6+c2)+1]= 255-c1*40; 
  			mat_RGB[3*(c1*6+c2)+2]= 0+c1*40;    
  		}
    }
 
	/* --- First, the creator of the PIF file must allocate space for the 
	       file structure. Routine "pif_file_allocate" returns a pointer 
		   to the allocated space, or a NULL pointer when the malloc has 
		   failed. --- */
	pif_file= pif_file_allocate();


	/* --- Second, the user specifies the header and data blocks in the 
		   PIF file. --- */
	pif_header_comments(pif_file,"This is an interpolated PIF file");
	pif_3D_data_interpolated(pif_file,PIF_PLANAR,-100.0,6,4,0.5,0.5,mat_z);


	/* --- Third, the user may optionally specify a color data block. --- */
	pif_color_data(pif_file,PIF_RGB_COLORS,mat_RGB);


	/* --- Fourth, the user writes the file. --- */
	pif_file_write(pif_file,"interpolated.pf");


	/* --- Fifth, the user frees the space allocated for the file structure. --- */
	pif_file_free(pif_file);

}


/* -------------------------------------------------------------------------
 * Creates a raw PIF file.
 *
 * Parameters:  None
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
void	create_raw_PIF_file(void)
{
	int 	c1,c2;
	void *	pif_file;
	float 	mat_xyz[72];


	/* --- A 6x4 array of (x,y,z) values is created. --- */
	for (c1=0; c1< 4; c1++)
	{
		for (c2=0; c2< 6; c2++)
  		{
  			mat_xyz[3*(c1*6+c2)]=   (float)(1.01*(float)c2);  
  			mat_xyz[3*(c1*6+c2)+1]= (float)(0.99*(float)c1);  
  			mat_xyz[3*(c1*6+c2)+2]= (float)(1.0+(float)(c1)*0.2);
  		}
    }
 

	/* --- First, the creator of the PIF file must allocate space for the 
		   file structure. Routine "pif_file_allocate" returns a pointer 
		   to the allocated space, or a NULL pointer when the malloc has 
		   failed. --- */
	pif_file= pif_file_allocate();


	/* --- Second, the user specifies the header and data blocks in the 
		   PIF file. --- */ 
	pif_header_comments(pif_file,"This is a raw PIF file");
	pif_header_optional_scaling(pif_file,1.0,1.0);
	pif_3D_data_raw(pif_file,PIF_PLANAR,-100.0,6,4,mat_xyz);


	/* --- Third, the user may optionally specify a color data block.
		   In this example, no color information is specified. --- */


	/* --- Fourth, the user writes the file. --- */
	pif_file_write(pif_file,"raw.pf");


	/* --- Fifth, the user frees the space allocated for the file structure. --- */
	pif_file_free(pif_file);

}



/* -------------------------------------------------------------------------
 * Creates a polygonal PIF file.
 *
 * Parameters:  None
 *
 * Returns:     Nothing
 * ------------------------------------------------------------------------- */
void 	create_polygonal_PIF_file(void)
{
	void *	pif_file;


	/* --- First, the creator of the PIF file must allocate space for the 
		   file structure. Routine "pif_file_allocate" returns a pointer 
		   to the allocated space, or a NULL pointer when the malloc has 
		   failed. --- */
	pif_file= pif_file_allocate();


	/* --- Second, the user specifies the header and data blocks in the 
		   PIF file. --- */
	pif_header_comments(pif_file,"This is a polygonal PIF file");
	pif_3D_data_polygonal(pif_file,PIF_PLANAR,"polygonal.obj","obj");


	/* --- Third, the user writes the file. --- */
	pif_file_write(pif_file,"polygonal.pf");


	/* --- Fourth, the user frees the space allocated for the file structure. --- */
	pif_file_free(pif_file);

}
