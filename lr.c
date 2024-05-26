#include"lr.h"
#include <stdio.h>
#define YES 1
#define NO 0
unsigned int zam(unsigned int n) {
        return ((n & 0x0F0F0F0F) << 4) | ((n & 0xF0F0F0F0) >> 4);
    }
    void zamena(int arr[10][10], int N, int strok, int stolb) {
    int max = arr[strok][stolb];
    for (int j = 0; j < N; j++) {
        int temp = arr[strok][j];
        arr[strok][j] = arr[j][stolb];
        arr[j][stolb] = temp;
        }
    }
    void proc() {
    float h, t, g, v, v0;
    printf("h = ");
    scanf("%f", &h);
    printf("t = ");
    scanf("%f", &t);
    printf("g = ");
    scanf("%f", &g);
    v0 = sqrt((g*(t*t))/2*h);
    printf("v0 = %f\n", v0);}
    float sumposl(int x, int N, int i, int n, float s) {
    if (i == N+1 || n <= 0.000001)
    {
        return s;
    }
    float a = (float)i / n;
    s = s + a;
    n = n * x;
    i = i + 1;

    return sumposl(x, N, i, n, s);
    }
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int lab1() {
    float h, t, g, v, v0;
    printf("h = ");
    scanf("%f", &h);
    printf("t = ");
    scanf("%f", &t);
    printf("g = ");
    scanf("%f", &g);
    v0 = sqrt((g*(t*t))/2*h);
    printf("v0 = %f\n", v0);
    return 0;
}
int lab12() {
        proc();
        return 0;
}

int lab2() {
    int x, N, n;
    float s, a, i;
    printf ("x = ");
    scanf("%d", &x);
    printf ("N = ");
    scanf("%d", &N);
    s = 0;
    i = 1;
    n = x;
    while (i <= N){
    a = i/n;
    s = s + a;
    n = n * x;
    i = i + 1;}
        printf("s = %f\n", s);
        return 0;
}
int lab22() {
    int x, N, n;
    printf("x = ");
    scanf("%d", &x);
    printf("N = ");
    scanf("%d", &N);
    n = x;
    float result = sumposl(x, N, 1, n, 0);

    printf("s = %f\n", result);

    return 0;


}
int lab3() {
    int flag, count, buk;
    char c;
    count = 0;
    buk=0;
    flag = NO;
    while((c = getchar()) != EOF )
    {
        if (c=='.' || c==',' ||  c==' ' || c=='\n'){
            flag=NO;
            if(buk%2 != 0){
                count+=1;
            buk=0;}
        }else{
            if (flag==NO){
                flag==YES;
                buk+=1;
            }else{
                if (flag==YES){
                    buk+=1;
                }
            }
        }
    }
    printf("kolichestvo slov = %d\n", count);
    return 0;
}


int lab4() {
    int x, max, start;
    x = 0;
    max = 0;
    char str[100];
    printf("vvedite predlogenie:");
    fgets(str, 100, stdin);
    for(int i = 0; str[i] != 0; i ++){
        if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '\n'){
            x = x + 1;
        }
        else {
            if (x>max){
                max = x;
                start = i-(max + 1);
            }
            x = 0;
        }
    }

    for(int i = start; i < start + (max + 1); i++){
        str[i] = ' ';
    }

    printf("stroka posle ydalenia samogo dlinnogo slova:\n");
    printf("%s", str);

    return 0;
}
int lab42() {
    int x, max, min, startmax, startmin;
    x = 0;
    max = 0;
    min = 1000;
    char str[100];
    printf("vvedite predlogenie:");
    fgets(str, 100, stdin);

    for(int i = 0; str[i] != 0; i ++){
        if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '\n'){
            x = x + 1;
        } else {
            if (x > max){
                max = x;
                startmax = i - max;
            }
            if (x < min){
                min = x;
                startmin = i - min;
            }
            x = 0;
        }
    }

    for(int i = startmax; str[i] != '\0'; i++){
        str[i] = str[i + (max + 1)];
    }

    for(int i = startmin; str[i] != '\0'; i++){
        str[i] = str[i + (min + 1)];
    }
    printf("stroka posle ydalenia samogo dlinnogo i samogo korotkogo slova:\n");
    printf("%s", str);
    return 0;

}
int lab5() {
        int n[10];
        int ps = 0;
        int ns = 0;
        printf("vvedite 10 chisel:\n");
        for(int i = 0; i < 10; i++) {
            scanf("%d", &n[i]);
            if(n[i] > 0) {
                ps++;
            } else if(n[i] < 0) {
                ns++;
            }
        }
        if(ps > ns) {
            for(int i = 0; i < 10; i++) {
               if (n[i] < 0) {
                    n[i] = 0;
                }
            }
        } else {
            for(int i = 0; i < 10; i++) {
                if(n[i] > 0) {
                    n[i] = 0;
                }
            }
        }
        printf("rezyltat:\n");
        for(int i = 0; i < 10; i++) {
            printf("%d ", n[i]); }
        return 0;}



int lab52() {
    int n[10];
    int ps = 0;
    int ns = 0;
    int progress = 1;
    printf("vvedite 10 chisel:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &n[i]);}
    for(int i = 0; i < 9; i++) {
        if(zam(n[i+1]) - zam(n[i]) != zam(n[1]) - zam(n[0])) {
            progress = 0;
            break;
        }
    }
    if(progress) {
        for(int i = 0; i < 10; i++) {
            if(n[i] > 0) {
                ps++;
            } else if(n[i] < 0) {
                ns++;
            }
        }
        if(ps > ns) {
            for(int i = 0; i < 10; i++) {
                if(n[i] < 0) {
                    n[i] = 0;
                }
            }
        } else {
            for(int i = 0; i < 10; i++) {
                if(n[i] > 0) {
                    n[i] = 0;
                }
            }
        }
    }
    printf("rezyltat:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", n[i]);
    }
    return 0;}

int lab6() {
    int N;
    printf("vvedite razmer massiva N: ");
    scanf("%d", &N);
    int arr[10][10];
    printf("vvedite elements massiva:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int strok = 0, stolb = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > arr[strok][stolb]) {
                strok = i;
                stolb = j;
            }
        }
    }
    zamena(arr, N, strok, stolb);
    printf("izmenenn massiv:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int lab62() {
    int rows, cols;
    printf("vvedite kolvo strok i stolbov: ");
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    printf("vvedite massiv:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        insertionSort(arr[i], cols);
    }
    printf("izmenenn massiv:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int lab7() {
        unsigned int N;
        printf("vvedite chislo N: ");
        scanf("%u", &N);
        unsigned int r = zam(N);
        printf("resyltat: %u\n", r);
        return 0;

}


