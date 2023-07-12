#ifndef INPUTS_H_
#define INPUTS_H_

/*
typedef struct
{
	int id;
	char nombre[32];

}structura;
*/

int esNumerica(char numero[]);
int esFlotante(char numero[]);

int input_GetInt(char mensaje[]);
float input_GetFloat(char mensaje[]);
char input_GetChar(char mensaje[]);
void input_GetString(char mensaje[],char string[]);
void input_GetNombre(char string[]);

void stringtoupper(char string[]);
void stringtolower(char string[]);

#endif /* INPUTS_H_ */
