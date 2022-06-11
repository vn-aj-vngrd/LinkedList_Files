#include <stdio.h>
#pragma pack(1)

typedef struct {
	char *id;
	char name[10];
	int age;
	float atk;
} ADV;

int main( void ) {
	FILE *fp;
	int numWritten;
	ADV a1 = {"0X1", "Alex", 10, 14.6};
	fp = fopen( "char_data.bin", "wb" );
	numWritten = fwrite( &a1, sizeof( ADV ), 1 , fp );
	fclose( fp );
}
