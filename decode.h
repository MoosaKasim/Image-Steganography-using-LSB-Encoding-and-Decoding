#ifndef DECODE_H
#define DECODE_H

#include "types.h"  //contains user defined types

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

/*
 * Structure to store information required for
 * decoding stego image to new file
 * Info about output and intermediate data is
 * also stored
 */

typedef struct _DecodeInfo
{
	/* Encoded Stego Image info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    char image_data[MAX_IMAGE_BUF_SIZE];
    char *magic_data;

	/* Decoded output file info */
    char *decode_extn_secret_file;
    int secret_file_size;
    char *secret_fname;
    FILE *fptr_secret;

    FILE *fptr_dest_image;

} DecodeInfo;

/* Decoding function prototypes */

/* Read and validate decode args from argv */
Status read_and_validate_decode_args(int argc, char **argv, DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding ( DecodeInfo *decInfo );

/* Get file pointers for i/p and o/p files */
Status decode_open_files ( DecodeInfo *decInfo );

/* Get the magic string */
Status decode_magic_string ( DecodeInfo *decInfo );

/* Decode data from image */
Status decode_data_from_image (int size, FILE *fptr_stego_image, DecodeInfo *decInfo);

/* Decode byte from LSB */
Status decode_byte_from_lsb ( char *data, char *image_buffer );

/* Decode file extn size */
Status decode_file_extn_size ( int size, FILE *fptr_stego_image );

/* Decode size from LSB */
Status decode_size_from_lsb ( char *buffer, int *size );

/* Decode secret file extn */
Status decode_secret_file_extn ( char *file_ext, DecodeInfo *decInfo );

/* Decode extn data from image */
Status decode_extn_data_from_image ( int size, FILE *fptr_stego_image, DecodeInfo *decInfo );

/* Decode secret file size */
Status decode_secret_file_size ( int file_size, DecodeInfo *decInfo );

/* Decode secret file data */
Status decode_secret_file_data ( DecodeInfo *decInfo );

#endif
