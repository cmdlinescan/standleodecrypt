// decrypter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(int argc, char **argv)
{
    FILE* file = fopen( argv[ 1 ], "rb" );
    if ( !file ) {
        printf( "failed to open file!\n" );
        return 0;
    }
    fseek( file, 0, SEEK_END );
    long file_size = ftell( file );
    rewind( file );
    char* metadata_buffer = ( char* )malloc( file_size * sizeof( char ) );
    if ( !metadata_buffer ) {
        printf( "failed to allocate memory!\n" );
        return 0;
    }

    fread( metadata_buffer, 1, file_size, file );
    fclose( file );

    char key[ 169 ];
    strcpy( key, "don't reverse me please <3\\na moy mal4ik na turbovom marke\\npo avtostrade vdol' no4nix stolbov\\nmi krujilish' bokom po razvyazke\\nsojgi devyatku i vse budet ok" );
    for ( long i = 0; i < file_size; ++i )
    {
        for ( int k = 0; k <= 158; ++k ) {
            metadata_buffer[ i ] ^= key[ k ];
        }
    }

    FILE* output_file = fopen( argv[ 2 ], "wb" );
    fwrite( metadata_buffer, 1, file_size, output_file );
    fclose( output_file );

    printf( "work finished\n" );
    return 0;
}