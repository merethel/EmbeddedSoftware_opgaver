#pragma once

/*      void multiSwap(int x, int y, int z) should take three integer-parameters x, y and z. 
        After a call to multiSwap, x should be equal to the old y, y should be equal to the 
        old z and z should be equal to the old x. The return type of multiSwap should be void. 
        */
void multiSwap(int* x, int* y, int* z){
    int temp;
    temp = *x; //temp bliver det som x pejer på (som er værdien på adressen)

    *x = *y; //x vil du peje på den værdi y pejer på (som er værdien på y's adresse)
    *y = *z; //y vil du peje på den værdi z pejer på (som er værdien på z's adresse)
    *z = temp; //z vil du peje på den værdi som er gemt på temp (som er værdien der først var på x's adresse)
}