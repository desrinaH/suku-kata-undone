//
//  main.c
//  Syllable
//
//  Created by Desrina Fithriyah Hasyim on 27/12/20.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, l, j;
    char sentence[999], t[999], map[999];
    scanf("%[^\n]", &sentence);
    //printf("%s", sentence);
    
    char vowel[10] = "aAeEiIoOuU";
    char consonant[42] = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
    l = strlen(sentence);
    //printf("ini l = %d", l);
    
    //mapping
    for(i = 0; i < l; i++){
        if(sentence[i] == 32){  //ascii 32 == space (character)
            map[i] = sentence[i];
            //printf("map[%d] = %c\n", i, map[i]);
        }
        else {
            for(j = 0; j < 10; j++){    // vowel = 10
                if (sentence[i] == vowel[j]){
                    map[i] = 'v';
                    //printf("map[%d] = %c\n", i, map[i]);
                }
            }
            if (map[i] != 'v') {
                map[i] = 'k';
                //printf("map[%d] = %c\n", i, map[i]);
            }
        }
    }
    
    
    for (i = 0; i < l; i++){
        switch (map[i]) {
            case 'v':
                printf("%c", sentence[i]); // outputkan huruf vokal
                if (map[i+1] == 'k'){ // jika ada huruf konsonan yang jumlahnya 1
                    if(map[i+2] == 'k'){ //jika ada huruf konsonan yang jumlahnya 2
                        if(map[i+3] == 'k'){ //jika ada huruf konsonan yang jumlahnya 3
                            if(map[i+4] == 'k'){ //jika ada huruf konsonan yang jumlahnya 4
                                printf("%c%c-%c%c", sentence[i+1], sentence[i+2],sentence[i+3], sentence[i+4]); //outputkan 2 konsonan terakhir e.g konstruksi
                                i = i+4; break;
                            }
                            printf("%c-", sentence[i+1]); //lanjutan konsonan jumlahnya 3
                            i = i + 1; break;
                        }
                        if (sentence[i+1] == 'n' || sentence[i+1] == 'N'){
                            if (sentence[i+2] == 'g' || sentence[i+2] == 'G' || sentence[i+2] == 'y' || sentence[i+2] == 'Y'){ // jika ada kombinasi ny atau ng (lanjutan konsonan 2)
                                if(sentence[i+3] == 0 || sentence[i+3] == 32){ //ascii 0 = end of line (character)
                                    printf("%c%c", sentence[i+1], sentence[i+2]); // outputkan ny atau ng
                                    i = i + 2; break;
                                }
                                else {
                                    printf("-%c%c", sentence[i+1], sentence[i+2]); // kalau ditengah kata
                                    i = i+2; break;
                                }
                            }
                            else {
                                printf("%c-", sentence[i+1]); //kalau bukan y atau g
                                i = i + 1; break;
                            }
                        }
                        else { //lanjutan 2 konsonan kalo i+2 bukan n
                            printf("%c-", sentence[i+1]);
                            i = i + 1; break;
                        }
                       
                    }
                    if (sentence[i+2] == 0 || sentence[i+2] == 32){ // kalo diakhir kata
                        printf("%c", sentence[i+1]); //outputkan 1 huruf konsonan itu(lanjutan konsonan 1)
                    }
                    else{
                        printf("-%c", sentence[i+1]); // kalo di tengah kata
                    }
                    i = i + 1; break;
                    
                }
                if (map[i+1] == 'v'){ //kalau huruf selanjutnya vokal
                    printf("-%c", sentence[i+1]);
                    i = i + 1; break;
                }
                else{
                    printf(" ");
                    i = i + 1; break;
                }
                break;
            case 'k':
                if(map[i+1] == 'k'){
                    if (map[i+2] == 'k'){
                        printf("%c%c%c", sentence[i], sentence[i +1], sentence[i+2]);
                        i = i + 2; break;
                    }
                    if (sentence[i] == 'n' || sentence[i] == 'N'){
                        if (sentence[i + 1] == 'g' || sentence[i+1] == 'G' || sentence[i + 1] == 'y' || sentence[i+1] == 'Y'){
                            printf("%c%c", sentence[i], sentence[i+1]);
                            i = i+1; break;
                        }
                        else {
                            printf("%c-", sentence[i]); break;
                        }
                    }
                    else {
                        if (sentence[i] != sentence[i + 1]) { //e.g gangguan, kampung
                            printf("%c", sentence[i]);
                        }
                       
                    }
                }
                else{ //lanjutan [i+1] kalo bukan konsonan
                    if (map[i + 1] == 0 || map[i + 1] == 32) {
                            printf("%c", sentence[i]);
                        }
                    else {
                        
                    
                        if (map[i-2] == 'v' && map[i-1] == 'v' && (map[i+2] == 32 || map[i+2] == 0)){
                            printf("-%c", sentence[i]); //e.g teori
                        }
                        else{
    //                        if(sentence[i] == 'n' && map[i+1] == 'v'){
    //                            printf("%c-", sentence[i]);
    //                        }
     //                       else{
                                printf("%c", sentence[i]);
                            }
       //                 }
                    }
                }
                break;
            default:
                printf(" ");
                break;
        }
    }
        printf("\n");
    
    return 0;
}
