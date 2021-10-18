#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool estConvexe(bool tab[],int length){
    int nbChange = 0;
    
    for(int i=0; i<length-1;i++){
        if (tab[i] != tab[i+1]){
            nbChange ++;
        }
    }
    if (nbChange==0 || nbChange == 1){
        return true;
    }
    if(nbChange==2){
        if (tab[0]== tab[length-1]){
            return true;
        }
    }
    return false;
}
int main(){
    printf("%s", "Doit return True:");
    bool T1[5]={false,true,true,false,false};
    printf("%d \n", estConvexe(T1,5));

    printf("%s", "Doit return True:");
    bool T2[5]={true,true,false,false,true}; 
    printf("%d \n", estConvexe(T2,5));

    printf("%s", "Doit return False:");
    bool T3[5]={true,true,false,true,false}; 
    printf("%d \n", estConvexe(T3,5));

    return 0;
}