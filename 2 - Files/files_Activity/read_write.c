#include <stdio.h>

typedef struct {
	char *id;
	char name[10];
	int age;
	float atk;
} ADV;

void printADV (ADV A);

void main () {
	FILE *fp ;
	int numWritten;
	
	ADV a1[] = {
	"0X1", "Alex", 10, 14.6,
	"F22", "Samu", 35, 1000,
	"ADC", "Neneve", 19, 200
	}, a2;
	
	if( (fp = fopen( "char_data.bin", "wb" )) != NULL ) {
	
		numWritten = fwrite( &a1[0], sizeof( ADV ), 1 , fp );
		numWritten = fwrite( &a1[1], sizeof( ADV ), 1 , fp );
		numWritten = fwrite( &a1[2], sizeof( ADV ), 1 , fp );
		
	fclose( fp );
	
	} 
	else {		
		printf( "Problem opening the file\n" );
	}
	
	if( (fp = fopen( "char_data.bin", "rb" )) != NULL ) {
		
		numWritten = fread( &a2, sizeof( ADV ), 1 , fp );
		printADV(a2);
		numWritten = fread( &a2, sizeof( ADV ), 1 , fp );
		printADV(a2);
		fseek(fp, (unsigned) - sizeof(ADV) * -1L, 3);
		numWritten = fread( &a2, sizeof( ADV ), 1 , fp );
		printADV(a2);
		
		printf("\nValue of EOF: %d", EOF);
		fclose( fp );
	
	} 
	else {
		printf( "Problem opening the file\n" );
	}
}

void printADV (ADV A) {
	printf("%-10s", A.id);
	printf("%-10s", A.name);
	printf("%-10d", A.age);
	printf("%-10f\n", A.atk);
}
