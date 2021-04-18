#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*
 Purpose: Ham kiem tra gia tri nhap vao tu ban phim
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int inputCheck(int min,int max){
	// Bien min la gia tri nho nhat cho phep nhap vao, bien max la gia tri lon nhat cho phep nhap vao
	int check,n;
	// Bien check duoc gan voi lenh scanf de kiem tra cac ki tu nhap vao
	char ch;
	// Bien ch de kiem tra phim enter
	do{
		fflush(stdin);
		// xoa bo nho dem
		check = scanf("%d%c",&n,&ch);
		// bien check duoc gan cho scanf de kiem tra ki tu dc nhap vao la 1 so va 1 ki tu enter
		if( ch=='\n' && check == 2){
			// neu ch la phim enter va nguoi dung nhap vao 1 so va 1 ki tu thi se chay cau lenh trong if
			if(n >= min && n <= max ){
				// neu gia tri n nhap vao nam trong khoang min -> max thi break khoi vong lap
				break;
			}
			else printf("Out of range!\nPlease try again!\n");
			// Neu gia tri n nhap vao khong nam trong khoang min max thi yeu cau nguoi dung nhap lai
		}else printf("INVALID input! Please try again!\n");
		// Neu nguoi dung nhap qua 2 ki tu hoac nhap cac ki tu khac so dau tien thi se yeu cau nhap lai
	}while(1);
	// vong lap luon luon chay den khi break
	return n;
}
/*
- Purpose: Ham hien thi mang ra man hinh
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void displayArr(int *arr, int n){
	printf("\nAll you current array:");
	int i;
	for(i = 0; i < n; i++)
		printf("\t%d", arr[i]);
	printf("\n");
}
/*
- Purpose: Ham yeu cau nguoi dung nhap them phan tu vao mang
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void addElement(int *arr, int *n){
	// Bien con tro arr de truyen gia tri vao mang, bien con tro n de thay doi kich thuoc mang
	printf("Please input an integer number: ");
	*n += 1;
	// tang kich thuoc mang len 1
	arr = (int*) realloc(arr, *n*sizeof(int));
	arr[*n-1] = inputCheck(INT_MIN,INT_MAX);
	// them phan tu moi vao cuoi mang
	displayArr(arr,*n);
}
/*
- Purpose: Ham tim kiem phan tu trong mang (thuat toan tim kiem tuan tu)
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void searchElement(int *arr,int n){
	int i,x;
	// Bien chay i, bien x la so nhap vao de search
	int check = 0;
	// Bien check mac dinh se la 0
	printf("Please input an integer: ");
	x = inputCheck(INT_MIN,INT_MAX);
	for(i=0;i<n;i++){
		if(arr[i] == x ){		
		// Neu tim thay x trong mang arr thi se gan check = 1	
		check = 1;
		printf("Your value's index is: %d\n",i);
		}
	}
	if(check == 0) printf("Not Found\n");
	// Neu khong tim thay thi in ra not found
}
/*
- Purpose: Ham in ra cac gia tri nam giua khoang nhap vao
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void printRange(int *arr,int n){
	int min,max,i;
	// Bien min la gia tri nho nhat , bien max la gia tri lon nhat trong khoang can in
	int check = 0;
	printf("Please enter min value: ");
	min = inputCheck(INT_MIN,INT_MAX);
	// nhap min truoc
	printf("Please enter max value: ");
	do{
		fflush(stdin);
		max = inputCheck(INT_MIN,INT_MAX);
		// nhap max neu nhap max nho hon min thi yeu cau nhap lai
		if(min > max){
			printf("Please enter max greater than min!!! Try again: ");
		}
	}while(min > max);
	printf("All value in range %d and %d :",min,max);
	for(i=0;i<=n;i++){
		if(arr[i] >= min && arr[i]<=max){
			// neu cac phan tu trong mang nam giua khoang min max thi in ra cac phan tu va cho check = 1
			printf("\t%d", arr[i]);
			check = 1;
		}
	}
	if(check == 0) printf(" No value in range!!!");
	// Neu check = 0 tuc la khong co phan tu nao trong mang nam giua khoang nhap vao
	printf("\n");
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
void bubbleSortAsc(int *arr, int n)
{
    int i, j;
    int copy[n];
    // bien i, j la bien chay cho vong lap thuc hien cac phep so sanh va doi cho
	// bien j con la vi tri duoc so sanh va doi cho trong mang
	for(i = 0; i < n; i++)
		copy[i] = arr[i];
    for (i = 0; i < n-1; i++){    	
        for (j = 0; j < n-i-1; j++){       	
            if (copy[j] > copy[j+1]){
                swap(&copy[j], &copy[j+1]);
            }
        }
    }
    displayArr(copy,n);
}
/*
- Purpose: Ham hien thi menu
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void displayMenu(){
		printf("\n1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Print out the array \n");
		printf("4- Print out values in a range of inputted min and max values,inclusively. \n");
		printf("5- Sort the array in ascending order\n");
		printf("6- Quit\n");
		printf("Choose your option(1-6): ");
}
/*
- Purpose: Ham hien thi menu cho nguoi dung lua chon
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void Function(int *arr, int *n){
	int choice;
	// Bien choice la lua chon cua nguoi dung
	int loop =1;
	// bien loop cho vong lap
	do{
	displayMenu();
	// Bieu thi menu
	choice = inputCheck(1,6);
	// nhap lua chon
	switch(choice){
		case 1:
			addElement(arr,&(*n));
			break;
		case 2:
			searchElement(arr,*n);
			break;
		case 3:
			displayArr(arr,*n);
			break;
		case 4:
			printRange(arr,*n);
			break;
		case 5:
			bubbleSortAsc(arr,*n);
			break;
		case 6:
			printf("----------Exit Program----------");
			loop = 0;
			break;	
				
		}
	}while(loop);
}
int main(){
	int n = 0;
	int *arr = (int*)malloc(n * sizeof(int));
	Function(arr,&n);
	return 0;
}
