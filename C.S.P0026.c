#include<stdio.h>
#include<math.h>
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
 Purpose: Ham chuyen doi cac so co so 10 sang co so 2
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int decToBin(int num){
	// Bien n la so duoc chuyen doi
	int i=0,index;
	// Bien i la so mu cho ham luy thua, bien index la phan 0 va 1 duoc tra ve khi chia du n cho 2
	int bin=0;
	// Bien bin se la so binary duoc chuyen doi ra va la tong cua cac gia tri tai cac vi tri 
	// VD :so 20 20%2=0(vtri 0) -> 20/2=10 -> 10%2=0(vtri 1) ->10/2=5->5%2=1(vtri 2) ->5/2=2->2%2=0(vtri3)-> 2/2=1->1%2=1(vtri 4)
	// --> 0*10^0+ 0*10^1 + 1*10^2 + 0*10^3 +1*10^4=10100(2)
	while(num>0){
		// vong lap se chay den khi n<=0
		index = num%2;
		num=num/2;
		bin = bin + index*pow(10,i);
		i++;
	}
	printf("%d",bin);
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
 Purpose: Ham bieu thi ten chuong trinh va huong dan nguoi dung nhap so can convert
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void display(){
	int n;
	// Bien n se duoc nhan gia tri tu ham inputCheck
	printf("--Convert Decimal to Binary Program--\n");
	printf("\tEnter a positive number:");
	n = inputCheck(0,INT_MAX);
	printf("\tBinary number:");
	decToBin(n);
	
}
int main(){
	do{
		display();
	}while(checkYN()==1);
	// Vong lap voi ham checkYN se cho nguoi dung lua chon tiep tuc hay dung lai
}
