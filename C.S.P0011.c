#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Purpose: Ham bieu thi menu lua chon cho nguoi dung
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
void display(){
	printf("1. Convert binary number to decimal number\n");
	printf("2. Convert octal number to decimal number\n");
	printf("3. Convert hexadecimal number to decimal number\n");
	printf("4. Exit\n");
	printf("Please choose number (1 to 4):");
}
/*
 Purpose: Ham check yes/no hoi nguoi dung muon tiep tuc hay thoat chuong trinh
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
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
		printf("\n---------------------------------------\nDo you want to continue or not(y/n):");
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
/*
 Purpose: Ham bieu thi menu ra man hinh va thuc hien cac ham chuyen doi co so
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
void menu(){
	int a;
	// Bien a de nhan gia tri tu ham checkInput(lua chon cua nguoi dung)
	char n[32];
	// mang n cho 32 ki tu de nhap cac so vao de chuyen doi
	int loop = 1;
	// bien loop de thuc hien vong lap
	while(loop){
		// khi loop la 1 thi vong lap se luon luon chay 
		display();
		// Ham bieu thi menu ben tren
		a = checkInput();
		// lua chon cua nguoi dung dc gan vao bien a
		switch (a){	
			// TH1 nguoi dung chon chuyen tu co so 2 sang co so 10
			case 1 : 
			printf("Enter binary number: ");
			while(binCheck(n) == 0){
				// Neu binCheck tra ve gia tri 0 thi yeu cau nguoi dung nhap lai
				printf("Wrong input! Please enter correct binary form:");
			}
			printf("Decimal number is: %d",bintoDec(n));
			break;
			// TH2 nguoi dung chon chuyen tu co so 8 sang co so 10
			case 2 : 
			printf("Enter octal number: ");
			while(octalCheck(n) == 0){
				printf("Wrong input! Please enter correct octal form:");
			}
			printf("Decimal number is: %d",octaltoDec(n));
			break;
			// TH3 nguoi dung chon chuyen tu co so 16 sang co so 10
			case 3 : 
			printf("Enter hexadecimal number: ");
			while(hexCheck(n) == 0){
				printf("Wrong input! Please enter correct hexadecimal form:");
			}
			printf("Decimal number is: %d",hextoDec(n));
			break;
			// TH4 nguoi dung chon thoat chuong trinh
			case 4 : 
			exit(1);
			// cau lenh exit de thoat khoi chuong trinh				
			break; 
			}
		if(checkYN() == 0) loop = 0;
		// Neu nguoi dung nhap n hoac N thi se thoat khoi chuong trinh con neu nhap la y hoac Y thi se tiep tuc vong lap
	}
}
/*
 Purpose: Ham kiem tra gia tri nhap vao khi nguoi dung lua chon cac chuc nang cua chuong trinh
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int checkInput(){
	int choice,check;
	// bien choice la lua chon duoc nhap, bien check de kiem tra nguoi dung nhap vao 1 so va 1 ki tu
	char ch;
	// bien ch de kiem tra phim enter
	do{
		fflush(stdin);
		// xoa bo nho dem
		check = scanf("%d%c",&choice,&ch);
		if(check == 2 && ch=='\n'){
			// neu nguoi dung nhap 1 so va 1 ki tu enter thi thuc hien cac cau lenh trong if
			if(choice>=1 && choice<=4){
				// neu nguoi dung nhap choice trong khoang 1 - 4 thi tra ve gia tri choice
				break;
			}
			else {
				// neu nhap ngoai khoang 1 - 4 thi yeu cau nhap lai
				printf("out of range 1 to 4! Try again:");
			}
		}
			else{
				// neu nguoi dung nhap chu hoac nhieu ki tu khac thi yeu cau nhap lai
				printf("Invalid input!!!Try again:");
			}
		}while(1);
	return choice;
}
/*
 Purpose: Ham kiem tra so binary
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int binCheck(char n[]){
	gets(n);
	// nhap mang n co chua dau cach
	int i;
	// bien chay i
	// vong lap kiem tra tung phan tu trong mang n neu chi co ki tu 0 va 1 thi return 1 con co cac ki tu khac return 0
	for( i = 0; i < strlen(n); i++){
		if(n[i] == 48 || n[i] == 49){
		continue;
		}
		else return 0;
	}
	return 1;
}
/*
 Purpose: Ham kiem tra so octal(he co so 8)
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int octalCheck(char n[]){
	gets(n);
	// nhap mang n co chua dau cach
	int i;
	// bien chay i
	// vong lap kiem tra tung phan tu trong mang n neu chi co ki tu tu 0 den 7 thi return 1 con co cac ki tu khac return 0
	for( i = 0; i < strlen(n); i++){
		if(n[i] >= 48 && n[i] <= 55){
		continue;
		} else return 0;
	}
	return 1;
}
/*
 Purpose: Ham kiem tra so hexadecimal(he co so 16)
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int hexCheck(char n[]){
	gets(n);
	// nhap mang n co chua dau cach
	int i;
	// bien chay i
	// vong lap kiem tra tung phan tu trong mang n
	// neu chi co ki tu tu 0 den 9 va cac chu cai a,b,c,d,f,A,B,C,D,E,F thi return 1 con co cac ki tu khac return 0
	for( i = 0; i < strlen(n); i++){
		if(n[i] >= 48 && n[i] <= 57) {
		continue;
		}else if (n[i] >= 65 && n[i] <= 70) continue;
		else if (n[i] >= 97 && n[i] <= 102) continue;
		else return 0;
	}
	return 1;
}
/*
 Purpose: Ham chuyen doi he co so 2 sang he co so 10
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int bintoDec(char n[]){
	int sum =0;
	// Bien sum se la so thap phan duoc tra ve
	int index;
	// Bien index la gia tri cua phan tu thu i trong mang n
	int i=0,j=0;
	// Bien i lam bien chay nguoc tu cuoi chuoi ki tu , Bien j la cac vi tri trong so nhi phan do
	for(i=strlen(n) - 1;i>=0 ;i--){
		index = n[i] - 48;
		// n[i] o day la kieu ki tu nen phai tru di 48 de ra gia tri 1 va 0 o he co so 10
		sum = sum + index*pow(2,j);
		// so he co so 10 dc chuyen doi se duoc cong dan vao 
		j++;
	}
	// vd 1011(2) --> 1*(2^0) + 1*(2^1) + 0*(2^2) + 1*(2^3) = 11(10)
	return sum;
}
/*
 Purpose: Ham chuyen doi he co so 8 sang he co so 10
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int octaltoDec(char n[]){
	int sum =0;
	// Bien sum se la so thap phan duoc tra ve
	int index;
	// Bien index la gia tri cua phan tu thu i trong mang n
	int i=0,j=0;
	// Bien i lam bien chay nguoc tu cuoi chuoi ki tu , Bien j la cac vi tri trong so bat phan do
	for(i=strlen(n) - 1;i>=0 ;i--){
		index = n[i] - 48;
		// chuyen cac ki tu 0 --> 7 (48-->55) ve gia tri decimal
		sum = sum + index*pow(8,j);
		j++;
	}
	// vd 321(8) --> 1*(8^0) + 2*(8^1) + 3*(8^2) = 209(10)
	return sum;
}
/*
 Purpose: Ham chuyen doi he co so 16 sang he co so 10
 Author :Vu Tien Khoi HE141137
 Date   :24/2/2020
*/
int hextoDec(char n[]){
	int sum =0;
	// Bien sum se la so thap phan duoc tra ve
	int index;
	// Bien index la gia tri cua phan tu thu i trong mang n
	int i=0,j=0;
	// Bien i lam bien chay nguoc tu cuoi chuoi ki tu , Bien j la cac vi tri trong so thap luc phan do
	for(i=strlen(n) - 1;i>=0 ;i--){
		if(n[i] >= 48 && n[i]<= 57){
		index = n[i] - 48;
		}// chuyen cac so 0 - 9 tu ki tu thanh gia tri decimal
		else if(n[i] >= 65 && n[i]<= 70){
		index = n[i] - 55;
		}// chuyen A,B,C,D,E,F - > 10,11,12,13,14
		else if(n[i] >= 97 && n[i]<= 102){
		index = n[i] - 87;
		}// chuyen a,b,c,d,e,f - > 10,11,12,13,14
		sum = sum + index*pow(16,j);
		j++;
	}// vd cafe(16) = 14*(16^0) + 15*(16^1) +10*(16^2) + 12*(16^3) = 51966(10)
	return sum;
}
int main(){
	menu();
}
