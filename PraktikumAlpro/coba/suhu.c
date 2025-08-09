#include <stdio.h>
#include <math.h>
double CelciusToFahrenheit(double c){
    return (c * (9.0/5.0))+32;
}

double CelciusToKelvin(double c){
    return c + 273.15;
}

double FahrenheitToCelcius(double f){
    return (f - 32)*(5.0/9.0);
}

double FahrenheitToKelvin(double f){
    return (f - 32)*(5.0/9.0) + 273.15;
}

double KelvinToCelcius(double k){
    return k - 273.15;
}

double KelvinToFahrenheit(double k){
    return (k - 273.15) * (9.0/5.0) + 32;
}

double Konversi(double x, char a, char b){
    if(a=='C' && b=='F'){
        return CelciusToFahrenheit(x);
    }
    else if(a=='C' && b=='K'){
        return CelciusToKelvin(x);
    }
    else if(a=='F' && b=='C'){
        return FahrenheitToCelcius(x);
    }
    else if(a=='F' && b=='K'){
        return FahrenheitToKelvin(x);
    }
    else if(a=='K' && b=='C'){
        return KelvinToCelcius(x);
    }
    else if(a=='K' && b=='F'){
        return KelvinToFahrenheit(x);
    }
    else{
        return x;
    }
}

int main(){
    int N, i;
    scanf("%d", &N);
    double x[N];
    char a[N], b[N];
    for(i=0; i< N; i++){
        scanf("%lf %c %c", &x[i], &a[i], &b[i]);
        //printf("%lf %c %c\n", x[i], a[i], b[i]);
    }
    for(i=0; i<N; i++){
        printf("%.2lf\n", floor(Konversi(x[i],a[i],b[i])));
    }
    return 0;
}