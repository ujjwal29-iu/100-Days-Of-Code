#include <stdio.h>

int main() {
    float costPrice, sellingPrice, profit, loss, percent;   

    printf("Enter Cost Price and Selling Price: ");    
    scanf("%f %f", &costPrice, &sellingPrice);             

    
    if (sellingPrice > costPrice) {
        profit = sellingPrice - costPrice;                 
        percent = (profit / costPrice) * 100;            
        printf("Profit %.0f%%", percent);                 
    }
    else if (costPrice > sellingPrice) {
        loss = costPrice - sellingPrice;                   
        percent = (loss / costPrice) * 100;             
        printf("Loss %.0f%%", percent);                   
    }
    else {
        printf("No Profit No Loss");                     
    }

    return 0;                                           
}