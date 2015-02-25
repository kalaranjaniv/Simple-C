#include<stdio.h>
#include<string.h>
typedef struct {
	char firstname[30];
	char lastname[30];
	int studentid;
	float gpa;
} STUDENT;
void  my_print(STUDENT data);
int main() {
	STUDENT first, second;
	char firstname[30];
	char lastname[30];
	int studentid;
	float sum = 0;
	float count = 0;
	float gpa;
	float avg;
	char reststring[100];
	FILE *fin;
	if ((fin = fopen("/home/grad1/kvijayak/assignment1/P1-DATA", "r"))== NULL) {
		printf("cannot open file");
		exit(1);
	}
	while (1) {
		if (!feof(fin)) {
			char indicator = fgetc(fin);
			fgets(reststring,200,fin);
			sscanf(reststring, "%s%s%d%f",firstname,lastname,&studentid,&gpa);
		//	printf("%s%s%d%f",firstname,lastname,studentid,gpa);
			sum = sum + gpa;
			count++;
		}
		else
		{
			break;
		}
	}
	fclose(fin);

	avg = sum / count;
//	printf("%f\t%f\n",sum,avg);
	if ((fin =fopen("/home/grad1/kvijayak/assignment1/P1-DATA", "r"))== NULL) {
		printf("cannot open file");
		exit(1);
	}
	while (1) {
		if (!feof(fin)) {
			char indicator = fgetc(fin);
			if (indicator != '#') {
				fgets(reststring,200,fin);
				sscanf(reststring, "%s%s%d%f",firstname,lastname,&studentid,&gpa);
			//	printf("%s\t%s\t%d\t%f\n",firstname,lastname,studentid,gpa);
				if (gpa - avg > 0.5) {
					if (first.gpa == NULL) {
						strcpy(first.firstname, firstname);
						strcpy(first.lastname,lastname);
						first.studentid = studentid;
						first.gpa = gpa;
					} else {
						if (first.gpa < gpa) {
							second = first;
							strcpy(first.firstname, firstname);
							strcpy(first.lastname,lastname);
							first.studentid = studentid;
							first.gpa = gpa;
						} else {
							strcpy(second.firstname, firstname);
							strcpy(second.lastname,lastname);
							second.studentid = studentid;
							second.gpa = gpa;
						}
					}

				}
			}
			else
			{
				fgets(reststring,200,fin);
			}
		}
		else
		{
			break;
		}
	}
	fclose(fin);
	my_print(first);
	my_print(second);
}

void  my_print(STUDENT data)
{
	printf("FIRSTNAME\tLASTNAME\tSTUDENTID\tGPA\n");
	printf("%s\t%s\t%d\t%f\n",data.firstname,data.lastname,data.studentid,data.gpa);
}
