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
- Purpose: Ham xoa phan tu trong mang
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
int removeElement(int *arr, int *n,int delnum){
	// bien mang de truyen gia tri, bien con tro n de thay doi kich thuoc mang, bien delnum la so bi xoa khoi mang
	int i;
	// bien i la bien chay
	int search = -1;
	// cho search la -1 tuc la vi tri khong nam trong mang
	for(i=0;i<*n;i++){
		if(delnum == arr[i]){
			search = i;
			// neu nhu tim thay arr[i] = delnum thi gan search voi vi tri i
			break;
		}
			
	}
	if(search != -1){
		// Neu search khac -1 thi thuc hien xoa
		for(i = search;i<*n;i++){
			arr[i] = arr[i+1];
			// day phan tu can xoa ve cuoi mang
		}
		*n = *n -1;
		// giam kich thuoc mang di 1
		arr = (int*) realloc(arr, *n * sizeof(int));
		// thay doi kich thuoc bo nho cua mang bang realloc
	}else 
		return 0;
}
/*
- Purpose: Ham xoa phan tu dau tien trong mang
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void removeFirst(int *arr,int *n){
	// bien con tro n de thay doi kich thuoc mang, bien delnum la so bi xoa khoi mang
	int delnum;
	// Bien delnum la so bi xoa
	printf("Please enter a number you want to remove: ");
	delnum = inputCheck(INT_MIN,INT_MAX);
 	if(removeElement(arr,&(*n),delnum)){
 		// Neu tim thay delnum va xoa thanh cong thi se thong bao ra man hinh
 		printf("Remove Successfull!!!\n");
 		displayArr(arr,*n);
	}else printf("Not Found\n");
	// khong tim thay delnum thi in ra not found
}

/*
- Purpose: Ham xoa tat ca phan tu trong mang
- Author: Vu Tien Khoi HE141137
- Date: 14/03/2020
*/
void removeAll(int *arr,int *n){
	int delnum,check = 0;
	// Bien delnum la so bi xoa
	printf("Please enter a number you want to remove: ");
	delnum = inputCheck(INT_MIN,INT_MAX);
	int i;
	for(i=0;i<*n;i++){
	// chay vong lap de xoa het cac gia tri = delnum
		if(removeElement(arr,&(*n),delnum)){
		// Neu tim thay va xoa delnum thi gan check = 1
		check = 1;
		// giam i de xoa nhung so giong nhau dung canh nhau
		i--;
		}
	}
	if(check == 1){
		// neu check = 1 in ra xoa thanh cong
		printf("Remove Successfull!!!\n");
		displayArr(arr,*n);
	}else{
		// Neu check van bang 0 thi in ra not found
		printf("Not Found\n");
	}
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
- Purpose: Hàm sap xep cac phan tu trong mang bubblesort
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void bubbleSortDesc(int *arr, int n)
{
    int i, j;
    int copy[n];
    // bien i, j la bien chay cho vong lap thuc hien cac phep so sanh va doi cho
	// bien j con la vi tri duoc so sanh va doi cho trong mang
	for(i = 0; i < n; i++)
		copy[i] = arr[i];
    for (i = 0; i < n-1; i++){    	
        for (j = 0; j < n-i-1; j++){       	
            if (copy[j] < copy[j+1]){
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
		printf("3- Remove the first existence of a value\n");
		printf("4- Remove all existences of a value\n");
		printf("5- Print out the array \n");
		printf("6- Sort the array in ascending order\n");
		printf("7- Sort the array in descending order\n");
		printf("8 - Quit\n");
		printf("Choose your option(1-8): ");
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
	choice = inputCheck(1,8);
	// nhap lua chon
	switch(choice){
		case 1:
			addElement(arr,&(*n));
			break;
		case 2:
			searchElement(arr,*n);
			break;
		case 3:
			removeFirst(arr,&(*n));
			break;
		case 4:
			removeAll(arr,&(*n));
			break;
		case 5:
			displayArr(arr,*n);
			break;
		case 6:
			bubbleSortAsc(arr,*n);
			break;
		case 7:
			bubbleSortDesc(arr,*n);
			break;
		case 8:
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

