#include<stdio.h>
#include <stdlib.h>
/*
 Purpose: Ham kiem tra nam nhuan
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int checkLeapYear(int n){
		if(n%400 == 0||n%4 == 0 && n%100 != 0)
		// Neu so nam do chia het cho 400 hoac chia het cho 4 nhung khong chia het cho 100 thi se return 1 la nam nhuan
		return 1;
	else
		return 0;
}
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
 Purpose: Ham xu ly cac du lieu ngay thang nam duoc nhap vao
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int processDateData(int day, int month, int year){
	printf("Enter day (1-31):");
	day = inputCheck(1,31);
	// Kiem tra khoang nhap ngay tu 1-31
	printf("Enter month (1-12):");
	month = inputCheck(1,12);
	// Kiem tra khoang nhap thang tu 1-12
	printf("Enter year (0001-9999):");
	year = inputCheck(0001,9999);
	// Kiem tra khoang nhap tu 1 - 9999
	if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
		// Cac thang co 31 ngay neu nguoi dung nhap dung thi se in ra ngay thang nam sai in ngay thang nam do khong hop le
		if(day<=31)
			printf("-----%d/%d/%d-----\n",day,month,year);
		else
			printf("---Your day,month,year is invalid---\n");
}
	else if(month==2){
		if(checkLeapYear(year)){
			// nam nhuan thi thang 2 se co 29 ngay neu nguoi dung nhap dung thi se in ra ngay thang nam sai in ngay thang nam do khong hop le
			if(day<=29)
				printf("-----%d/%d/%d-----\n",day,month,year);
			else
				printf("---Your day,month,year is invalid---\n");
			}
		else{
			// nam khong nhuan thi thang 2 chi co 28 ngay
			if(day<=28)
				printf("-----%d/%d/%d-----\n",day,month,year);
			else
				printf("---Your day,month,year is invalid---\n");
		}
	}
	else{
		if(day<=30)
		// Nhung thang con lai se la 30 ngay 
			printf("-----%d/%d/%d-----\n",day,month,year);
		else
			printf("---Your day,month,year is invalid---\n");
	}
}
/*
 Purpose: Ham in ra list cac ki tu giua 2 ki tu nhap vao theo chieu giam dan
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void characterData(char a,char b){
	int i;
	if(a<b)
	// Neu ki tu a nho hon b thi in cac ki tu tu b ve a
		for(i=b;i>=a;i--)
			printf("\t%c : %d\n",i,i);
		
	else
	// Neu ki tu b nho hon a thi in cac ki tu tu a ve b
		for(i=a;i>=b;i--)
			printf("\t%c : %d\n",i,i);
	
}
/*
 Purpose: Ham nhap vao 2 ki tu 
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void checkCharInput(char *a, char *b){
	// Bien con tro a,b de luu gia tri a,b su dung cho cac ham khac
	int check;
	// Bien check de kiem tra cac ki tu nhap vao
	char ch;
	// Bien ch de kiem tra phim enter 
	do{
		fflush(stdin);
		// xoa bo nho dem
		printf("Enter 2 characters: ");
		check = scanf("%c%c%c",*(&a),*(&b),&ch);
		// check se duoc gan vao len nhap 2 ki tu va 1 phim enter
		if (check == 3 && ch == '\n'){
			// Neu nguoi dung nhap vao 3 ki tu trong do ki tu cuoi la enter thi break va tra ve a,b da nhap vao
			break;
		}else{
			// Neu nhap sai thi yeu cau nhap lai
			printf("Invalid input!!! Please enter 2 characters: ");
		}
	}while(1);
}
/*
 Purpose: Ham bieu thi menu cho nguoi dung chon 
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void display(){
	printf("1- Processing date data\n");
	printf("2- Character data\n");
	printf("3- Quit\n");
	printf("Enter your choice: ");	
}
/*
 Purpose: Ham menu thuc hien cac chuc nang cua chuong trinh
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void menu(){
	int choice;
	// Bien choice se duoc gan voi gia tri nguoi dung lua chon
	int d,m,y;
	// Bien ngay thang nam
	char a,b;
	// 2 bien a,b la 2 ki tu duoc nhap vao
	int loop =1;
	// Bien loop de thuc hien vong lap chay lien tuc
	do{
		fflush(stdin);
		// xoa bo nho dem
		display();
		// bieu thi menu
		choice = inputCheck(1,3);
		// nhap lua chon tu ban phim
		switch (choice){
			// thuc hien cac chuc nang ma nguoi dung chon
			case 1:
				// Xu ly du lieu ngay thang nam duoc nhap vao
				processDateData(d,m,y);
				break;
			case 2:
				// In ra cac ki tu trong khoang 2 ki tu nhap vao theo chieu giam dan
				checkCharInput(&a,&b);	
				characterData(a,b);
				break;
			case 3:
				exit(1);
				// Neu nguoi dung chon exit thi se thoat khoi chuong trinh bang lenh exit(1)
				break;
		}
	}while(loop);
}
void main(){
	printf("MENU\n--------------------------------------------------\n");
	menu();

}

