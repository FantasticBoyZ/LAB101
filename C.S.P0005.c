#include<stdio.h>
/*
 Purpose: Ham check so duoc nhap vao tu ban phim
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
 */
int check_input_number()
{
	int num,check;
	// Bien num la so nhap vao tu ban phim, bien check de kiem tra cac ki tu nhap vao
	char ch;
	// Bien ch de kiem tra phim enter
	do{
		fflush(stdin);
		// Xoa bo nho dem
		printf("Please enter a number from (1-9):");
		// in ra dong lenh yeu cau nguoi dung nhap so tu 1 den 9
		check = scanf("%d%c",&num, &ch);
		// Bien check duoc gan cho 1 bien so va 1 bien cho ki tu enter
		if(check == 2 && ch =='\n'){
			// Neu cac phan tu nhap vao bao gom 1 so 1 ki tu va ki tu do la phim enter thi thuc hien if
			if(num > 0 && num <10)
			{
				break;
				// Neu so nhap vao lon hon 0 va nho hon 10 thi se break vong lap
			}
			else
			{
				printf("Out of range from 1 to 9!!!\n");
				// Neu nguoi dung nhap ngoai vung so cho phep thi thong bao ngoai vung va yeu cau nhap lai
			}
		}
		else{
			printf("Invalid input!!! \n");
			// Neu cac thanh phan duoc nhap tu ban phim khong phai 1 so va 1 ki tu thi in ra invalid va yeu cau nhap lai
		}
	}while(1);
	// Vong lap luon luon chay cho den khi nguoi dung nhap dung so trong khoang cho phep thi thoi
	return num;
	// Tra ve gia tri so nhap vao
}
/*
 Purpose: Ham bieu dien ra bang cuu chuong cua so nhap vao
 Author : Vu Tien Khoi HE141137
 Date   : 24/2/2020
*/
void multiplication_table(int num)
{// Bien num se duoc lay gia tri tu so nhap vao ban phim o ham tren
	int i;
	// bien i la bien chay
	printf("Multiplication table for %d number\n",num);
	for(i = 1; i<=10; i++)
	{
		printf("%d x %d = %d\n",num,i,num*i);
		// vong lap in ra bang cuu chuong
	}
}
/*
 Purpose: Ham hoi nguoi dung co muon tiep tuc hoac dung lai
 Author : Vu Tien Khoi HE141137
 Date   : 24/2/2020
*/
int checkYN()
{
	int check;
	// bien check dung de kiem tra cac ki tu nhap vao
	char temp,enter;
	// bien temp la ki tu nhap vao, bien enter dung de kiem tra phim enter
	do{
		fflush(stdin);
		// xoa bo nho dem trong vong lap
		printf("---------------------------------------\nDo you want to continue or not(y/n):");
		check = scanf("%c%c",&temp,&enter);
		// gan check cho cau lenh nhap 1 ki tu va 1 phim enter
		if(check == 2 && enter == '\n'){
			// Neu nguoi dung chi nhap 1 ki tu va 1 phim enter thi se thuc hien cac cau lenh ben duoi
			if(temp == 'y' || temp == 'Y'){
				//Neu ki tu duoc nhap vao la y hoac Y thi se tra ve gia tri 1 phuc vu cho vong lap trong main
				return 1;
			}
			else if(temp == 'n' || temp == 'N'){
				// Neu ki tu la n hoac N thi se tra ve 0 phuc vu cho vong lap trong main
				return 0;
			}
			else{
				printf("Only input(y/n)!!!\n");
				// Neu ki tu nhap vao khong phai y hoac n thi yeu cau nhap lai
			}
		}
		else{
			printf("Only input(y/n)!!!\n");
			// Neu nguoi dung nhap qua 2 ki tu tinh ca phim enter thi se yeu cau nhap lai
		}
		
	}while(1);
	// Vong lap se luon luon chay den khi no return 1 hoac 0
}


int main ()
{
	do{
		int num;
		// Bien num de nhan gia tri tra ve ham check_input_number()
		num = check_input_number();
		multiplication_table(num);
	}while(checkYN() == 1);
}
