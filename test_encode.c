/*

Name		:	MK MOOSA KASIM
Date		:	13-03-2022
Description	:	Technique of hiding secret data within an image or an set of file., Here the program was on to encode secret file data to source image file by creating new image file with option '-e' and decode data from new image file to new text file

Input		:	For Encoding
			./a.out -e beautiful.bmp secret.txt stego.bmp
			
			For Decoding

			./a.out -d stego.bmp decode.txt



Output		:	For Encoding
			./a.out -e beautiful.bmp secret.txt stego.bmp
			
			Selected encoding
			Read and validate encode arguments is success
			........Started Encoding..........
			Open files is a success
			width = 1024
			height = 768
			Check capacity is a success
			Copied bmp header successfully
			Encoded magic string successfully
			Encoded the extn size
			encoded secret file extn
			Encoded secret file size
			Encoded secret file data
			copied remaining data
			.....Completed Encoding.....
	
				*********

			For Decoding

			./a.out -d stego.bmp decode.txt
			Selected Decoding
			Read and validate decode arguments is success
			...........Started Decoding..........
			 Opening files function is success
			 Decoding magic string is success
			 Decoding file extension size is success
 			 Decoding secret file extension successful
 			 Decoding secret file size is success
 			 Decoding secret file data is success
			 .....Completed Decoding.....


*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

int main(int argc, char **argv)
{
	if (check_operation_type(argv) == e_encode)
	{
		printf("Selected encoding\n");
		EncodeInfo encInfo;
		if (read_and_validate_encode_args(argv, &encInfo) == e_success)
		{
			printf("Read and validate encode arguments is success\n");
            printf("........Started Encoding..........\n");
			if (do_encoding(&encInfo) == e_success)
			{
				printf(".....Completed Encoding.....\n");
			}
			else
			{
				printf(".....Encoding Failed.....\n");
				return -1;
			}
		}
		else
		{
			printf("Read and validate encode arguments is failure\n");
			return -1;
		}
	}
	else if (check_operation_type(argv) == e_decode)
	{
		printf("Selected Decoding\n");
        DecodeInfo *decInfo;
        if (read_and_validate_decode_args(argc, argv, &decInfo) == e_success)
        {
            printf("Read and validate decode arguments is success\n");
            printf("...........Started Decoding..........\n");
            if (do_decoding(&decInfo) == e_success)
            {
                printf(".....Completed Decoding.....\n");
            }
            else
            {
                printf(".....Decoding Failed.....\n");
                return -1;
            }
        }
        else
        {
            printf("Read and validate decode arguments is failure\n");
            return -1;
        }
	}
	else
	{
		printf("Invalid option\nFor encoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nFor decoding: ./a.out -d stego.bmp decode.txt\n");
	}
	return 0;
}

OperationType check_operation_type(char *argv[])
{
	if (strcmp(argv[1], "-e") == 0)
		return e_encode;
	else if (strcmp(argv[1], "-d") == 0)
		return e_decode;
	else
		return e_unsupported;
}
