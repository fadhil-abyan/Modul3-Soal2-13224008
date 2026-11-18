#include <stdio.h>

int fpb(int a, int b){
    if(b == 0){
        return a;
    }
    return fpb(b, a % b);
}

int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int pour(int kapasitas1, int kapasitas2, int d){
    int isi1 = kapasitas1; 
    int isi2 = 0;

    int step = 1;
    while(isi1 != d && isi2 != d){
        int temp = min(isi1, kapasitas2 - isi2);

        isi2 = isi2 + temp;
        isi1 = isi1 - temp;

        step++;

        if(isi1 == d || isi2 == d){
            break;
        }

        if(isi1 == 0){
            isi1= kapasitas1;
            step++;
        }

        if(isi2 == kapasitas2){
            isi2 = 0;
            step++;
        }
    }
    return step;
}


int minSteps(int m, int n, int d){
    // berlaku apabila m < n
    if(d > n){
        return -1;
    }

    if(d % fpb(m, n) != 0){
        return -1;
    }

    return min(pour(m, n, d), pour(n, m, d));
}

int main(){
    int ukuran1;
    int ukuran2;
    int takaran;
    int langkahMin;

    scanf("%d %d %d", &ukuran1, &ukuran2, &takaran);

    if(ukuran1 < ukuran2){
        langkahMin = minSteps(ukuran1, ukuran2, takaran);
    }
    else{
        langkahMin = minSteps(ukuran2, ukuran1, takaran);
    }

    printf("%d\n", langkahMin);

    return 0;
}
