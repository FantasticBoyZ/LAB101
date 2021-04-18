#include<stdio.h>
#include<stdlib.h>
/*Hàm check giá tri nhâp vào tu ban phim
- Purpose: Kiem tra xem nguoi dung da nhap dung yeu cau hay chua. Neu chua nhap dung yeu cau nhap lai
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
int check()
{
	int number, check;
	// Bien number la gia tri nhap vao, bien check de gan cho lenh scanf
	char ch;
	// Bien ch dung de kiem tra phim enter nhap vao ban phim
	do{
		fflush(stdin);
		// Xoa bo nho dem
		check = scanf("%d%c", &number, &ch);
		// check gia tri nhap vao la so va phim enter
		if(ch == '\n' && check == 2){
			// neu gia tri scanf nhap vao chi co so va phim enter thi se thuc hien  cac cau lenh trong if
			if(number > 0){
				// neu bien number nhap vao lon hon 0 thi break khoi vong lap
				break;
			}
			else{
				// neu gia tri nhap vao nho hon 0 thi yeu cau nhap lai
				printf("Please enter a number greater than 0!!! \n");
				continue;	
			}
		}
		else{
			// neu gia tri nhap vao khong phai chi co 2 gia tri 1 la so 2 la phim enter thi se bao khong hop le va yeu cau nhap lai
			printf("Invalid input!!! \n");
			continue;
		}
	}while(1);
	// vong lap se luon luon chay den khi bien nhap vao lon hon 0 thi break
	return number;
}
/*
- Purpose: Hàm yeu cau nguoi dung nhap cac phan tu cua mang
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void inputValue(int *arr, int number){
	// dung bien con tro de truyen gia tri vao mang, bien number la so luong phan tu cua mang da nhap vao o tren
	printf("Input elements\n");
		
	int i=0,check1;
	// bien i lam bien chay cho vong lap nhap cac gia tri vao mang, bien check1 de kiem tra gia tri nhap vao
	char ch;
	// bien c de kiem tra ki tu enter nhap vao
	do{
		fflush(stdin);
		// xoa bo nho dem
		printf("Enter element[%d]: ", i);
		// In ra man hinh nhap ki tu thu i+1
		check1 = scanf("%d%c", &arr[i], &ch);
		// Kiem tra gia tri nhap vao mang va ki tu enter
		if(ch == '\n' && check1 == 2){
			i++;
			// neu ki tu nhap vao la enter va check1 chi co 1 so va 1 ki tu nhap vao thi i tang len 1
		}
		else{
			printf("Please try again\n");
			// neu khong thi yeu cau nhap lai
		}
	}while(i<number);
	// vong lap chay den khi i lon hon hoac bang number
}
/*
- Purpose: Hàm doi vi tri 2 phan tu voi nhau
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void swap(int *x, int *y)
// Bien con tro x,y de doi cho cho nhau, bien temp lam bien trung gian
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
/*
- Purpose: Hàm sap xep cac phan tu trong mang bubblesort
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void bubbleSortAsc(int arr[], int n)
{
    int i, j;
    // bien i, j la bien chay cho vong lap thuc hien cac phep so sanh va doi cho
	// bien j con la vi tri duoc so sanh va doi cho trong mang
    for (i = 0; i < n-1; i++){    	
        for (j = 0; j < n-i-1; j++){       	
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
/*
- Purpose: Hàm sap xep cac phan tu trong mang bubblesort
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void bubbleSortDesc(int arr[], int n)
{
    int i, j;
    // bien i, j la bien chay cho vong lap thuc hien cac phep so sanh va doi cho
	// bien j con la vi tri duoc so sanh va doi cho trong mang
    for (i = 0; i < n-1; i++){    	
        for (j = 0; j < n-i-1; j++){       	
            if (arr[j] < arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
/*
- Purpose: Hàm bieu thi ket qua cua mang da duoc sap xep tang dan, giam dan
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void display(int arr[],int n, int type){
	int i;
	if(type == 1){
	printf("The array sorted in ascending:\n");
	// Ham sap xep tang dan in theo chieu xuoi
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	}
	if(type == 0){
	printf("\n\nThe array sorted in descending:\n");
	// Ham sap xep giam dan thi in theo chieu nguoc lai
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}
}
void main(){
	int n;
	// Bien n duoc khai bao de nhan gia tri nhap vao tu ham check()
	printf("Please enter size of array:");
	n = check();
	int *arr = (int *)malloc(sizeof(int) * n);
	// Khai bao mang dong
	inputValue(arr,n);
	bubbleSortAsc(arr,n);
	display(arr,n,1);
	bubbleSortDesc(arr,n);
	display(arr,n,0);
}
