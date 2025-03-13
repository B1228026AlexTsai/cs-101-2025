#include <stdio.h>
#include <string.h>

typedef struct employee{
    int id;
    char name[12];
    int age;
    float salary;
}employee_t;

void emp_info(employee_t emp){
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %02f\n\n", emp.salary);
    
}

int emp_aveage_age(employee_t emp[], int n){
    int sum = 0;
    for (int i=0;i<3;i++) {
        sum+=emp[i].age;
    }
    return sum/3;
}

void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb+");
    for (int i=0;i<n;i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    fclose(fp);
    return;
}

void emp_readfile(employee_t emp[]) {
    FILE* fp = fopen("employee.bin", "rb+");
    int i = 0;
    while (fread(&emp[i],sizeof(employee_t), 1, fp)) {
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }
    fclose(fp);
    return;
}

int main()
{
    employee_t emp[3];
    e[0].id = 1;
    e[0].age = 20;
    strcpy(e[0].name,"IU");
    e[0].salary = 30000.0;
    
    e[1].id = 2;
    e[1].age = 26;
    strcpy(e[1].name,"taylor");
    e[1].salary = 36000.0;
    
    e[2].id = 3;
    e[2].age = 31;
    strcpy(e[2].name,"swift");
    e[2].salary = 90000.0;
    
    emp_writefile(emp, 3);
    employee_t readread_emp[10];
    emp_readfile(read_emp);
    
    for (int i=0;i<3;i++) {
        emp_info(read_emp[i]);
    }
    
    return 0;
}
