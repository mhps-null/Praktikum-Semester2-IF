#include <stdio.h>
#include <string.h>

int isLeapYear(int year)
{
  if (((year%4==0) && (year%100!=0))||(year%400==0)){
    return 1;
  }else{return 0;}
}

int getDaysInMonth(int month, int year)
{
    int kabisat=isLeapYear(year);     
    if (month == 2){
        if(kabisat == 0){
            return 28;

        }else{return 29;}
    }else if ((month == 4) || (month == 6) || (month == 9) ||( month == 11)){
        return 30;
    }else{
        return 31;
    }
}
int isValidDate(int day, int month, int year){
    int days = getDaysInMonth(month, year);
    if (day >= 1 && day <= days && month >= 1 && month <= 12 && year >= 0){
        return 1;
    }else{return 0;}
}

const char* getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    
    const char* days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    return days[h];
}

const char* getZodiac(int day, int month) {
    const char* zodiacSigns[] = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"
    };
    int zodiacStartDays[] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22, 20};

    if (day < zodiacStartDays[month - 1]) return zodiacSigns[month - 1];
    return zodiacSigns[month];
}


long long daysFromBeginning(int day, int month, int year) {
    long long total=0;

    for(int i = 1; i < month; i++){
    
            total += getDaysInMonth(i, year);
        
    }
    total+=day;
    for (int j = 1; j < year; j++){
        if (isLeapYear(j) == 1){
            total += 366;

        }else{total += 365;}
    }return total;
}

long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    int selisih = 0;
    
    selisih = -daysFromBeginning(d1,m1,y1)+daysFromBeginning(d2,m2,y2);
    return selisih;
}

const char* getPasaran(int day, int month, int year) {
    const char* pasaran[] = {"Legi", "Pahing", "Pon","Wage", "Kliwon"};
    long long jhari;
    jhari=daysFromBeginning(day,month,year);
    return pasaran[jhari%5];
}

int main(){
    int day,month;int year;char menu[20];
    scanf("%s",&menu);
    while (strcmp(menu,"SELESAI")!=0){
        if (strcmp(menu,"VALIDASI")==0){
            scanf("%d %d %d",&day,&month,&year);
            if (isValidDate(day,month,year)==0){
                printf("TIDAK\n");
            }else{printf("YA\n");}
        }
        else if (strcmp(menu,"HARI")==0){
            scanf("%d %d %d",&day,&month,&year);
            printf("%s\n",getDayOfWeek(day, month, year));
        }
        else if (strcmp(menu,"ZODIAK")==0){
            scanf("%d %d",&day,&month);
            printf("%s\n",getZodiac(day,month));
        }
        else if (strcmp(menu,"SELISIH")==0){
            scanf("%d %d %d",&day,&month,&year);
            int day2,month2;int year2;
            scanf("%d %d %d",&day2,&month2,&year2);
            printf("%lld\n",dateDifference( day,  month,  year,  day2,  month2,  year2));
        }
        else if (strcmp(menu,"PASARAN")==0){
            scanf("%d %d %d",&day,&month,&year);
            printf("%s\n",getPasaran( day,  month,  year));
        }
        scanf("%s", menu);
    }

    return 0;
}