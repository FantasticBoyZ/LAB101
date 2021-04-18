#include<stdio.h>
#include<math.h>
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
/*Hàm in ra man hinh
- Purpose: In ra ten cua chuong trinh va yeu cau nguoi dung nhap so phan tu
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
int Display(){
	printf("Sum Even Odd Program\n");
	printf("Enter number of element n=");
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
	char c;
	// bien c de kiem tra ki tu enter nhap vao
	do{
		fflush(stdin);
		// xoa bo nho dem
		printf("\tEnter element[%d]: ", i+1);
		// In ra man hinh nhap ki tu thu i+1
		check1 = scanf("%d%c", &arr[i], &c);
		// Kiem tra gia tri nhap vao mang va ki tu enter
		if(c == '\n' && check1 == 2){
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
- Purpose: Hàm tinh tong cac so le trong mang
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void Calculate_Odd(int arr[], int number){
	// bien mang da duoc khai bao de lay gia tri tu mang da nhap vao o ben tren, bien number la so cac phan tu cua mang
	int i,sum = 0;
	// bien i lam bien chay, bien sum de tinh tong
	for(i = 0; i < number; i++){
		if(arr[i] % 2 == 1){
			sum += arr[i];
		}
		// vong lap chay de tim cac so le trong mang va tinh tong cac so do
	}
	printf("sum of Odd=%d\n",sum);
	// in ra man hinh tong cac so le
}
/*
- Purpose: Hàm tinh tong cac so chan trong mang
- Author: Vu Tien Khoi HE141137
- Date: 20/2/2020
*/
void Calculate_Even(int arr[], int number){
	// bien mang da duoc khai bao de lay gia tri tu mang da nhap vao o ben tren, bien number la so cac phan tu cua mang
	int i,sum = 0;
	// bien i lam bien chay, bien sum de tinh tong
	for(i = 0; i < number; i++){
		if(arr[i] % 2 == 0){
			sum += arr[i];
		}
		// vong lap chay de tim cac so chan trong mang va tinh cac so do
	}
	printf("sum of Event=%d\n",sum);
	// in ra man hinh tong cac so le
}

int main (){
	int number;
	// Bien number dung de gan voi ham check() de lay gia tri tra ve tu ham check
	Display();
	number = check();
	int *arr = (int *)malloc(sizeof(int) * number);
	// khai bao mang dong theo so luong phan tu nhap vao
	inputValue(arr,number);
	Calculate_Even(arr,number);
	Calculate_Odd(arr,number);
	
}
