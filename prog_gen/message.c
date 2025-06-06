#include <stdio.h>
#include <stdlib.h>

// INPUT : Une expression préfixe. ((a+b)+(c*d)) = ++ab*cd
//      exemple  : +#+#247#106#*#57#103
//
//  OUTPUT (247+106)+(57*103) = 6224
//  
//

// GLOBAL
char *t;
int i=0;

int eval(){
    if(t[i] == '#') i++;

    if(t[i] == '+'){
        i++;
        return eval()+eval();
    }
    if(t[i] == '*'){
        i++;
        return eval()*eval();
    }

    // ALGO DE HORNER
    int x=0;
    while(t[i]>='0' && t[i]<='9'){
        x = x*10 + (t[i++]-'0');

    }
    return x;
}

float evalFloat(){
    // en entrée on ne met pas de floattant
    if(t[i] == '#') i++;

    if(t[i] == '+'){
        i++;
        return evalFloat()+evalFloat();
    }
    if(t[i] == '*'){
        i++;
        return evalFloat()*evalFloat();
    }
    if(t[i] == '/'){
        i++;
        return evalFloat()/evalFloat();
    }
    if(t[i] == '-'){
        i++;
        return evalFloat()-evalFloat();
    }
    // ALGO DE HORNER
    float x=0.;
    while(t[i]>='0' && t[i]<='9'){
        x = x*10 + (t[i++]-'0');

    }
    return x;
}

float evalFloatAmel(){
    // en entrée on ACCEPTE les floattant
    if(t[i] == '#') i++;

    if(t[i] == '+'){
        i++;
        return evalFloatAmel()+evalFloatAmel();
    }
    if(t[i] == '*'){
        i++;
        return evalFloatAmel()*evalFloatAmel();
    }
    if(t[i] == '/'){
        i++;
        return evalFloatAmel()/evalFloatAmel();
    }
    if(t[i] == '-'){
        i++;
        return evalFloatAmel()-evalFloatAmel();
    }
    // Ma façon de gérer les nombre à virgule
    float x=0.;
    int virgule=-1;
    while(t[i]>='0' && t[i]<='9' || t[i] == ','){
        if(t[i]==','){
            virgule = 0;
            i++;
        }else{        
            x = x*10 + (t[i++]-'0');
            if(virgule!=-1){
                virgule+=1;
            }
        }
    }

    int puissance=1;
    for(int i =0; i<virgule; ++i){
        puissance = puissance *10;
    }
    
    x = x/puissance;
    
    return x;
}

// Bonus étendre le programme d'évaluation d'une expression préfixe avec les opérateur + - * / ^
float evalFloatAmel2(){
    // en entrée on ACCEPTE les floattant
    // on accepte le % et ^
    //gerer les nombre négatif
    int negatif = 1;
    if(t[i] == '#') i++;

    if(t[i] == '+'){
        i++;
        return evalFloatAmel2()+evalFloatAmel2();
    }
    
    if(t[i] == '*'){
        i++;
        return evalFloatAmel2()*evalFloatAmel2();
    }
    if(t[i] == '/'){
        i++;
        float a = evalFloatAmel2();
        float b = evalFloatAmel2();
        if(b == 0){
            printf("ERREUR divison par 0\n");
            exit(1);
        }
        return a/b;
    }
    if(t[i] == '-'){
        if(t[++i]!='#'){
            negatif=-1;
        }else{
            return evalFloatAmel2()-evalFloatAmel2();
        }
    }

    // Ma façon de gérer les nombre à virgule
    float x=0.;
    int virgule=-1;
    while(t[i]>='0' && t[i]<='9' || t[i] == ','){
        if(t[i]==','){
            virgule = 0;
            i++;
        }else{        
            x = x*10 + (t[i++]-'0');
            if(virgule!=-1){
                virgule+=1;
            }
        }
    }

    int puissance=1;
    for(int i =0; i<virgule; ++i){
        puissance = puissance *10;
    }
    
    x = x/puissance;
    x = x*negatif;

    return x;
}

int main(){
    //t="+#+#247#106#*#57#103";
    //printf("%d\n",eval());
    
    //t="/#-1,55#9";
    
    t="+#*#-25#6#*#15#10";
    
    printf("%f\n",evalFloatAmel2());

}