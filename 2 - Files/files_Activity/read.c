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
	ADV a1 = {"0X1", "Alex", 10, 14.6}, a2;
	if( (fp = fopen( "char_data.bin", "rb" )) != NULL ) {
	numWritten = fread( &a2, sizeof( ADV ), 1 , fp );
	fclose( fp );

	} else {
	
	printf( "Problem opening the file\n" );
	
	}
	printf("id: %s\n", a2.id);
	printf("name: %s\n", a2.name);
	printf("age: %d\n", a2.age);
	printf("atk: %.2f\n", a2.atk);

}
