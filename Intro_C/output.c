#include "my_header.h"
void  my_print(STUDENT *data)
{
	printf("FIRSTNAME\tLASTNAME\tSTUDENTID\tGPA\n");
	printf("%s\t%s\t%d\t%f\n",data->firstname,data->lastname,data->studentid,data->gpa);
}
