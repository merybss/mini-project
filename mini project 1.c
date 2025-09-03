#include <stdio.h>
#include <stdlib.h>



int main()
{
    float note1,note2,note3,note4,note5,la_somme,M;
    float max,min;
    char mention;
    printf("saisie les 5 notes: \n");
    scanf("%f %f %f %f %f",&note1,&note2,&note3,&note4,&note5);
    la_somme=note1+note2+note3+note4+note5;
    printf("la somme des notes est:%2.f \n",la_somme);
    //moyenne des notes
    M=la_somme/5;
    printf("la moyenne des notes est:%2.f \n",M);
    
   max=note1;
    if(note2>max)
    max=note2;

     if(note3>max)
     max=note3;

    if(note4>max)
     max=note4;

    if(note5>max)
    max=note5;

       printf("Note la plus haute : %.2f \n", max);

     min=note1;
    if(note2<min)
    min=note2;

     if(note3<min)
     min=note3;

    if(note4<min)
     max=note4;

    if(note5<min)
    min=note5;s

       printf("Note la plus basse : %.2f \n", min);
    if (M >= 90) {
        printf("Mention : A alors Excellent \n");}
     else if(M >= 80 ) {
        printf("Mention: B alors Très bien \n");}
    else if (M >= 70 ) {
        printf("Mention: C alors  Bien \n");}
     else if (M >= 60 ) {
        printf("Mention:D alors passable \n");}
     else  {
        printf("Mention:echec \n");}

    return 0;
}
