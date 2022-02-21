#include <stdio.h>
int average(FILE *f, int size);
void swap(FILE *f, int size);
void input(FILE *f,int k);
void output(FILE *f, int k);

int main() {
    setbuf(stdout, 0);
    FILE *f;
    do {
        printf("chose filename\n");
        char name[100];
        scanf_s("%s",name);
        f= fopen(name,"w+");
    } while (f==NULL);
    int count=0;
    do {
        printf("input number of digits\n");
        scanf_s("%d",&count);
    } while ((count<=0)||(count>1000));
    printf("enter data sequentially\n");
    input(f,count);

    for (;;) {
        int ch;
        printf("Menu:\n1)average\n2)swap\n3)show data\n4)exit\n");
        scanf_s("%d",&ch);

        switch (ch) {
            case 1:
                printf("Average:\t%d\n", average(f,count));
                break;
            case 2:
                swap(f,count);
                break;
            case 3:
                output(f,count);
                break;
            case 4:
                return 0;
            default:
                printf("incorrect input\n");
        }
    }
}
void input(FILE *f, int k) {
    for (int i = 0; i < k; ++i) {
        int num;
        scanf_s("%d",&num);
        fprintf(f,"%d\n",num);
    }
}

void output(FILE *f, int k) {
    fseek(f,0,0);
    printf("Data:\n");
    for (int i = 0; i < k; ++i) {
        int buf;
        fscanf_s(f,"%d",&buf);
        printf("%d\n",buf);
    }
}

int average(FILE *f, int size) {
    fseek(f, 0,0);
    int sum=0;
    for (int i = 0; i < size; ++i) {
        int buf;
        fscanf_s(f,"%d",&buf);
        sum+=buf;
    }
    return (sum/size);
}

void swap(FILE *f, int size) {
    int buf,buf2;
    fseek(f, 0,0);
    fscanf_s(f,"%d",&buf);
    fseek(f, (long)(-sizeof(int)),2);
    fscanf_s(f,"%d",&buf2);
    fseek(f, (long)(-sizeof(int)),2);
    fprintf(f,"%d\n",buf);
    fseek(f, 0,0);
    fprintf(f,"%d\n",buf2);
}
