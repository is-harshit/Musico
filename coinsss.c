// // #include<stdio.h>


// // int len(int arr[])
// // {
// //     int i=0;
// //     while(arr[i]!=NULL)
// //     i++;
// //     return i;
// // }

// // int append(int val[],int arr[])
// // {
// //     int n=len(arr);
// //     arr[n]=val;
// // }
// // int calc(int ele,int arr[])
// // {
// //     if(ele==0)
// //     {
// //         int emp1[1]={};
// //         int emp2[0];
// //         emp1[0]=emp2;
// //     return(emp1);
// //     }
// //     int l[20];
// //     for(int i=0;i<len(arr);i++)
// //     {
// //         if(ele>=arr[i])
// //         {
// //             int comb[]=calc(ele-arr[i],arr);
// //             for(int j=0;j<len(comb);j++)
// //             {
// //                 int ele_RR[2]={ele,comb[j]};
// //                 // int app[1]=
// //                 append(ele_RR,l);
// //             }
// //         }
// //     }
// //     return l; 
// // }
// // int main()
// // {
// //     int a[3]={1,2,3};
// //     int ele=5;
// //     printf("%d",calc(ele,a));
// //     return 1;
// // }


// #include<stdio.h>

// int len(int arr[]) {
//     int i = 0;
//     while (arr[i] != 0)
//         i++;
//     return i;
// }

// void copyArray(int source[], int destination[], int length) {
//     for (int i = 0; i < length; i++) {
//         destination[i] = source[i];
//     }
// }

// void append(int val, int arr[]) {
//     int n = len(arr);
//     arr[n] = val;
//     arr[n + 1] = 0; // Set the next element to 0 to mark the end of the array
// }

// void calc(int ele, int arr[], int l[], int *resultCount) {
//     if (ele == 0) {
//         // Create an empty combination and append it to the result array
//         int emp1[1] = {0};
//         append(0, emp1);
//         append(emp1, l);
//         (*resultCount)++;
//         return;
//     }

//     for (int i = 0; i < len(arr); i++) {
//         if (ele >= arr[i]) {
//             int comb[20]; // Create an array to store the combination
//             copyArray(l, comb, 20); // Copy the existing combination into comb
//             calc(ele - arr[i], arr, comb, resultCount); // Recursive call
//             for (int j = 0; j < *resultCount; j++) {
//                 int ele_RR[20];
//                 copyArray(comb, ele_RR, 20); // Copy the combination into ele_RR
//                 ele_RR[j] = arr[i]; // Add the current coin to the combination
//                 append(0, ele_RR); // Add a 0 at the end to mark the end of the combination
//                 append(ele_RR, l); // Append the combination to the result array
//             }
//         }
//     }
// }

// int main() {
//     int a[4] = {1, 2, 3, 0}; // Added a 0 at the end to mark the end of the array
//     int ele = 5;
//     int l[100][20]; // Increased the size of the result array and inner arrays
//     int resultCount = 0;
    
//     calc(ele, a, l, &resultCount);

//     printf("Combinations:\n");
//     for (int i = 0; i < resultCount; i++) {
//         printf("[");
//         for (int j = 0; l[i][j] != 0; j++) {
//             printf("%d ", l[i][j]);
//         }
//         printf("]\n");
//     }
    
//     return 0;
// }


#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int k, int total_amount) {
    if (total_amount == 0)
        return 0;

    int result = INT_MAX;

    for (int i = 0; i < k; i++) {
        if (coins[i] <= total_amount) {
            int subResult = minCoins(coins, k, total_amount - coins[i]);
            if (subResult != INT_MAX && subResult + 1 < result)
                result = subResult + 1;
        }
    }

    return result;
}

int main() {
    int k;
    scanf("%d", &k);

    if (k == 0) {
        printf("-1\n");
        return 0;
    }

    int coins[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &coins[i]);
    }

    int total_amount;
    scanf("%d", &total_amount);

    int result = minCoins(coins, k, total_amount);

    if (result == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
